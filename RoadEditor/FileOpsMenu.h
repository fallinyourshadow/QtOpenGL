#ifndef FILEOPS_H
#define FILEOPS_H

#include <QObject>
#include <QAction>
#include <QMenu>
#include <QThread>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
class FileProcess : public QObject
{
    Q_OBJECT
public:
    explicit FileProcess(QObject *parent = nullptr);
public slots:
    void on_modelLoading(QStringList paths);
};

class FileOpsMenu : public QMenu
{
    Q_OBJECT
public:
    explicit FileOpsMenu(QMenu *parent = nullptr);
    ~FileOpsMenu();

signals:
    void modelLoading(QStringList paths);
public slots:
    void on_modelLoadingTriggered(bool click);
private:
    QAction m_pModelLoading;
    QAction m_pSaveCurrent;
    QThread * m_processThread;
    FileProcess m_processFunc;
};



#endif // FILEOPS_H
