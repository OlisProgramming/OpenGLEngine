#include "src\graphics\window.h"
#include "src\graphics\shader.h"

#include <glm\gtx\transform.hpp>
#include <glm\gtc\matrix_transform.hpp>

int main() {
	
	using namespace thirdsengine;
	using namespace graphics;

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

	glm::mat4 view = glm::lookAt(glm::vec3(5,2,5), glm::vec3(), glm::vec3(0,1,0));
	//glm::mat4 view = glm::translate(glm::vec3(-1,0,0));
	shader.setUniformMat4("viewMatrix", view);
	glm::mat4 proj = glm::perspective(glm::radians(60.0f), 16.0f / 9.0f, 0.1f, 100.0f);
	shader.setUniformMat4("projMatrix", proj);

	while (!window.closed()) {
		
		window.clear();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		window.update();
	}

	return 0;
}
