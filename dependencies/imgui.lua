project "ImGui"
	kind "StaticLib"
	language "C"

	files
	{
		"imgui/*.h",
		"imgui/*.cpp",
		"imgui/backends/imgui_impl_glfw.*",
		"imgui/backends/imgui_impl_opengl3.*"
	}

	includedirs { "imgui/", "glad/include", "glfw/include/" }

	defines "IMGUI_IMPL_OPENGL_LOADER_GLAD"
    
	filter "system:linux"
		defines "_IMGUI_X11"

	filter "system:windows"
		defines "_IMGUI_WIN32"

	filter "action:vs*"
		defines "_CRT_SECURE_NO_WARNINGS"