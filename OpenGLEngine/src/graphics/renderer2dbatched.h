#pragma once

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
		public:
			Renderer2DBatched();
			~Renderer2DBatched();
			void begin();
			void submit(Renderable2D* renderable) override;
			void end();
			void flush(Shader& currentShader) override;
		};
	}
}