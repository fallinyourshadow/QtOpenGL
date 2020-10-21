#include "RoadEditor.h"

QObject * RoadEditor::openRoadEditor(QWidget *parent)
{
    setParent(parent);
    m_pModelWindow = new ModelWindow(parent);
    m_pViewWindow = new ViewWindow(parent);
    m_pSceneWindow = new SceneWindow(parent);
    m_pPropertyWindow = new PropertyWindow(parent);
    return this;
}

void RoadEditor::sayHellow()
{
    qDebug() << "hello";
}

QWidget *RoadEditor::viewWindow()
{
    return m_pViewWindow;
}

QWidget *RoadEditor::modelWindow()
{
    return m_pModelWindow;
}

QWidget *RoadEditor::sceneWindow()
{
    return m_pSceneWindow;
}

QWidget *RoadEditor::propertyWindow()
{
    return m_pPropertyWindow;
}


