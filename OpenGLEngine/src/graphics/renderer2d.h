#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>

#include "renderable2d.h"
#include "shader.h"

namespace thirdsengine {
	namespace graphics {

#define RENDERER2D_MAX_SPRITES		(10000)
#define RENDERER2D_VERTEX_SIZE		(sizeof(VertexData))
#define RENDERER2D_SPRITE_SIZE		(RENDERER2D_VERTEX_SIZE * 4)
#define RENDERER2D_BUFFER_SIZE		(RENDERER2D_SPRITE_SIZE * RENDERER2D_MAX_SPRITES)
#define RENDERER2D_INDICES_SIZE		(RENDERER2D_MAX_SPRITES * 6)

#define SHADER_VERTEX_INDEX			(0)
#define SHADER_COLOUR_INDEX			(1)

		class Renderer2D {
		public:
			virtual void begin() = 0;
			virtual void submit(Renderable2D* renderable) = 0;
			virtual void end() = 0;
			virtual void flush() = 0;
		};
	}
}