#version 330 core

layout (location = 0) in vec4 pos;
layout (location = 1) in vec4 _col;

out vec4 col;

uniform mat4 projMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix = mat4(1.0);

void main() {
	gl_Position = projMatrix * viewMatrix * modelMatrix * pos;
	col = _col;
}