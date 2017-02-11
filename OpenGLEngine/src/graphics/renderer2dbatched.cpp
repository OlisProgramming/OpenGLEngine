#include "renderer2dbatched.h"

namespace thirdsengine {
	namespace graphics {

		Renderer2DBatched::Renderer2DBatched(Shader& shader) :
			m_CurrentShader(shader) {

			glGenVertexArrays(1, &m_VAO);
			glBindVertexArray(m_VAO);
			
			glGenBuffers(1, &m_VBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

			glBufferData(GL_ARRAY_BUFFER, RENDERER2D_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glEnableVertexAttribArray(SHADER_COLOUR_INDEX);

			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER2D_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::pos)));
			glVertexAttribPointer(SHADER_COLOUR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER2D_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::col)));

			glBindBuffer(GL_ARRAY_BUFFER, NULL);

			// Generate indices

			GLushort indices[RENDERER2D_INDICES_SIZE];

			int offset = 0;
			for (int i = 0; i < RENDERER2D_INDICES_SIZE; i+=6) {
				indices[i + 0] = offset + 0;
				indices[i + 1] = offset + 1;
				indices[i + 2] = offset + 2;
				indices[i + 3] = offset + 2;
				indices[i + 4] = offset + 3;
				indices[i + 5] = offset + 0;
				offset += 4;
			}

			m_IBO = new IndexBuffer(indices, RENDERER2D_INDICES_SIZE);

			glBindVertexArray(NULL);
		}

		Renderer2DBatched::~Renderer2DBatched() {
			delete m_IBO;
			glDeleteBuffers(1, &m_VBO);
			glDeleteBuffers(1, &m_VAO);
		}

		void Renderer2DBatched::begin() {
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);  // TODO m_Buffer was nullptr
		}

		void Renderer2DBatched::submit(Renderable2D* renderable) {

			if (m_IndexCount + 6 > RENDERER2D_INDICES_SIZE) {
				end();
				flush();
				begin();
			}

			const glm::vec3& pos = renderable->getPosition();
			const glm::vec2& size = renderable->getSize();
			const glm::vec4& colour = renderable->getColour();

			int r = (int)(colour.x * 255.0f);
			int g = (int)(colour.y * 255.0f);
			int b = (int)(colour.z * 255.0f);
			int a = (int)(colour.w * 255.0f);
			unsigned int col = a << 24 | b << 16 | g << 8 | r;

			m_Buffer->pos = pos;
			m_Buffer->col = col;
			m_Buffer++;

			m_Buffer->pos = glm::vec3(pos.x + size.x, pos.y, pos.z);
			m_Buffer->col = col;
			m_Buffer++;

			m_Buffer->pos = glm::vec3(pos.x + size.x, pos.y + size.y, pos.z);
			m_Buffer->col = col;
			m_Buffer++;

			m_Buffer->pos = glm::vec3(pos.x, pos.y + size.y, pos.z);
			m_Buffer->col = col;
			m_Buffer++;

			m_IndexCount += 6;
		}

		void Renderer2DBatched::end() {
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, NULL);
		}

		void Renderer2DBatched::flush() {
			glBindVertexArray(m_VAO);
			m_IBO->enable();

			glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, NULL);

			m_IBO->disable();
			glBindVertexArray(NULL);

			m_IndexCount = 0;
		}
	}
}