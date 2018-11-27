#version 330 core

in vec3 vertex;
in vec3 normal;


out vec3 vertexF;
out vec3 normalF;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;


out vec3 matambF;
out vec3 matdiffF;
out vec3 matspecF;
out float matshinF;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

// Valors per als components que necessitem dels focus de llum
vec3 colFocus = vec3(0.8, 0.8, 0.8);
vec3 llumAmbient = vec3(0.2, 0.2, 0.2);
vec3 posFocus = vec3(1, 1, 1);  // en SCA

out vec3 fcolor;

void main()
{	
	
	matambF = matamb;
	matdiffF = matdiff;
	matspecF = matspec;
	matshinF = matshin;
	
	vertexF = vertex;
	normalF = normal;
	
	posFocusF = posFocus;
    
    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
}
