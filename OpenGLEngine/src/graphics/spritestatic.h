#pragma once

#include "sprite.h"

namespace thirdsengine {
	namespace graphics {

		class SpriteStatic : public Renderable2D {
		private:
			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;

		public:
			SpriteStatic(glm::vec3 pos, glm::vec2 size, glm::vec4 col);
			~SpriteStatic();

			inline const VertexArray* getVAO() const { return m_VertexArray; }
			inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }
		};
	}
}