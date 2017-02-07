#include "src\graphics\window.h"

int main() {
	
	using namespace thirdsengine;
	using namespace graphics;

	std::cout << "Thirds Engine initialising..." << std::endl;

	Window window("Thirds Engine", 960, 540);

	glClearColor(0.2f, 0.4f, 0.7f, 1.0f);

	while (!window.closed()) {
		
		window.clear();

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();

		window.update();
	}

	return 0;
}
