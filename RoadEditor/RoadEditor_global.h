#ifndef ROADEDITOR_GLOBAL_H
#define ROADEDITOR_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QObject>
#include <QWidget>
#if defined(ROADEDITOR_LIBRARY)
#  define ROADEDITOR_EXPORT Q_DECL_EXPORT
#else
#  define ROADEDITOR_EXPORT Q_DECL_IMPORT
#endif

class RoadEditorInterface
{
public:
    virtual ~RoadEditorInterface() {}
    virtual QObject * openRoadEditor(QWidget *parent) = 0;
    virtual void sayHellow() =0;
    virtual QWidget * viewWindow() = 0;
    virtual QWidget * modelWindow() = 0;
    virtual QWidget * sceneWindow() = 0;
    virtual QWidget * propertyWindow() =0;
};
#define PLUGIN_INTERFACE_IID "io.qt.RoadEditor"//plugin's iid
Q_DECLARE_INTERFACE(RoadEditorInterface,PLUGIN_INTERFACE_IID)//register plugin iid to qt meta object
#endif // ROADEDITOR_GLOBAL_H
