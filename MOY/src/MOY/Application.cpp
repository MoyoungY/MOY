#include "moypch.h"
#include "Application.h"
#include "Platform/Windows/WindowsWindow.h"

namespace MOY {
	Application::Application(){}
	Application::~Application() {}

	void Application::run() {
		Window* window = Window::Create();
		while (true) {
			window->OnUpdate();
		}
	}
}