#include "layerscene.h"

namespace thirdsengine {
	namespace graphics {

		LayerScene::LayerScene(Shader* shader, glm::mat4 projectionMatrix) :
			Layer(new Renderer2DBatched(*shader), shader, projectionMatrix) {
		}
	}
}