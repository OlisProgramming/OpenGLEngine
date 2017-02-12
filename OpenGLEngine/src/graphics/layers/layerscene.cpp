#include "layerscene.h"

#include "../../util/constants.h"

namespace thirdsengine {
	namespace graphics {

		LayerScene::LayerScene(Shader* shader, glm::mat4 projectionMatrix) :
			Layer(new Renderer2DBatched(*shader), shader, projectionMatrix) {
			// m_Renderer->pushRotate(DEGREES_45, glm::vec3(0, 0, 1));
		}
	}
}