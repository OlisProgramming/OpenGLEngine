#include "renderer2dbasic.h"

#include <glm\gtx\transform.hpp>

namespace thirdsengine {
	namespace graphics {

		void Renderer2DBasic::submit(Renderable2D* renderable) {
			m_Sprites.push_back((SpriteStatic*)renderable);
		}

		void Renderer2DBasic::flush(Shader& currentShader) {
			while (!m_Sprites.empty()) {
				SpriteStatic* renderable = (SpriteStatic*)(m_Sprites.front());
				renderable->getVAO()->enable();
				renderable->getIBO()->enable();
				
				//currentShader.setUniformMat4("modelMatrix", glm::translate(renderable->getPosition()));
				glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, NULL);

				renderable->getIBO()->disable();
				renderable->getVAO()->disable();

				m_Sprites.pop_front();
			}
		}
	}
}