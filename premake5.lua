workspace "Cartographer"
	configurations { "Debug", "Release" }

project "Cartographer"
	kind "StaticLib"
	language "C++"
	targetdir "build/%{cfg.buildcfg}"
	objdir ("build/obj")
	cppdialect "C++20"

	files { "src/**.hpp", "src/**.cpp" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEGUG" }
		optimize "On"
