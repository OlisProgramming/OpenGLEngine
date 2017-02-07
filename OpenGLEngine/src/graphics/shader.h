#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <glm\glm.hpp>
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

			void setUniformMat4(const char* uniform, glm::mat4 mat);
		private:
			GLuint load();
		};
	}
}