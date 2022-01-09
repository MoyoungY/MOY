#pragma once

MOY::Application* MOY::createNewApplication();

int main() {
	MOY::Log::Init();
	MOY_CORE_ERROR("error!")


	MOY::Application* app = MOY::createNewApplication();
	app->run();
	delete app;
}
