#include "moypch.h"
#include "MOY/Window.h"
#include "WindowsWindow.h"
#include "MOY/Log.h"
#include "MOY/Event/ApplicationEvent.h"

namespace MOY 
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{

	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_windowdata.Title = props.Title;
		m_windowdata.Width = props.Width;
		m_windowdata.Height = props.Height;

		MOY_CORE_INFO("Creating window {0} {1} {2}", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			if (!success) MOY_CORE_ERROR("glfw init error");
			s_GLFWInitialized = true;
		}

		m_window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		if (!m_window)
		{
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_windowdata);
		SetVSync(true);

		// set callback
		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData *)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		m_windowdata.vSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_windowdata.vSync;
	}

}