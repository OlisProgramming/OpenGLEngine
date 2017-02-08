#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>

#include "renderable2d.h"
#include "shader.h"

namespace thirdsengine {
	namespace graphics {

		class Renderer2D {
		protected:
			virtual void submit(Renderable2D* renderable) = 0;
			virtual void flush(Shader& currentShader) = 0;
		};
	}
}