#include <cstdlib>

#include "editor_application.h"

using namespace raytrazer_editor;

int main()
{
	EditorApplication application;
	application.Initialize();

	while (!application.ShouldClose())
	{
		application.Update();
	}

	application.Destroy();

	return EXIT_SUCCESS;
}