#pragma once

#ifdef MOY_PLATFORM_WINDOWS
	#ifdef MOY_DLL_BUILD
		#define MOY_API __declspec(dllexport)
	#else
		#define MOY_API __declspec(dllimport)
	#endif // MOY_DLL_BUILD
#else
	#error "ONLY SUPPORT WINDOWS NOW!
#endif // MOY_PLATFORM_WINDOWS

