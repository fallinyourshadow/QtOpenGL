#ifndef SCENEWINDOW_H
#define SCENEWINDOW_H

#include <QWidget>

namespace Ui {
class SceneWindow;
}

class SceneWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SceneWindow(QWidget *parent = nullptr);
    ~SceneWindow();

private:
    Ui::SceneWindow *ui;
};

#endif // SCENEWINDOW_H
