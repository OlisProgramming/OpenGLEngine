#include "layer.h"

#include "../renderable2d.h"

namespace thirdsengine {
	namespace graphics {

		Layer::Layer(Renderer2D* renderer, Shader* shader, glm::mat4 projectionMatrix = glm::mat4()) :
			m_Renderer(renderer), m_Shader(shader), m_ProjectionMatrix(projectionMatrix) {
			m_Shader->enable();
			m_Shader->setUniformMat4("projMatrix", m_ProjectionMatrix);
			m_Shader->disable();
		}

		Layer::~Layer() {
			delete m_Shader;
			delete m_Renderer;
			for (unsigned int i = 0; i < m_Renderables.size(); i++)
				delete m_Renderables[i];
		}

		void Layer::add(Renderable2D* renderable) {

			m_Renderables.push_back(renderable);
		}

		void Layer::render() {
			m_Shader->enable();
			m_Renderer->begin();
			for (Renderable2D* renderable : m_Renderables)
				renderable->submitTo(m_Renderer);
			m_Renderer->end();
			m_Renderer->flush();
			m_Shader->disable();
		}
	}
}