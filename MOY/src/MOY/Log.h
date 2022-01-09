#pragma once

#include "core.h"
#include "spdlog/spdlog.h"

namespace MOY {
	class MOY_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetCientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define MOY_CORE_TRACE(...)		MOY::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define MOY_CORE_INFO(...)		MOY::Log::GetCoreLogger()->info(__VA_ARGS__);
#define MOY_CORE_WARN(...)		MOY::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define MOY_CORE_ERROR(...)		MOY::Log::GetCoreLogger()->error(__VA_ARGS__);
#define MOY_Client_TRACE(...)	MOY::Log::GetClientLogger()->trace(__VA_ARGS__);
#define MOY_Client_INFO(...)	MOY::Log::GetClientLogger()->info(__VA_ARGS__);
#define MOY_Client_WARN(...)	MOY::Log::GetClientLogger()->warn(__VA_ARGS__);
#define MOY_Client_ERROR(...)	MOY::Log::GetClientLogger()->error(__VA_ARGS__);

