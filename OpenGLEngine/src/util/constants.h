#pragma once

#include <iostream>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtc\quaternion.hpp>
#include <glm\gtx\quaternion.hpp>

// The constant Pi to 10 decimal places.
#define PI 3.1415926536f

// The constant Tau, defined as 2 * Pi.
#define TAU (PI * 2)

#define PI_2 (PI / 2)
#define PI_3 (PI / 3)
#define PI_4 (PI / 4)
#define PI_6 (PI / 6)

#define DEGREES_360		TAU
#define DEGREES_180		PI
#define DEGREES_90		PI_2
#define DEGREES_60		PI_3
#define DEGREES_45		PI_4
#define DEGREES_30		PI_6

#define MATRIX_TRANSLATE(vector)			glm::translate(vector)
#define MATRIX_ROTATE(angleRadians, axis)	glm::toMat4(glm::angleAxis(angleRadians, axis))
#define MATRIX_SCALE(vector)				glm::scale(vector)

#define PRINT_MATRIX(mat4)					{ for (int __i = 0; __i < 4; __i++) { for (int __j = 0; __j < 4; __j++) std::cout << mat4[__i][__j] << " "; std::cout << std::endl; } std::cout << std::endl; }