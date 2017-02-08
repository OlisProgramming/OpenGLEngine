#include "renderable2d.h"

namespace thirdsengine {
	namespace graphics {

		Renderable2D::Renderable2D(glm::vec3 pos, glm::vec2 size, glm::vec4 col) :
			m_Position(pos), m_Size(size), m_Colour(col) {
			
			m_VertexArray = new VertexArray();

			GLfloat vertices[] = {
				0, 0, 0,
				0, size.y, 0,
				size.x, size.y, 0,
				size.x, 0, 0,
			};

			GLfloat colours[] = {
				col.x, col.y, col.z, col.w,
				col.x, col.y, col.z, col.w,
				col.x, col.y, col.z, col.w,
				col.x, col.y, col.z, col.w,
			};

			GLushort indices[] = {
				0, 1, 2,
				2, 3, 0,
			};

			m_VertexArray->addBuffer(new Buffer(vertices, sizeof(vertices) / sizeof(GLfloat), 3), 0);
			m_VertexArray->addBuffer(new Buffer(colours, sizeof(colours) / sizeof(GLfloat), 4), 1);

			m_IndexBuffer = new IndexBuffer(indices, 6);
		}

		Renderable2D::~Renderable2D() {
			delete m_VertexArray;
			delete m_IndexBuffer;
		}
	}
}