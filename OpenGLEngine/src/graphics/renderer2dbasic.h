#pragma once

#include <deque>
#include "renderer2d.h"

namespace thirdsengine {
	namespace graphics {

		class Renderer2DBasic : public Renderer2D {
		private:
			std::deque<Renderable2D*> m_Renderables;

		public:
			void submit(Renderable2D* renderable) override;
			void flush(Shader& currentShader) override;
		};
	}
}