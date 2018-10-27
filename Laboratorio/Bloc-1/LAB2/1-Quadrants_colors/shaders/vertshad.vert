#version 330 core

in vec3 vertex;
// out vec4 gl_Position; variable predefinida

void main()  {
    gl_Position = vec4 (vertex, 1.0);
}
