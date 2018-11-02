#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "model.h"

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core 
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();

  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    // resizeGL - És cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);
    // keyPressEvent - Es cridat quan es prem una tecla
    virtual void keyPressEvent (QKeyEvent *event);
    
    virtual void mouseMoveEvent (QMouseEvent *e);

  private:
    void createBuffers ();
    void carregaShaders ();
    void modelTransformTerra ();
    void modelTransformPatricio1 ();
    void modelTransformPatricio2 ();
    void modelTransformPatricio3 ();
    void projectTransform ();
    void viewTransform ();
    void ini_camera ();
    void calculaCapsaModel ();
    void calculaCapsaEscena ();
    void calculaCentreEscnea ();
    void calculaRadiEscena ();

    // attribute locations
    GLuint vertexLoc, colorLoc;
    // uniform locations
    GLuint transLoc, projLoc, viewLoc;
    // VAO names
    //GLuint VAO_Casa;
    GLuint  VAO_Patricio, VAO_Terra;
    // Program
    QOpenGLShaderProgram *program;
    // Internal vars
    float scale, rotate, FOV, FOVini, raw, Znear, Zfar;
    float radi, distancia, escala, girTheta, girPsi, x_ant, y_ant;
    
    glm::vec3 pos, OBS, VRP, UP, centreEscena;
    glm::vec3 escenaMinima, escenaMaxima, centreBasePatricio;
    
    bool perspectiva;
    
    Model Patricio;
};

