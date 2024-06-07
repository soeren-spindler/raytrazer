#include "editor_user_interface.h"

#include <cstdio>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>


raytrazer_editor::EditorUserInterface::EditorUserInterface()
{
}

raytrazer_editor::EditorUserInterface::~EditorUserInterface()
{
}

void raytrazer_editor::EditorUserInterface::Initialize(EditorWindow& window)
{
	printf("EditorUserInterface::Initialize");

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();

	ImGui_ImplGlfw_InitForOpenGL(window.GetGlfwWindow(), true);
#ifdef __EMSCRIPTEN__
	ImGui_ImplGlfw_InstallEmscriptenCanvasResizeCallback("#canvas");
#endif
	ImGui_ImplOpenGL3_Init();
}

void raytrazer_editor::EditorUserInterface::Destroy()
{
	printf("EditorUserInterface::Destroy");

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void raytrazer_editor::EditorUserInterface::RenderFrame()
{
	// Start the Dear ImGui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	Render();

	ImGui::Render();
}

void raytrazer_editor::EditorUserInterface::RenderDrawData()
{
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void raytrazer_editor::EditorUserInterface::Render()
{
	if (show_demo_window)
		ImGui::ShowDemoWindow(&show_demo_window);
}

