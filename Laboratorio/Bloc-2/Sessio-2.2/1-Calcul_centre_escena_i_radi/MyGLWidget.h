#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "../../Model/model.h"

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

  private:
    void createBuffers ();
    void carregaShaders ();
    void modelTransformTerra ();
    void modelTransformHomerProves ();
    void projectTransform ();
    void viewTransform ();
    void ini_camera ();
    void calculaCapsaModel ();
    void calculaCapsaEscena ();
    void calculCentreEscnea ();
    void calculRadiEscena ();

    // attribute locations
    GLuint vertexLoc, colorLoc;
    // uniform locations
    GLuint transLoc, projLoc, viewLoc;
    // VAO names
    //GLuint VAO_Casa;
    GLuint  VA0_HomerProves, VA1_Terra;
    // Program
    QOpenGLShaderProgram *program;
    // Internal vars
    float scale, rotate, FOV, raw, Znear, Zfar;
    float radi;
    
    glm::vec3 pos, OBS, VRP, UP, centreEscena;
    glm::vec3 escenaMinima, escenaMaxima;
    
    Model HomerProves;
};

