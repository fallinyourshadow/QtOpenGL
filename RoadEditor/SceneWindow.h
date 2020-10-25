#ifndef SCENEWINDOW_H
#define SCENEWINDOW_H

#include <QWidget>
#include "SourceTreeView.h"

namespace Ui {
class SceneWindow;
}

class SceneWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SceneWindow(QWidget *parent = nullptr);
    ~SceneWindow();
    SourceTreeView * treeView();

private:
    Ui::SceneWindow *ui;
};

#endif // SCENEWINDOW_H
