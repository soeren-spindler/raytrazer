#ifndef EDITOR_SCENE_RENDERER_H_
#define EDITOR_SCENE_RENDERER_H_

#include <memory>

#include <glm/glm.hpp>

#include "editor_core.h"
#include "editor_window.h"
#include "editor_user_interface.h"


namespace raytrazer_editor
{
	class EditorApplication
	{
	public:
		EditorApplication();
		~EditorApplication();

		void Initialize();
		void Destroy();

		/// @brief The actual renders everything
		void Update();

		bool ShouldClose();

	private:
		std::unique_ptr<EditorWindow> m_window;
		EditorUserInterface m_userInterface{};
		
		glm::vec4 m_clearColor = { 0.45f, 0.55f, 0.60f, 1.00f };
	};

}  // namespace raytrazer_editor

#endif  // EDITOR_SCENE_RENDERER_H_
