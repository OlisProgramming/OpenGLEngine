#version 330 core

layout (location = 0) in vec4 pos;

uniform mat4 projMatrix;
uniform mat4 viewMatrix = mat4(1.0);
uniform mat4 modelMatrix = mat4(1.0);

void main() {
	gl_Position = pos;
}