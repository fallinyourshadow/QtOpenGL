#ifndef ROADEDITOR_H
#define ROADEDITOR_H
#include <QDebug>
#include <QThread>
#include "RoadEditor_global.h"


#include "PropertyWindow.h"
#include "SceneWindow.h"
#include "ViewWindow.h"
#include "FileOpsMenu.h"

class ROADEDITOR_EXPORT RoadEditor:
    public QObject,
    public RoadEditorInterface

{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PLUGIN_INTERFACE_IID FILE "RoadEditor.json")//plugin's meta data. note: the JSON file is necessary，if you used this macro.
    Q_INTERFACES(RoadEditorInterface)
public:
    RoadEditor();
    virtual ~RoadEditor() Q_DECL_OVERRIDE;
    virtual QObject * openRoadEditor(QWidget *parent) Q_DECL_OVERRIDE;
    virtual void sayHellow() Q_DECL_OVERRIDE;
    virtual QWidget * viewWindow() Q_DECL_OVERRIDE;
    //virtual QWidget * modelWindow() Q_DECL_OVERRIDE;
    virtual QWidget * sceneWindow() Q_DECL_OVERRIDE;
    virtual QWidget * propertyWindow() Q_DECL_OVERRIDE;
    virtual QList<QMenu *> menus() Q_DECL_OVERRIDE;
protected:
    void createMenus();
private:
    //ModelWindow * m_pModelWindow;
    PropertyWindow * m_pPropertyWindow;
    ViewWindow * m_pViewWindow;
    SceneWindow * m_pSceneWindow;
    QList<QMenu *> m_menus;

};

#endif // ROADEDITOR_H
