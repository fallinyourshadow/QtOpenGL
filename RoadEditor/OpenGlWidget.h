#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QBasicTimer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

//绘制场景窗口
class OpenGlWidget :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGlWidget(QWidget *parent = nullptr);
    ~OpenGlWidget();
protected:
    void mousePressEvent(QMouseEvent *e) override;//鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *e) override;//鼠标释放事件
    void timerEvent(QTimerEvent *e) override;//定时事件
    void initializeGL() override;//重写opgl初始化
    void resizeGL(int w, int h) override;//改变大小
    void paintGL() override;
private:
    QBasicTimer timer;
    QMatrix4x4 projection;//透视

};

#endif // OPENGLWIDGET_H
