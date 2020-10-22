#include "FileOpsMenu.h"
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include "../Common/Common.h"

FileOpsMenu::FileOpsMenu(QMenu *parent) : QMenu(parent)
{
    m_processThread = new QThread(nullptr);
    m_processFunc.moveToThread(m_processThread);
    m_processThread->start();
    setTitle("文件");
    m_pModelLoading.setText("加载模型");
    m_pSaveCurrent.setText("保存当前");
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
    //定义文件对话框类
    QFileDialog *fileDialog = new QFileDialog(this);
    //定义文件对话框标题
    fileDialog->setWindowTitle(QStringLiteral("选择模型文件"));
    //设置默认文件路径
    fileDialog->setDirectory(".");
    //设置文件过滤器
    fileDialog->setNameFilter(tr("File(*.*)"));
    //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //打印所有选择的文件的路径
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
    DEBUG(QThread::currentThreadId() << paths);
}
