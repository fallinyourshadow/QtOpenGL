#ifndef QPLUGINLOADERTHREAD_H
#define QPLUGINLOADERTHREAD_H
#include "MainWindow.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QPluginLoader>
#include <QThread>
#include "../RoadEditor/RoadEditor_global.h"

class  PluginLoader: public QThread
{
    Q_OBJECT
signals:
    void loadDone(QObject * plugin);


public:
    PluginLoader(){
        w = new MainWindow(nullptr);
        w->show();
        connect(this,&PluginLoader::loadDone,this,&PluginLoader::on_loadDone);
    }
    ~PluginLoader()
    {
       delete w;
    }
    virtual void run(){
        QString path = property("path").value<QString>();
        Q_EMIT loadDone(loadPlugin(path));
    }
    void on_loadDone(QObject * plugin){
        if(nullptr != plugin)
        {
            RoadEditorInterface *pIf = qobject_cast<RoadEditorInterface *>(plugin);
            pIf->openRoadEditor(nullptr);
            w->AddWidget_LayoutLeft(pIf->sceneWindow());
            w->AddWidget_LayoutRight(pIf->propertyWindow());
            w->AddWidget_LayoutCentre(pIf->viewWindow());
            w->setMenueBar(pIf->menus());
            pIf->sayHellow();
        }
    }

    QObject* loadPlugin(QString pluginPath)
    {
        QObject *interface = nullptr;
        QFile pluginFile(pluginPath);
        if(!pluginFile.exists())
        {
            qDebug() << __FUNCDNAME__ << pluginPath;
            QMessageBox::warning(nullptr,QString::fromLocal8Bit( "warning"),QString::fromLocal8Bit("dll not fund"));
        }
        else
        {
            QPluginLoader loader(pluginPath);
            QObject *pluginInstance = loader.instance();
            if(pluginInstance)
            {
                qDebug() << __FUNCDNAME__ << pluginInstance;
                interface = pluginInstance;
            }
            // loader.dumpObjectInfo();
            //qDebug() << __FUNCDNAME__ << loader.unload();
        }
        return interface;
    }
private:
    MainWindow * w;
};


#endif // QPLUGINLOADERTHREAD_H
