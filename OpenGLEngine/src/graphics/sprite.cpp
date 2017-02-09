#include "sprite.h"

namespace thirdsengine {
	namespace graphics {

		Sprite::Sprite(glm::vec3 pos, glm::vec2 size, glm::vec4 col) :
			Renderable2D(pos, size, col) {

		}
	}
}