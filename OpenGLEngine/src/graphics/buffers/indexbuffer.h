#pragma once

#include <GL/glew.h>

namespace thirdsengine {
	namespace graphics {

		class IndexBuffer {
		private:
			GLuint m_BufferID;
			GLuint m_Count;

		public:
			IndexBuffer(GLushort* data, GLsizei count);

			void enable() const;
			void disable() const;

			inline GLuint getCount() const { return m_Count; }
		};
	}
}