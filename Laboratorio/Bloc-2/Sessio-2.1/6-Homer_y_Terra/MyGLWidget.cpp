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
  carregaShaders();
  createBuffers();
  glEnable(GL_DEPTH_TEST); // NOMES UN COP! En paintGL() molt incorrecte
  
  scale = 1.0f;
  rotate = 0.0f;
  ini_camera();
}

void MyGLWidget::paintGL () 
{
  glViewport (0, 0, width(), height()); // Aquesta crida no caldria perquè Qt la fa de forma automàtica amb aquests paràmetres
  
  modelTransformHomer (); // Carreguem la transformació de model (rotacio)
  
  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glBindVertexArray(VA0_HomerProves);
  glDrawArrays(GL_TRIANGLES, 0, HomerProves.faces().size()*3);
  
  modelTransformTerra (); // Carreguem la transformació de model
  
  glBindVertexArray(VA1_Terra);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  
  glBindVertexArray (0);
}

void MyGLWidget::modelTransformTerra () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::scale(transform, glm::vec3(scale));
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::modelTransformHomer () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::scale(transform, glm::vec3(scale));
  transform = glm::rotate(transform, rotate, glm::vec3(0.0, 1.0, 0.0));
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::ini_camera () 
{
  FOV = float(M_PI)/2.0f;
  raw = 1.0f;
  Znear = 0.4f;
  Zfar = 3.0f;
  projectTransform();
  
  OBS = glm::vec3(0,0,1);
  VRP = glm::vec3(0,0,0);
  UP = glm::vec3(0,1,0);
  viewTransform();
}

void MyGLWidget::projectTransform () 
{
	//glm::perspective (FOV en radians, ra window, Znear, Zfar);
	glm::mat4 Proj = glm::perspective (FOV, raw, Znear, Zfar);
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::viewTransform () 
{
	//glm::lookAt(OBS, VRP, UP);
	glm::mat4 View = glm::lookAt (OBS, VRP, UP);
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::resizeGL (int w, int h) 
{
  // Aquí anirà el codi que cal fer quan es redimensiona la finestra
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
    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::createBuffers () 
{
  // HomerProves
  HomerProves.load("../../models/HomerProves.obj");
  
  // Creació del Vertex Array Object per pintar
  glGenVertexArrays(1, &VA0_HomerProves);
  glBindVertexArray(VA0_HomerProves);
  
  GLuint VB0_HomerProvesPos;
  glGenBuffers(1, &VB0_HomerProvesPos);
  glBindBuffer(GL_ARRAY_BUFFER, VB0_HomerProvesPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*HomerProves.faces().size()*3*3, 
				HomerProves.VBO_vertices(), GL_STATIC_DRAW);
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);
  
  GLuint VB0_HomerProvesCol;
  glGenBuffers(1, &VB0_HomerProvesCol);
  glBindBuffer(GL_ARRAY_BUFFER, VB0_HomerProvesCol);
  glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*HomerProves.faces().size()*3*3, 
				HomerProves.VBO_matdiff(), GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);				
  
  
  //Terra
  glm::vec3 posicio[6] = {
	glm::vec3(1.0, -1.0, 1.0),
	glm::vec3(1.0, -1.0, -1.0),
	glm::vec3(-1.0, -1.0, -1.0),
	
	glm::vec3(1.0, -1.0, 1.0),
	glm::vec3(-1.0, -1.0, -1.0),
	glm::vec3(-1.0, -1.0, 1.0)
  }; 
   glm::vec3 color[6] = {
	glm::vec3(1,0,0),
	glm::vec3(0,0,1),
	glm::vec3(0,1,0),
	
	glm::vec3(1,0,0),
	glm::vec3(0,1,0),
	glm::vec3(0,0,1),
  };
  
  glGenVertexArrays(1, &VA1_Terra);
  glBindVertexArray(VA1_Terra);
  
  GLuint VB0_TerraPos;
  glGenBuffers(1, &VB0_TerraPos);
  glBindBuffer(GL_ARRAY_BUFFER, VB0_TerraPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(posicio), posicio, GL_STATIC_DRAW);
  
  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);
  
  GLuint VB0_TerraCol;
  glGenBuffers(1, &VB0_TerraCol);
  glBindBuffer(GL_ARRAY_BUFFER, VB0_TerraCol);
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
