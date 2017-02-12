#pragma once

#include "renderable2d.h"
#include "transformationstack.h"

namespace thirdsengine {
	namespace graphics {

		class RenderableGroup2D : public Renderable2D {
		private:
			std::vector<Renderable2D*> m_Renderables;
			TransformationStack m_TransformationStack;

		public:
			RenderableGroup2D() {}

			void push(glm::mat4 matrix, bool override = false) {
				m_TransformationStack.push(matrix, override);
			}

			void pop() {
				m_TransformationStack.pop();
			}

			glm::mat4 getTransformation() { return m_TransformationStack.transformation(); }

			void add(Renderable2D* renderable) { m_Renderables.push_back(renderable); }
			void submitTo(Renderer2D* renderer) override;
		};
	}
}