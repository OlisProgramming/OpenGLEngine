#include "src\graphics\window.h"
#include "src\graphics\shader.h"
#include "src\graphics\buffers\buffer.h"
#include "src\graphics\buffers\indexbuffer.h"
#include "src\graphics\buffers\vertexarray.h"
#include "src\graphics\sprite.h"
#include "src\graphics\renderer2dbatched.h"
#include "src\graphics\renderablegroup2d.h"
#include "src\util\timer.h"
#include "src\graphics\layers\layerscene.h"

#include <glm\gtx\transform.hpp>
#include <glm\gtc\matrix_transform.hpp>

int main() {
	
	using namespace thirdsengine;
	using namespace graphics;

	std::cout << "Thirds Engine initialising..." << std::endl;

	Window window("Thirds Engine", 960, 540);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	Shader* shader = new Shader("src/shader/vert.glsl", "src/shader/frag.glsl");

	shader->enable();

	glm::mat4 view = glm::lookAt(glm::vec3(10, 10, 20), glm::vec3(10, 10, 0), glm::vec3(0, 1, 0));
	shader->setUniformMat4("viewMatrix", view);

	window.setShader(shader);

	glm::mat4 proj = glm::perspective(glm::radians(60.0f), window.getAspect(), 0.1f, 100.0f);
	LayerScene* layer = new LayerScene(shader, proj);

	RenderableGroup2D* group = new RenderableGroup2D();

	for (float i = 0; i < 20; i += 0.1f)
		for (float j = 0; j < 20; j += 0.1f)
			group->add(new Sprite(glm::vec3(i, j, 0.0), glm::vec2(0.08, 0.08), glm::vec4(i / 20.0, 1.0, j / 20.0, 1.0)));

	group->push(MATRIX_TRANSLATE(glm::vec3(-10, -10, 0)));
	group->push(MATRIX_ROTATE(DEGREES_45, glm::vec3(0, 0, 1)));
	group->push(MATRIX_TRANSLATE(glm::vec3(10, 10, 0)));

	layer->add(group);

	Timer timer;

	while (!window.closed()) {
		
		window.clear();

		layer->render();

		window.update();

		timer.tick();
		printf("%f Average FPS\n", timer.getFPSStable());
		timer.reset();
	}

	delete layer;

	return 0;
}
