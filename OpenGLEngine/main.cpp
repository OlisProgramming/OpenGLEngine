#include "src\graphics\window.h"
#include "src\graphics\shader.h"
#include "src\graphics\buffers\buffer.h"
#include "src\graphics\buffers\indexbuffer.h"
#include "src\graphics\buffers\vertexarray.h"
#include "src\graphics\renderer2d.h"
#include "src\graphics\renderable2d.h"
#include "src\graphics\renderer2dbasic.h"

#include <glm\gtx\transform.hpp>
#include <glm\gtc\matrix_transform.hpp>

int main() {
	
	using namespace thirdsengine;
	using namespace graphics;

	std::cout << "Thirds Engine initialising..." << std::endl;

	Window window("Thirds Engine", 960, 540);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

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

	Shader shader("src/shader/vert.glsl", "src/shader/frag.glsl");
	shader.enable();

	glm::mat4 view = glm::lookAt(glm::vec3(2,1,2), glm::vec3(), glm::vec3(0,1,0));
	//glm::mat4 view = glm::translate(glm::vec3(-1,0,0));
	shader.setUniformMat4("viewMatrix", view);
	glm::mat4 proj = glm::perspective(glm::radians(60.0f), window.getAspect(), 0.1f, 100.0f);
	shader.setUniformMat4("projMatrix", proj);

	Renderable2D renderable(glm::vec3(), glm::vec2(1,1), glm::vec4(1.0, 0.0, 0.0, 1.0));
	Renderer2DBasic renderer;

	while (!window.closed()) {
		
		window.clear();
		
		renderer.submit(&renderable);
		renderer.flush(shader);

		window.update();
	}

	return 0;
}
