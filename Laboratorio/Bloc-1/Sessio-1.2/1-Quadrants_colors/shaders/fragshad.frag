#version 330 core

out vec4 FragColor;
// variables predefinides
// in vec4 gl_FragCoord;
// out float gl_FragDepth; 

void main() {
    //FragColor = vec4(0, 0, 0, 1); // negro
    //FragColor = vec4(1, 1, 1, 1); // blanco
    
    /*
    FragColor = vec4(1.); // blanco
    if (gl_FragCoord.x < 354.)
		FragColor = vec4(1., 0., 0., 1);
	*/
	
	// arriba izq
	if (gl_FragCoord.x < 354 && gl_FragCoord.y > 354)
		FragColor = vec4(1, 0, 0, 1);
	// arriba der
	if (gl_FragCoord.x > 354 && gl_FragCoord.y > 354)
		FragColor = vec4(0, 0, 1, 1);
	// abajo izq
	if (gl_FragCoord.x < 354 && gl_FragCoord.y < 354)
		FragColor = vec4(1, 1, 0, 1);
	// abajo der
	if (gl_FragCoord.x > 354 && gl_FragCoord.y < 354)
		FragColor = vec4(0, 1, 0, 1);
}

