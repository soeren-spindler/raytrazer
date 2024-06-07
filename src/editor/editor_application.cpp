#include "editor_application.h"


raytrazer_editor::EditorApplication::EditorApplication()
{
}

raytrazer_editor::EditorApplication::~EditorApplication()
{
}

void raytrazer_editor::EditorApplication::Initialize()
{
	m_window = std::unique_ptr<EditorWindow>(new EditorWindow("Editor", 1366, 768));
	m_window->Create();

	m_userInterface.Initialize(*m_window);
}

void raytrazer_editor::EditorApplication::Destroy()
{
	m_userInterface.Destroy();

	m_window->Destroy();
}

void raytrazer_editor::EditorApplication::Update()
{
	m_window->PollEvents();

	m_userInterface.RenderFrame();

	int display_w, display_h;
	glfwGetFramebufferSize(m_window->GetGlfwWindow(), &display_w, &display_h);
	glViewport(0, 0, display_w, display_h);

	glClearColor(
		m_clearColor.x * m_clearColor.w,
		m_clearColor.y * m_clearColor.w,
		m_clearColor.z * m_clearColor.w,
		m_clearColor.w
	);
	glClear(GL_COLOR_BUFFER_BIT);

	m_userInterface.RenderDrawData();

	m_window->SwapBuffers();
}

bool raytrazer_editor::EditorApplication::ShouldClose()
{
	return m_window->ShouldClose();
}
