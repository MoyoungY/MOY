workspace "MOY"
	configurations {"Debug", "Release", "Dist"}
	architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MOY"
	location "MOY"
	kind "SharedLib"
	language "C++"
	files{"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
	includedirs{"%{prj.name}/ext/spdlog/include", "%{prj.name}/src"}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}" )
	
	pchheader "moypch.h"
	pchsource "MOY/src/moypch.cpp"

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MOY_PLATFORM_WINDOWS",
			"MOY_DLL_BUILD"
		}
		
		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir.. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MOY_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "MOY_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "MOY_Dist"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	files{"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
	includedirs{"MOY/ext/spdlog/include", "MOY/src/"}

	links{ "MOY" }

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}" )
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MOY_PLATFORM_WINDOWS",
			"MOY_APP_BUILD"
		}
	

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "HZ_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_Dist"
		optimize "On"