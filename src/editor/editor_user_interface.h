#ifndef EDITOR_USER_INTERFACE_H_
#define EDITOR_USER_INTERFACE_H_

#include "editor_window.h"

namespace raytrazer_editor
{

	class EditorUserInterface
	{
	public:
		EditorUserInterface();
		~EditorUserInterface();

		void Initialize(EditorWindow& window);
		void Destroy();

		void RenderFrame();
		void RenderDrawData();

	private:
		bool show_demo_window = true;

		void Render();
	};

}  // namespace raytrazer_editor

#endif  // EDITOR_USER_INTERFACE_H_
