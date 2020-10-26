#include "SceneWindowMenu.h"
#include "../Common/Common.h"
SceneWindowMenu::SceneWindowMenu(QMenu *parent) : QMenu(parent)
{
    m_addScene.setText("add scene");
    m_addObject.setText("add object");
    m_delCurScene.setText("delete scene");
    m_delCurObject.setText("delete object");
    addAction(&m_addScene);
    addAction(&m_addObject);
    addAction(&m_delCurScene);
    addAction(&m_delCurObject);
}

void SceneWindowMenu::showSceneMenu()
{
    addAction(&m_addScene);
    addAction(&m_addObject);
    addAction(&m_delCurScene);
    removeAction(&m_delCurObject);
}

void SceneWindowMenu::showObjectMenu()
{
    removeAction(&m_addScene);
    removeAction(&m_addObject);
    removeAction(&m_delCurScene);
    addAction(&m_delCurObject);
}

const QAction *SceneWindowMenu::addScene()
{
    return  &m_addScene;
}

const QAction *SceneWindowMenu::addObject()
{
    return &m_addObject;
}

const QAction *SceneWindowMenu::delCurObject()
{
    return &m_delCurObject;
}

const QAction *SceneWindowMenu::delCurScene()
{
    return &m_delCurScene;
}

void SceneWindowMenu::showTopSceneMenu()
{
    addAction(&m_addScene);
    addAction(&m_addObject);
    removeAction(&m_delCurScene);
    removeAction(&m_delCurObject);

}
