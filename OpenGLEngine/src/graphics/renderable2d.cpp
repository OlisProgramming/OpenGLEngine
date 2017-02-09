#include "renderable2d.h"

namespace thirdsengine {
	namespace graphics {

		Renderable2D::Renderable2D(glm::vec3 pos, glm::vec2 size, glm::vec4 col) :
			m_Position(pos), m_Size(size), m_Colour(col) { }

		Renderable2D::~Renderable2D() { }
	}
}