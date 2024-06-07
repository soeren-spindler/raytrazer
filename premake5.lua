local BUILD_DIR = path.join("build", _ACTION)
if _OPTIONS["cc"] ~= nil then
	BUILD_DIR = BUILD_DIR .. "_" .. _OPTIONS["cc"]
end

local GLFW_DIR = "dependencies/glfw"
local GLAD_DIR = "dependencies/glad"
local GLM_DIR = "dependencies/glm"
local IMGUI_DIR = "dependencies/imgui"

workspace "Raytrazer"
	location(BUILD_DIR)
	configurations { "Debug", "Release" }
	startproject "Raytrazer.Editor"

	flags { "MultiProcessorCompile" }
	
	if os.is64bit() and not os.istarget("windows") then
		platforms "x86_64"
	else
		platforms { "x86", "x86_64" }
	end

	filter "configurations:Debug"
    	defines "DEBUG"
		optimize "Debug"
    	symbols "On"

 	filter "configurations:Release"
    	defines "RELEASE"
    	optimize "Full"
    	flags { "LinkTimeOptimization" }
		
	filter "platforms:x86"
		architecture "x86"
	filter "platforms:x86_64"
		architecture "x86_64"


project "Raytrazer.Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	exceptionhandling "Off"
	rtti "Off"

	files {
		"src/editor/**.h",
		"src/editor/**.cpp"
	}

	includedirs {
		path.join(GLAD_DIR, "include"),
		path.join(GLFW_DIR, "include"),
		GLM_DIR,
		IMGUI_DIR,
		"src/core/include"
	}
  
	links { "GLAD", "GLFW", "ImGui" }

	filter "system:linux"
		links { "dl", "GL", "X11" }
		
	filter "system:windows"
		links { "gdi32", "kernel32", "psapi" }


project "Raytrazer.Core"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	exceptionhandling "Off"
	rtti "Off"

	includedirs { 
		"src/core/include/" 
	}
  
	files {
	  "src/core/include/*.h",
	  "src/core/*.cpp"
	}

	links { }

	filter "system:linux"
    	links { "dl", "pthread" }
    	defines { "_CORE_X11" }
		
	filter "system:windows"
    	defines { "_CORE_WINDOWS" }


group "Dependencies"
	include "dependencies/glad.lua"
	include "dependencies/glfw.lua"
	include "dependencies/imgui.lua"
