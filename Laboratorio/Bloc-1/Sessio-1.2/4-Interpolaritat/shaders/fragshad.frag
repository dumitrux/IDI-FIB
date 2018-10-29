#version 330 core

out vec4 FragColor;
in vec4 out_colors;

void main() {
    FragColor = out_colors;
}

