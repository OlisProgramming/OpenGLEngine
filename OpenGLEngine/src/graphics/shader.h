#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "../util/fileutils.h"

namespace thirdsengine {
	namespace graphics {

		class Shader {
		private:
			GLuint m_Shader;
			const char* m_VertPath;
			const char* m_FragPath;

		public:
			Shader(const char* vert, const char* frag);
			~Shader();

			void enable() const;
			void disable() const;
		private:
			GLuint load();
		};
	}
}