#pragma once

#include "renderable2d.h"

namespace thirdsengine {
	namespace graphics {

		class Sprite : public Renderable2D {
		public:
			Sprite(glm::vec3 pos, glm::vec2 size, glm::vec4 col);
		};
	}
}