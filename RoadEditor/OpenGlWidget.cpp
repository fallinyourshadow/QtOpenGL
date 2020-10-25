#include "OpenGlWidget.h"



OpenGlWidget::OpenGlWidget(QWidget *parent):
    QOpenGLWidget(parent)
{

}

void OpenGlWidget::setTopScene(Topscene *topScene)
{
    m_pTopScene = topScene;
}

OpenGlWidget::~OpenGlWidget()
{
    makeCurrent();
    doneCurrent();
}

void OpenGlWidget::mousePressEvent(QMouseEvent *e)
{

}

void OpenGlWidget::mouseReleaseEvent(QMouseEvent *e)
{

}

void OpenGlWidget::timerEvent(QTimerEvent *e)
{
    update();
}

void OpenGlWidget::initializeGL()
{
    initializeOpenGLFunctions();
    m_timer.start(12, this);
    //QOpenGLWidget::initializeGL();
}

void OpenGlWidget::resizeGL(int w, int h)
{
    // Calculate aspect ratio
    qreal aspect = qreal(w) / qreal(h ? h : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const qreal zNear = 3.0, zFar = 7.0, fov = 45.0;

    // Reset projection
    m_projection.setToIdentity();

    // Set perspective projection
    m_projection.perspective(fov, aspect, zNear, zFar);
}

void OpenGlWidget::paintGL()
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
