#include "shader.h"

namespace thirdsengine {
	namespace graphics {

		Shader::Shader(const char* vert, const char* frag) :
			m_VertPath(vert), m_FragPath(frag) {
			m_Shader = load();
		}

		Shader::~Shader() {
			glDeleteProgram(m_Shader);
		}

		void Shader::enable() const {
			glUseProgram(m_Shader);
		}

		void Shader::disable() const {
			glUseProgram(NULL);
		}

		GLuint Shader::load() {
			GLuint program = glCreateProgram();

			GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSource = readFile(m_VertPath);
			std::string fragSource = readFile(m_FragPath);
			const char* vertCstr = vertSource.c_str();
			const char* fragCstr = fragSource.c_str();
			glShaderSource(vertShader, 1, &vertCstr, NULL);
			glShaderSource(fragShader, 1, &fragCstr, NULL);

			glCompileShader(vertShader);
			GLint vertResult;
			glGetShaderiv(vertShader, GL_COMPILE_STATUS, &vertResult);
			if (vertResult == GL_FALSE) {
				GLint length;
				glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertShader, length, &length, &error[0]);
				std::cout << "Failed to compile vertex shader!" << std::endl << &error[0] << std::endl;
				glDeleteShader(vertShader);
				return NULL;
			}

			glCompileShader(fragShader);
			GLint fragResult;
			glGetShaderiv(fragShader, GL_COMPILE_STATUS, &fragResult);
			if (fragResult == GL_FALSE) {
				GLint length;
				glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragShader, length, &length, &error[0]);
				std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
				glDeleteShader(vertShader);
				glDeleteShader(fragShader);
				return NULL;
			}

			glAttachShader(program, vertShader);
			glAttachShader(program, fragShader);

			glLinkProgram(program);
			glValidateProgram(program);
			
			glDeleteShader(vertShader);
			glDeleteShader(fragShader);

			return program;
		}
	}
}