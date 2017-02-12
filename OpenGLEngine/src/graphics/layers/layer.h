#pragma once

#include <vector>
#include "../renderer2d.h"

namespace thirdsengine {
	namespace graphics {

		class Layer {
		protected:
			Renderer2D* m_Renderer;
			std::vector<Renderable2D*> m_Renderables;
			Shader* m_Shader;
			glm::mat4 m_ProjectionMatrix;

		protected:
			Layer(Renderer2D* renderer, Shader* shader, glm::mat4 projectionMatrix);
		public:
			virtual ~Layer();
			virtual void add(Renderable2D* renderable);
			virtual void render();
		};
	}
}