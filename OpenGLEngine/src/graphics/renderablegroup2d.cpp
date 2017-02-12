#pragma once

#include "renderablegroup2d.h"
#include "renderer2d.h"

namespace thirdsengine {
	namespace graphics {

		void RenderableGroup2D::submitTo(Renderer2D* renderer) {
			renderer->push(getTransformation());
			for (Renderable2D* renderable : m_Renderables)
				renderable->submitTo(renderer);
			renderer->pop();
		}
	}
}