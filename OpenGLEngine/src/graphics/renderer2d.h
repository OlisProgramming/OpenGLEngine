#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>

#include "renderable2d.h"
#include "shader.h"

namespace thirdsengine {
	namespace graphics {

#define RENDERER2D_MAX_SPRITES		(10000)
#define RENDERER2D_VERTEX_SIZE		(sizeof(VertexData))
#define RENDERER2D_SPRITE_SIZE		(RENDERER2D_VERTEX_SIZE * 4)
#define RENDERER2D_BUFFER_SIZE		(RENDERER2D_SPRITE_SIZE * RENDERER2D_MAX_SPRITES)
#define RENDERER2D_INDICES_SIZE		(RENDERER2D_MAX_SPRITES * 6)

#define SHADER_VERTEX_INDEX			(0)
#define SHADER_COLOUR_INDEX			(1)

		class Renderer2D {
		private:
			std::vector<glm::mat4> m_TransformationStack;
		protected:
			glm::mat4 m_CurrentTransformation;

		protected:
			Renderer2D() { m_TransformationStack.push_back(glm::mat4(1.0)); }
		public:
			void push(glm::mat4 matrix, bool override = false) {
				if (override)
					m_TransformationStack.push_back(matrix);
				else
					m_TransformationStack.push_back(m_TransformationStack.back() * matrix);
				m_CurrentTransformation = m_TransformationStack.back();
			}

			void pop() {
				if (m_TransformationStack.size() > 1)
					m_TransformationStack.pop_back();
				m_CurrentTransformation = m_TransformationStack.back();
			}

			virtual void begin() = 0;
			virtual void submit(Renderable2D* renderable) = 0;
			virtual void end() = 0;
			virtual void flush() = 0;
		};
	}
}