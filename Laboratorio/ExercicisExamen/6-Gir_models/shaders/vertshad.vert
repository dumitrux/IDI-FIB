#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

// Valors per als components que necessitem dels focus de llum
vec3 colFocus = vec3(0.8, 0.8, 0.8);
vec3 llumAmbient = vec3(0.2, 0.2, 0.2);
vec3 posFocus = vec3(0, 1, 0); 

out vec3 fcolor;

vec3 Lambert (vec3 NormSCO, vec3 L) 
{
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats

    // Inicialitzem color a component ambient
    vec3 colRes = llumAmbient * matamb;

    // Afegim component difusa, si n'hi ha
    if (dot (L, NormSCO) > 0)
      colRes = colRes + colFocus * matdiff * dot (L, NormSCO);
    return (colRes);
}

vec3 Phong (vec3 NormSCO, vec3 L, vec4 vertSCO) 
{
    // Els vectors estan normalitzats

    // Inicialitzem color a Lambert
    vec3 colRes = Lambert (NormSCO, L);

    // Calculem R i V
    if (dot(NormSCO,L) < 0)
      return colRes;  // no hi ha component especular

    vec3 R = reflect(-L, NormSCO); // equival a: normalize (2.0*dot(NormSCO,L)*NormSCO - L);
    vec3 V = normalize(-vertSCO.xyz);

    if ((dot(R, V) < 0) || (matshin == 0))
      return colRes;  // no hi ha component especular
    
    // Afegim la component especular
    float shine = pow(max(0.0, dot(R, V)), matshin);
    return (colRes + matspec * colFocus * shine); 
}

void main()
{	
    // Passar posicio del vertex a SCO
	vec3 vertSCO = (view * TG * vec4(vertex, 1.0)).xyz;
	
	// Pasar posicio del focus de llum en SCO
	// vec3 posF = (view * vec4(posFocus, 1.0)).xyz;
	// Dixar posicio del focus de llum en SCA
	vec3 posF = posFocus;
	// Direccio llum
	vec3 L = posF - vertSCO;
	
	// Passar vector normal a SCO
	mat3 NormalMatrix = (inverse(transpose(mat3(view * TG))));
	vec3 NM = NormalMatrix * normal;
	
	// Nomes la Normal i la L son "vcectors", els unics que es normalitzen
	L = normalize(L);
	NM = normalize(NM);
	
    fcolor = Phong(NM, L, vec4(vertSCO, 1.));
    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
}
