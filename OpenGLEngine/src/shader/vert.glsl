#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec4 _col;

out vec4 col;

uniform mat4 projMatrix = mat4(1.0);
uniform mat4 viewMatrix = mat4(1.0);
uniform mat4 modelMatrix = mat4(1.0);

void main() {
	gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(pos, 1.0);
	col = _col;
}