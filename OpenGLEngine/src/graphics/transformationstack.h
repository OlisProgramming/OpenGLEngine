#pragma once

#include <vector>
#include <glm\glm.hpp>
#include "../util/constants.h"

namespace thirdsengine {
	namespace graphics {

		class TransformationStack {
		private:
			std::vector<glm::mat4> m_Transformations;
			glm::mat4 m_CurrentTransformation;

		public:
			TransformationStack() { push(glm::mat4(1.0), true); }

			void push(const glm::mat4& matrix, bool override = false) {
				if (!override)
					m_Transformations.push_back(matrix * m_CurrentTransformation);
				else
					m_Transformations.push_back(matrix);
				m_CurrentTransformation = m_Transformations.back();

				//std::cout << "Push:\n";
				//PRINT_MATRIX(m_CurrentTransformation);
			}

			void pop() {
				if (m_Transformations.size() > 1)
					m_Transformations.pop_back();
				
				m_CurrentTransformation = m_Transformations.back();

				//std::cout << "Pop:\n";
				//PRINT_MATRIX(m_CurrentTransformation);
			}

			glm::mat4& transformation() { return m_CurrentTransformation; }
		};
	}
}