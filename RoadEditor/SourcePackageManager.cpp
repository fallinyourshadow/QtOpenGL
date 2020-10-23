#include "SourcePackageManager.h"

QMultiHash<QString, QSharedPointer<ModelPackage *>> SourcePackageManager::s_modelPackageHash;

SourcePackageManager::SourcePackageManager(QObject *parent) : QObject(parent)
{

}

void SourcePackageManager::appendModelPackage(const QString &packageName,  ModelPackage *package)
{
    QWriteLocker locker(&m_lock);
    QSharedPointer<ModelPackage *> share_package;
    share_package.reset(&package);
    s_modelPackageHash.insertMulti(packageName, share_package);//复制一个指针的引用
}

QList<QSharedPointer<ModelPackage *>> SourcePackageManager::selectModelPackage(const QString &packageName)
{
    QReadLocker locker(&m_lock);
    return s_modelPackageHash.values(packageName);//根据键值查找
}

int SourcePackageManager::removeModelPackage(const QString &packageName)
{
    QWriteLocker locker(&m_lock);
    QList<QSharedPointer<ModelPackage *>> temp = selectModelPackage(packageName);
    if(0 == temp.size())
        return 0;
    QSharedPointer<ModelPackage *> v;
    foreach(v, temp)
    {
        v.clear();
    }
    return s_modelPackageHash.remove(packageName);//根据键值移除
}
