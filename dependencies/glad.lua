local GLAD_DIR = "glad"

project "GLAD"
	kind "StaticLib"
	language "C"

	files 
	{
		path.join(GLAD_DIR, "include/**.h"),
		path.join(GLAD_DIR, "src/glad.c") 
	}

	includedirs { path.join(GLAD_DIR, "include") }
    
	filter "system:linux"
		defines "_GLAD_X11"

	filter "system:windows"
		defines "_GLAD_WIN32"

	filter "action:vs*"
		defines "_CRT_SECURE_NO_WARNINGS"