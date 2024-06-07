#include <cstdio>
#include <cstdlib>

#include "editor_window.h"

using namespace raytrazer_editor;

int main()
{
	EditorWindow window("Raytrazer Editor", 1366, 768);
	window.Create();

	while (!window.ShouldClose())
	{
		window.PollEvents();

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window.SwapBuffers();
	}

	window.Destroy();

	return EXIT_SUCCESS;
}