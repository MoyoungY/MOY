#pragma once
#include <iostream>
MOY::Application* MOY::createNewApplication();

int main() {
	std::cout << "1" << std::endl;
	MOY::Application* app = MOY::createNewApplication();
	app->run();
	delete app;
}
