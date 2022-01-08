#pragma once
#include "core.h"

namespace MOY{
	class MOY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// to be difined in client
	Application* createNewApplication();
}
