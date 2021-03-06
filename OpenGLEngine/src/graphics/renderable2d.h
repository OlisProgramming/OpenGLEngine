#pragma once

#include <glm\glm.hpp>
#include "buffers\buffer.h"
#include "buffers\indexbuffer.h"
#include "buffers\vertexarray.h"

namespace thirdsengine {
	namespace graphics {

		class Renderer2D;

		struct VertexData {
			glm::vec3 pos;
			//glm::vec4 col;
			unsigned int col;
		};

		class Renderable2D {
		protected:
			glm::vec2 m_Size;
			glm::vec3 m_Position;
			glm::vec4 m_Colour;			

		protected:
			Renderable2D() {}
		public:
			Renderable2D(glm::vec3 pos, glm::vec2 size, glm::vec4 col);
			virtual ~Renderable2D();

			virtual void submitTo(Renderer2D* renderer);

			inline const glm::vec2& getSize() const { return m_Size; }
			inline const glm::vec3& getPosition() const { return m_Position; }
			inline const glm::vec4& getColour() const { return m_Colour; }
		};
	}
}