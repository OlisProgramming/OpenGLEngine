#version 330 core

layout (location = 0) out vec4 colour;

in vec4 col;

void main() {
	colour = col;
}