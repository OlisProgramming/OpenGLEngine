#pragma once

#define GL_PRINT_ERROR(msg) { GLenum error = glGetError(); if (error != GL_NO_ERROR) std::cout << "OpenGL error code " << error << " at " << msg << std::endl; else std::cout << "No error at " << msg << std::endl; }