#ifndef EDITOR_WINDOW_H_
#define EDITOR_WINDOW_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#define GLFW_EXPOSE_NATIVE_WIN32
//#include <GLFW/glfw3native.h>

namespace raytrazer_editor {

	struct WindowData {
		const char* title;
		unsigned int width;
		unsigned int height;
	};

	class EditorWindow {

	public:
		EditorWindow(const char* title, unsigned int width, unsigned int height);
		~EditorWindow();

		void Create();
		void Destroy();

		void PollEvents();
		void SwapBuffers();

		bool ShouldClose();

		GLFWwindow* GetGlfwWindow();

	private:
		GLFWwindow* m_window = nullptr;
		WindowData m_windowData{};

	};

}  // namespace raytrazer_editor

#endif  // EDITOR_WINDOW_H_
