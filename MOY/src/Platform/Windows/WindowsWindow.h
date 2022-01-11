#pragma once
#include "MOY/Window.h"
#include "GLFW/glfw3.h"


namespace MOY
{
	class WindowsWindow :public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline uint32_t GetWidth() const override { return m_windowdata.Width; }
		inline uint32_t GetHeight() const override { return m_windowdata.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_windowdata.EventCallback = callback; }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_window;

		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			bool vSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_windowdata;
	};

}