#include <QApplication>
#include "PluginLoader.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    PluginLoader lt;
    lt.setProperty("path","C:\\Users\\ASUS\\Desktop\\QtOpenGl\\build\\debug\\RoadEditor.dll");
    //w.show();

    lt.start();
///while(1);
    //QObject * pRoadEditor =
    //loadPlugin(QString::fromLocal8Bit("C:\\Users\\Administrator\\Desktop\\QtOpenGL\\build\\debug\\RoadEditor.dll"));
    //loadPlugin(QString::fromLocal8Bit("C:\\Users\\ASUS\\Desktop\\QtOpenGl\\build\\debug\\RoadEditor.dll"));
//    if(pRoadEditor)
//    {
//        RoadEditorInterface *pIf = qobject_cast<RoadEditorInterface *>(pRoadEditor);

//        pIf->openRoadEditor(&w);
//      //  w.AddWidget_LayoutTop(pIf->modelWindow());
//        w.AddWidget_LayoutLeft(pIf->sceneWindow());
//        w.AddWidget_LayoutRight(pIf->propertyWindow());
//        w.AddWidget_LayoutCentre(pIf->viewWindow());
//        w.setMenueBar(pIf->menus());
//        pIf->sayHellow();
//    }
    return a.exec();
}


