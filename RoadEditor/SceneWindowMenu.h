#ifndef SCENEWINDOWMENU_H
#define SCENEWINDOWMENU_H

#include <QObject>
#include <QMenu>

class SceneWindowMenu : public QMenu
{
    Q_OBJECT
public:
    explicit SceneWindowMenu(QMenu *parent = nullptr);
    void showTopSceneMenu();
    void showSceneMenu();
    void showObjectMenu();
    const QAction * addScene();
    const QAction * addObject();
    const QAction * delCurObject();
    const QAction * delCurScene();
signals:
private:
    QAction m_addScene;
    QAction m_addObject;

    QAction m_delCurObject;
    QAction m_delCurScene;

};

#endif // SCENEWINDOWMENU_H
