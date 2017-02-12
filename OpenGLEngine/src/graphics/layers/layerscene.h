#pragma once

#include "layer.h"
#include "../renderer2dbatched.h"

namespace thirdsengine {
	namespace graphics {

		class LayerScene : public Layer {
		public:
			LayerScene(Shader* shader, glm::mat4 projectionMatrix);
		};
	}
}