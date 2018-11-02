#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent), program(NULL)
{
  setFocusPolicy(Qt::StrongFocus);  // per rebre events de teclat
}

MyGLWidget::~MyGLWidget ()
{
  if (program != NULL)
    delete program;
}

void MyGLWidget::initializeGL ()
{
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();  

  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  glEnable(GL_DEPTH_TEST); // NOMES UN COP! En paintGL() molt incorrecte
  carregaShaders();
  createBuffers();
  
  rotate = 0.0;
  scale = 1.0;
  
  calculaCapsaModel();
  calculaCapsaEscena();
  calculaCentreEscnea();
  calculaRadiEscena();
  
  perspectiva = true;
  ini_camera();
}

void MyGLWidget::ini_camera () 
{
  distancia = radi * 2.0;
  Znear = distancia - radi;
  Zfar = distancia + radi;
  raw = 1.0f;
  FOVini = 2.0 * asin(radi / distancia);
  FOV = FOVini;
  
  rav = 1;
  
  girTheta = float(M_PI/8.);
  girPsi = 0.0;
  
  projectTransform();
  viewTransform();
}

void MyGLWidget::paintGL () 
{
  glViewport (0, 0, width(), height()); // Aquesta crida no caldria perquè Qt la fa de forma automàtica amb aquests paràmetres
  
  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glBindVertexArray(VAO_Patricio);
  modelTransformPatricio1();
  glDrawArrays(GL_TRIANGLES, 0, Patricio.faces().size()*3);
  modelTransformPatricio2();
  glDrawArrays(GL_TRIANGLES, 0, Patricio.faces().size()*3);
  modelTransformPatricio3();
  glDrawArrays(GL_TRIANGLES, 0, Patricio.faces().size()*3);
  
  glBindVertexArray(VAO_Terra);
  modelTransformTerra (); // Carreguem la transformació de model
  glDrawArrays(GL_TRIANGLES, 0, 6);
  
  glBindVertexArray (0);
}

void MyGLWidget::resizeGL (int w, int h) 
{
	float rav = float(w) / float(h);
		if (persepectiva) {
		raw = rav;
		if (rav < 1.0) FOV = 2.0*atan(tan(FOVini/2.0)/rav);
	}
	else {
		float aw = hw;
		
		if(rav > 1) {
			
			float hw = 2*radi;
			float a1w = rav * hw;
			float inc_a = a1w - aw;
			
		}
		else if(rav < 1) {
			
		}
	}
	projectTransform ();
	glViewport(0, 0, w, h);
}

void MyGLWidget::modelTransformTerra () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::scale(transform, glm::vec3(scale));
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::modelTransformPatricio1 () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::rotate(transform, rotate, glm::vec3(0.0, 1.0, 0.0));
  transform = glm::scale(transform, glm::vec3(scale));
  transform = glm::translate(transform, glm::vec3(2., 0., 2.));
  transform = glm::scale(transform, glm::vec3(escala));
  transform = glm::translate(transform, -centreBasePatricio);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::modelTransformPatricio2 () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::rotate(transform, rotate+float(M_PI/2.0), glm::vec3(0.0, 1.0, 0.0));
  transform = glm::scale(transform, glm::vec3(scale));
  transform = glm::scale(transform, glm::vec3(escala));
  transform = glm::translate(transform, -centreBasePatricio);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::modelTransformPatricio3 () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::rotate(transform, rotate+float(M_PI), glm::vec3(0.0, 1.0, 0.0));
  transform = glm::scale(transform, glm::vec3(scale));
  transform = glm::translate(transform, glm::vec3(2., 0., 2.));
  transform = glm::scale(transform, glm::vec3(escala));
  transform = glm::translate(transform, -centreBasePatricio);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}


void MyGLWidget::projectTransform () 
{
	glm::mat4 Proj;
	if (perspectiva)
		Proj = glm::perspective (FOV, raw, Znear, Zfar);
	else
		Proj = glm::ortho(-radi * rav, radi * rav, -radi, radi, Znear, Zfar);
		//Proj = glm::ortho(left, right, bottom, top, Znear, Zfar);
	
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::viewTransform () 
{
	glm::mat4 View(1.0);
	View = glm::translate(View, glm::vec3(0., 0., -distancia));
	View = glm::rotate(View, girTheta, glm::vec3(1., 0., 0.));
	View = glm::rotate(View, -girPsi, glm::vec3(0., 1., 0.));
	View = glm::translate(View, -centreEscena);
	glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
	
}

void MyGLWidget::createBuffers () 
{
  // Patricio
  Patricio.load("../../models/Patricio.obj");
  
  // Creació del Vertex Array Object per pintar
  glGenVertexArrays(1, &VAO_Patricio);
  glBindVertexArray(VAO_Patricio);
  
  GLuint VBO_PatricioPos;
  glGenBuffers(1, &VBO_PatricioPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatricioPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*Patricio.faces().size()*3*3, 
				Patricio.VBO_vertices(), GL_STATIC_DRAW);
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);
  
  GLuint VBO_PatricioCol;
  glGenBuffers(1, &VBO_PatricioCol);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatricioCol);
  glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*Patricio.faces().size()*3*3, 
				Patricio.VBO_matdiff(), GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);				
  
  
  //Terra
  glm::vec3 posicio[6] = {
	glm::vec3(2.5, 0, 2.5),
	glm::vec3(2.5, 0, -2.5),
	glm::vec3(-2.5, 0, -2.5),
	
	glm::vec3(2.5, 0, 2.5),
	glm::vec3(-2.5, 0, -2.5),
	glm::vec3(-2.5, 0, 2.5)
  }; 
   glm::vec3 color[6] = {
	glm::vec3(1,0,0),
	glm::vec3(0,0,1),
	glm::vec3(0,1,0),
	
	glm::vec3(1,0,0),
	glm::vec3(0,1,0),
	glm::vec3(0,0,1),
  };
  
  glGenVertexArrays(1, &VAO_Terra);
  glBindVertexArray(VAO_Terra);
  
  GLuint VBO_TerraPos;
  glGenBuffers(1, &VBO_TerraPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(posicio), posicio, GL_STATIC_DRAW);
  
  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);
  
  GLuint VBO_TerraCol;
  glGenBuffers(1, &VBO_TerraCol);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraCol);
  glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);
  
  
  glBindVertexArray (0);
}

void MyGLWidget::carregaShaders()
{
  // Creem els shaders per al fragment shader i el vertex shader
  QOpenGLShader fs (QOpenGLShader::Fragment, this);
  QOpenGLShader vs (QOpenGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem
  fs.compileSourceFile("shaders/fragshad.frag");
  vs.compileSourceFile("shaders/vertshad.vert");
  // Creem el program
  program = new QOpenGLShaderProgram(this);
  // Li afegim els shaders corresponents
  program->addShader(&fs);
  program->addShader(&vs);
  // Linkem el program
  program->link();
  // Indiquem que aquest és el program que volem usar
  program->bind();

  // Obtenim identificador per a l'atribut “vertex” del vertex shader
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
  // Obtenim identificador per a l'atribut “color” del vertex shader
  colorLoc = glGetAttribLocation (program->programId(), "color");
  // Uniform locations
  transLoc = glGetUniformLocation(program->programId(), "TG");
  projLoc = glGetUniformLocation(program->programId(), "proj");
  viewLoc = glGetUniformLocation(program->programId(), "view");
}

void MyGLWidget::calculaCapsaModel ()
{
  // Càlcul capsa contenidora i valors transformacions inicials
  float minx, miny, minz, maxx, maxy, maxz;
  minx = maxx = Patricio.vertices()[0];
  miny = maxy = Patricio.vertices()[1];
  minz = maxz = Patricio.vertices()[2];
  for (unsigned int i = 3; i < Patricio.vertices().size(); i+=3)
  {
    if (Patricio.vertices()[i+0] < minx)
      minx = Patricio.vertices()[i+0];
    if (Patricio.vertices()[i+0] > maxx)
      maxx = Patricio.vertices()[i+0];
    if (Patricio.vertices()[i+1] < miny)
      miny = Patricio.vertices()[i+1];
    if (Patricio.vertices()[i+1] > maxy)
      maxy = Patricio.vertices()[i+1];
    if (Patricio.vertices()[i+2] < minz)
      minz = Patricio.vertices()[i+2];
    if (Patricio.vertices()[i+2] > maxz)
      maxz = Patricio.vertices()[i+2];
  }
  
  /*
  std::cout << std::endl << 
  "MIN(x,y,z) = (" << minx << "," << miny << "," << minz << ")" << std::endl <<
  "MAX(x,y,z) = (" << maxx << "," << maxy << "," << maxz << ")" << std::endl;
  */
  escala = 1.0/(maxy-miny);
  centreBasePatricio= glm::vec3((minx+maxx)/2, miny, (minz+maxz)/2);
  escenaMaxima.y = 1.0;
}

void MyGLWidget::calculaCapsaEscena ()
{
  escenaMaxima.x = 2.5;
  escenaMaxima.z = 2.5;
  
  escenaMinima = glm::vec3(-2.5, 0.0, -2.5); 
}

void MyGLWidget::calculaRadiEscena ()
{
  radi = distance(escenaMinima, escenaMaxima)/2.0;
  /*
  std::cout << "Radi: " << radi << std::endl;
  */
}

void MyGLWidget::calculaCentreEscnea ()
{
  centreEscena = (escenaMaxima + escenaMinima);
  centreEscena = centreEscena / glm::vec3(2.0);
  /*
  std::cout << "Centre Escena: (" << centreEscena[0] << ","
								 << centreEscena[1] << ","
								 << centreEscena[2] << ")" << std::endl; 
  */
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) 
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: { // escalar a més gran
      scale += 0.05;
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      scale -= 0.05;
      break;
    }
    case Qt::Key_R: {
		rotate += float(M_PI)/4.0f;
		break;
	}
	case Qt::Key_Z: {
		FOV -= 0.1;
		projectTransform();
		break;
	}
	case Qt::Key_X: {
		FOV += 0.1;
		projectTransform();
		break;
	}
	case Qt::Key_O: {
		perspectiva = !perspectiva;
		projectTransform();
		break;
	}
	
    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e) {
	makeCurrent();
	
	if(e->x() > x_ant) girPsi -= 0.03;
	else if(e->x() < x_ant) girPsi += 0.03;
	
	if(e->y() > y_ant) girTheta -= 0.03;
	else if(e->y() < y_ant) girTheta += 0.03;
	
	x_ant = e->x();
	y_ant = e->y();
	viewTransform();
	update();
}
