#version 330

in vec2 inVertex;

void main() {
    gl_Position = vec4(inVertex.x, inVertex.y, 0.0, 1.0);
}