#include "buffer.h"

#define NULL 0

namespace thirdsengine {
	namespace graphics {

		Buffer::Buffer(GLfloat *data, GLsizei count, GLint componentCount)  :
			m_ComponentCount(componentCount) {

			glGenBuffers(1, &m_BufferID);
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, NULL);
		}

		Buffer::~Buffer() {
			glDeleteBuffers(1, &m_BufferID);
		}

		void Buffer::enable() const {
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		}

		void Buffer::disable() const {
			glBindBuffer(GL_ARRAY_BUFFER, NULL);
		}
	}
}