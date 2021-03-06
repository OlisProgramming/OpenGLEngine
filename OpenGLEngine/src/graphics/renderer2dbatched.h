#pragma once

#include <cstddef>
#include "renderable2d.h"
#include "renderer2d.h"
#include "buffers\indexbuffer.h"

namespace thirdsengine {
	namespace graphics {
		
		class Renderer2DBatched : public Renderer2D {
		private:
			GLuint m_VAO;
			IndexBuffer* m_IBO;
			GLsizei m_IndexCount;
			GLuint m_VBO;
			VertexData* m_Buffer;
			Shader& m_CurrentShader;
		public:
			Renderer2DBatched(Shader& shader);
			~Renderer2DBatched();
			void begin() override;
			void submit(Renderable2D* renderable) override;
			void end() override;
			void flush() override;
		};
	}
}