#include "FileOpsMenu.h"
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include "../Common/Common.h"
#include "SourcePackageManager.h"
FileOpsMenu::FileOpsMenu(QMenu *parent) : QMenu(parent)
{
    m_processThread = new QThread(nullptr);
    m_processFunc.moveToThread(m_processThread);
    m_processThread->start();
    setTitle(LOC("file"));

    m_pModelLoading.setText(LOC("load model"));
    //
    // m_pSaveCurrent.setText("保存当前");
    addAction(&m_pModelLoading);
    addAction(&m_pSaveCurrent);
    connect(&m_pModelLoading,
            &QAction::triggered,
            this,
            &FileOpsMenu::on_modelLoadingTriggered);
    connect(this,
            &FileOpsMenu::modelLoading,
            &m_processFunc,
            &FileProcess::on_modelLoading);

    DEBUG(QThread::currentThreadId());
    //DEBUG("");
}

FileOpsMenu::~FileOpsMenu()
{
    m_processThread->requestInterruption();
    m_processThread->wait(100);
    m_processThread->quit();
    DEBUG(m_processThread->isRunning());
    //m_processThread->exit();
    delete m_processThread;
}



void FileOpsMenu::on_modelLoadingTriggered(bool click)
{
    Q_UNUSED(click)
    //定?文件??框?
    QFileDialog *fileDialog = new QFileDialog(this);
    //定?文件??框??
    fileDialog->setWindowTitle(LOC("load model"));
    //?置默?文件路径
    fileDialog->setDirectory(".");
    //?置文件??器
    fileDialog->setNameFilter(LOC("File(*.*)"));
    //?置可以??多个文件,默??只能??一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    //?置??模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //打印所有??的文件的路径
    QStringList fileNames;

    if (fileDialog->exec()) {
        fileNames = fileDialog->selectedFiles();

    }
    QString v;
    Q_EMIT modelLoading(fileNames);
}

FileProcess::FileProcess(QObject *parent):QObject(parent)
{

}

void FileProcess::on_modelLoading(QStringList paths)
{
    if(QThread::currentThread()->isInterruptionRequested())
        return;
    SourcePackageManager manager;
    ModelPackage * package = new ModelPackage("default");//创建一个模型资源包
    manager.appendModelPackage("default",package);//命名为"default"
    QString v;
    int i = 0;
    foreach(v,paths)
    {
        Model *model = new Model(QString(i++));
        if(!model->loading(v))//如果加载失败
        {
            --i;
            delete model;
        }
        else
        {
            package->appendModel(QString(i), model);
        }
    }
   // DEBUG(QThread::currentThreadId() << paths);
}
