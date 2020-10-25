#include "SourcePackageManager.h"
#include "../Common/Common.h"

QMultiHash<QString, ModelPackage *> * SourcePackageManager::s_modelPackageHash;

SourcePackageManager::SourcePackageManager(QObject *parent) : QObject(parent)
{
    s_modelPackageHash = new  QMultiHash<QString, ModelPackage *>;
}

void SourcePackageManager::appendModelPackage(const QString &packageName,  ModelPackage * packageAddr)
{
    QWriteLocker locker(&m_lock);
    //DEBUG_TITLE << package->name();
    s_modelPackageHash->insertMulti(packageName, packageAddr);//复制一个指针的引用
}

QList<ModelPackage *> SourcePackageManager::selectModelPackage(const QString &packageName)
{
    QReadLocker locker(&m_lock);
    return s_modelPackageHash->values(packageName);//根据键值查找
}

int SourcePackageManager::removeModelPackage(const QString &packageName)
{
    QWriteLocker locker(&m_lock);
    QList<ModelPackage *> temp = selectModelPackage(packageName);
    if(0 == temp.size())
        return 0;
    ModelPackage * v;
    foreach(v, temp)
    {
        delete v;
    }
    return s_modelPackageHash->remove(packageName);//根据键值移除
}
