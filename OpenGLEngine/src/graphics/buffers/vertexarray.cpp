#include "vertexarray.h"

namespace thirdsengine {
	namespace graphics {

		VertexArray::VertexArray() {

		}

		VertexArray::~VertexArray() {
			for (int i = 0; i < m_Buffers.size(); i++) {
				delete m_Buffers[i];
			}
		}

		void VertexArray::addBuffer(Buffer *buffer, GLuint index) {
			enable();
			buffer->enable();

			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

			buffer->disable();
			disable();

			m_Buffers.push_back(buffer);
		}

		void VertexArray::enable() const {
			glBindVertexArray(m_ArrayID);
		}

		void VertexArray::disable() const {
			glBindVertexArray(NULL);
		}
	}
}