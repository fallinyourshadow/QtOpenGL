#include "MainWindow.h"
#include "../RoadEditor/RoadEditor_global.h"
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QPluginLoader>

QObject* loadPlugin(QString pluginPath);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QObject * pRoadEditor =
    loadPlugin(QString::fromLocal8Bit("C:\\Users\\Administrator\\Desktop\\QtOpenGL\\build\\debug\\RoadEditor.dll"));
    //loadPlugin(QString::fromLocal8Bit("C:\\Users\\ASUS\\Desktop\\QtOpenGl\\QtOpenGl\\build\\debug\\RoadEditor.dll"));
    if(pRoadEditor)
    {
        RoadEditorInterface *pIf = qobject_cast<RoadEditorInterface *>(pRoadEditor);

        pIf->openRoadEditor(&w);
      //  w.AddWidget_LayoutTop(pIf->modelWindow());
        w.AddWidget_LayoutLeft(pIf->sceneWindow());
        w.AddWidget_LayoutRight(pIf->propertyWindow());
        w.AddWidget_LayoutCentre(pIf->viewWindow());
        w.setMenueBar(pIf->menus());
        pIf->sayHellow();
    }
    return a.exec();
}

QObject* loadPlugin(QString pluginPath)
{
    QObject *interface = nullptr;
    QFile pluginFile(pluginPath);
    if(!pluginFile.exists())
    {
        qDebug() << __FUNCDNAME__ << pluginPath;
        QMessageBox::warning(nullptr,"警告","找不到指定的插件");
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
