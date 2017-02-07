#include "src\graphics\window.h"
#include "src\graphics\shader.h"

#include <glm\glm.hpp>

int main() {
	
	using namespace thirdsengine;
	using namespace graphics;
	using namespace glm;

	std::cout << "Thirds Engine initialising..." << std::endl;

	Window window("Thirds Engine", 960, 540);
	glClearColor(0.2f, 0.4f, 0.7f, 1.0f);

	GLfloat vertices[] = {
		-0.5f,	-0.5f,	0.0f,
		 0.0f,	 0.5f,	0.0f,
		 0.5f,	-0.5f,	0.0f,
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Shader shader("src/shader/vert.glsl", "src/shader/frag.glsl");
	shader.enable();

	while (!window.closed()) {
		
		window.clear();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		window.update();
	}

	return 0;
}
