#include "src\graphics\window.h"
#include "src\graphics\shader.h"
#include "src\graphics\buffers\buffer.h"
#include "src\graphics\buffers\indexbuffer.h"
#include "src\graphics\buffers\vertexarray.h"
#include "src\graphics\sprite.h"
#include "src\graphics\renderer2dbatched.h"

#include <glm\gtx\transform.hpp>
#include <glm\gtc\matrix_transform.hpp>

int main() {
	
	using namespace thirdsengine;
	using namespace graphics;

	std::cout << "Thirds Engine initialising..." << std::endl;

	Window window("Thirds Engine", 960, 540);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	Shader shader("src/shader/vert.glsl", "src/shader/frag.glsl");
	shader.enable();

	glm::mat4 view = glm::lookAt(glm::vec3(10,10,20), glm::vec3(10,10,0), glm::vec3(0,1,0));
	shader.setUniformMat4("viewMatrix", view);
	glm::mat4 proj = glm::perspective(glm::radians(60.0f), window.getAspect(), 0.1f, 100.0f);
	shader.setUniformMat4("projMatrix", proj);

	window.setShader(&shader);

	std::vector<Sprite*> sprites;
	for (float i = 0; i < 20; i+=0.1)
		for (float j = 0; j < 20; j += 0.1)
			sprites.push_back(new Sprite(glm::vec3(i,j,0.0), glm::vec2(0.08, 0.08), glm::vec4(i/20.0, 1.0, j/20.0, 1.0)));
	
	Renderer2DBatched renderer(shader);

	while (!window.closed()) {
		
		window.clear();
		
		renderer.begin();
		for (Sprite* spr : sprites)
			renderer.submit(spr);
		renderer.end();
		renderer.flush();

		window.update();
	}

	sprites.clear();

	return 0;
}
