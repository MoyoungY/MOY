#pragma once
#include "core.h"
#include "Window.h"

namespace MOY{
	class MOY_API Application
	{
	private:
		std::unique_ptr<Window> m_window;
		bool m_running = true;

	public:
		#define MOY_BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

		Application();
		virtual ~Application();

		virtual void OnEvent(Event& e);

		virtual bool OnWindowClose(Event& e);

		void run();
	};

	// to be defined in client
	Application* createNewApplication();
}
