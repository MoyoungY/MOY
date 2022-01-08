#include "MOY.h"
#include<iostream>

class SandBox : public MOY::Application {
};

MOY::Application* MOY::createNewApplication() {
	return new SandBox;
}

void test() {
	std::cout << "test" << std::endl;
}