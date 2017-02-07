#pragma once

#include <GL/glew.h>

namespace thirdsengine {
	namespace graphics {
		
		class Buffer {
		private:
			GLuint m_BufferID;
			GLuint m_ComponentCount;  // How many floats are in each vector? E.g. 2 for vec2

		public:
			Buffer(GLfloat* data, GLsizei count, GLint componentCount);

			void enable() const;
			void disable() const;

			inline GLuint getComponentCount() const { return m_ComponentCount; }
		};
	}
}