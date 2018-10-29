#version 330 core

in vec3 vertex;
in vec3 colors;
out vec4 out_colors;

void main()  {
    gl_Position = vec4 (vertex*0.5, 1.0);
    out_colors = vec4(colors, 1.0);
}
