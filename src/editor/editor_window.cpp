#include "editor_window.h"

#include <cstdio>
#include <cstdlib>


namespace raytrazer_editor
{
	static void glfw_error_callback(int error, const char* description)
	{
		fprintf(stderr, "GLFW Error %d: %s\n", error, description);
	}
}

raytrazer_editor::EditorWindow::EditorWindow(const char* t_title, unsigned int t_width, unsigned int t_height)
{
	m_windowData.title = t_title;
	m_windowData.width = t_width;
	m_windowData.height = t_height;
}

raytrazer_editor::EditorWindow::~EditorWindow()
{
}

void raytrazer_editor::EditorWindow::Create()
{
	glfwSetErrorCallback(glfw_error_callback);

	if (!glfwInit())
	{
		fprintf(stderr, "Unable to initialize GLFW.");
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(m_windowData.width, m_windowData.height, m_windowData.title, nullptr, nullptr);
	if (m_window == nullptr)
	{
		fprintf(stderr, "Unable to create editor window.");
		Destroy();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(m_window);

	// GLAD
	gladLoadGL();

	// Enable vsync
	glfwSwapInterval(1);
}

void raytrazer_editor::EditorWindow::Destroy()
{
	if (m_window != nullptr)
		glfwDestroyWindow(m_window);

	glfwTerminate();
}

void raytrazer_editor::EditorWindow::PollEvents()
{
	glfwPollEvents();
}

void raytrazer_editor::EditorWindow::SwapBuffers()
{
	glfwSwapBuffers(m_window);
}

bool raytrazer_editor::EditorWindow::ShouldClose()
{
	return glfwWindowShouldClose(m_window);
}

GLFWwindow* raytrazer_editor::EditorWindow::GetGlfwWindow()
{
	return m_window;
}
