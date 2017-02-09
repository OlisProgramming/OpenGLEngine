#pragma once

#include <deque>
#include "spritestatic.h"
#include "renderer2d.h"

namespace thirdsengine {
	namespace graphics {

		class Renderer2DBasic : public Renderer2D {
		private:
			std::deque<SpriteStatic*> m_Sprites;

		public:
			void submit(Renderable2D* renderable) override;
			void flush(Shader& currentShader) override;
		};
	}
}