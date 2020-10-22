#include "RoadEditor.h"

RoadEditor::RoadEditor()
{

}

RoadEditor::~RoadEditor()
{
    QMenu * var;
    foreach (var, m_menus) {
        if(var)
            delete var;
    }
}

QObject * RoadEditor::openRoadEditor(QWidget *parent)
{
    setParent(parent);
    m_pViewWindow = new ViewWindow(parent);
    m_pSceneWindow = new SceneWindow(parent);
    m_pPropertyWindow = new PropertyWindow(parent);
    createMenus();
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

//QWidget *RoadEditor::modelWindow()
//{
//    return m_pModelWindow;
//}

QWidget *RoadEditor::sceneWindow()
{
    return m_pSceneWindow;
}

QWidget *RoadEditor::propertyWindow()
{
    return m_pPropertyWindow;
}

QList<QMenu *> RoadEditor::menus()
{
    return m_menus;
}

void RoadEditor::createMenus()
{
    FileOpsMenu * pFileOpsMenu = new FileOpsMenu(nullptr);
    m_menus.append(pFileOpsMenu);

}


