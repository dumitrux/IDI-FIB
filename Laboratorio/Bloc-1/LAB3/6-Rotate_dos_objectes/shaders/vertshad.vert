#version 330 core

in vec3 vertex;
in vec3 colors;
out vec4 out_colors;
uniform mat4 TG;

void main()  {
    gl_Position = TG * vec4 (vertex, 1.0);
    out_colors = vec4(colors, 1.0);
}
