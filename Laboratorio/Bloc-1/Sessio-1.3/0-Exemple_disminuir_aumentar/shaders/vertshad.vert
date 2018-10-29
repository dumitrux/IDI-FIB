#version 330 core

in vec3 vertex;
uniform float val;

void main()  {
    gl_Position = vec4 (vertex * val, 1.0);
}
