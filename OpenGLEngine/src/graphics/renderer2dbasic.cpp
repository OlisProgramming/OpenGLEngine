#include "renderer2dbasic.h"

#include <glm\gtx\transform.hpp>

namespace thirdsengine {
	namespace graphics {

		void Renderer2DBasic::submit(Renderable2D* renderable) {
			m_Renderables.push_back(renderable);
		}

		void Renderer2DBasic::flush(Shader& currentShader) {
			while (!m_Renderables.empty()) {
				Renderable2D* renderable = m_Renderables.front();
				renderable->getVAO()->enable();
				renderable->getIBO()->enable();
				
				//currentShader.setUniformMat4("modelMatrix", glm::translate(renderable->getPosition()));
				glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, NULL);

				renderable->getIBO()->disable();
				renderable->getVAO()->disable();

				m_Renderables.pop_front();
			}
		}
	}
}