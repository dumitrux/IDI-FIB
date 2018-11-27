#version 330 core

out vec4 FragColor;

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
	
	// Direccio llum i posFocus en SCA
	vec3 L = posFocus - vertSCO;
	
	// Passar vector normal a SCO
	mat3 NormalMatrix = (inverse(transpose(mat3(view * TG))));
	vec3 NM = NormalMatrix * normal;
	
	// Nomes la Normal i la L son "vcectors", els unics que es normalitzen
	L = normalize(L);
	NM = normalize(NM);
	
	FragColor = Phong(NM, L, vec4(vertSCO, 1.));
}
