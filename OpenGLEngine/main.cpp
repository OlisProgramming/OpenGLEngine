#include "src\graphics\window.h"
#include "src\graphics\shader.h"
#include "src\graphics\buffers\buffer.h"
#include "src\graphics\buffers\indexbuffer.h"
#include "src\graphics\buffers\vertexarray.h"

#include <glm\gtx\transform.hpp>
#include <glm\gtc\matrix_transform.hpp>

int main() {
	
	using namespace thirdsengine;
	using namespace graphics;

	std::cout << "Thirds Engine initialising..." << std::endl;

	Window window("Thirds Engine", 960, 540);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

#if 0
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
#else
	GLfloat vertices[] = {
		-0.5f,	-0.5f,	0.0f,
		0.5f,	 0.5f,	0.0f,
		-0.5f,	 0.5f,	0.0f,
		0.5f,	-0.5f,	0.0f,
		0.0f,	1.0f,	0.0f,
	};
	GLushort indices[] = {
		0, 2, 3,
		2, 1, 3,
		2, 4, 1,
	};
	GLfloat colours[] = {
		1.0f, 1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
	};

	VertexArray vao;
	IndexBuffer ibo(indices, sizeof(indices) / sizeof(GLushort));

	vao.addBuffer(
		new Buffer(vertices, sizeof(vertices) / sizeof(GLfloat), 3),
		0);
	vao.addBuffer(
		new Buffer(colours, sizeof(colours) / sizeof(GLfloat), 4),
		1);
#endif

	Shader shader("src/shader/vert.glsl", "src/shader/frag.glsl");
	shader.enable();

	glm::mat4 view = glm::lookAt(glm::vec3(2,1,2), glm::vec3(), glm::vec3(0,1,0));
	//glm::mat4 view = glm::translate(glm::vec3(-1,0,0));
	shader.setUniformMat4("viewMatrix", view);
	glm::mat4 proj = glm::perspective(glm::radians(60.0f), window.getAspect(), 0.1f, 100.0f);
	shader.setUniformMat4("projMatrix", proj);

	while (!window.closed()) {
		
		window.clear();

#if 0
		glDrawArrays(GL_TRIANGLES, 0, 3);
#else
		vao.enable();
		ibo.enable();
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.disable();
		vao.disable();
#endif
		
		window.update();
	}

	return 0;
}
