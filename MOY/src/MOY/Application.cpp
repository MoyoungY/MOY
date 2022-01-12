#include "moypch.h"
#include "Application.h"
#include "Platform/Windows/WindowsWindow.h"
#include "Event/ApplicationEvent.h"
#include "Log.h"
#include "MOY/Event/ApplicationEvent.h"

namespace MOY 
{
	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::Create());
		m_window->SetEventCallback(MOY_BIND_EVENT_FN(OnEvent));
	}
	Application::~Application() {}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispather(e);
		dispather.Dispatch<WindowCloseEvent>(MOY_BIND_EVENT_FN(OnWindowClose));
	}

	bool Application::OnWindowClose(Event& e)
	{
		MOY_CORE_INFO("ONWindowClose!");
		m_running = false;
		return true;
	}

	void Application::run() {
		while (m_running) {
			m_window->OnUpdate();
		}
	}
}