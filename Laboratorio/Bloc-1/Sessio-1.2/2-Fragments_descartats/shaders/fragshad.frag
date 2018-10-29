#version 330 core

out vec4 FragColor;

void main() {
    //FragColor = vec4(0, 0, 0, 1); // negro
    //FragColor = vec4(1, 1, 1, 1); // blanco
    
    /*
    FragColor = vec4(1.); // blanco
    if (gl_FragCoord.x < 354.)
		FragColor = vec4(1., 0., 0., 1);
	*/
	
	//if (int(gl_FragCoord.y) % 26 <= 14) { // 354/14 -> 25.29
	if (int(gl_FragCoord.y) % 28 <= 13) { // 354/13 -> 27.23
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
	else FragColor = vec4(0.5, 0.7, 1.0, 1.0);
}
