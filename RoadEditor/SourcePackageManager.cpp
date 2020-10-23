#include "SourcePackageManager.h"

SourcePackageManager::SourcePackageManager(QObject *parent) : QObject(parent)
{

}

void SourcePackageManager::appendModelPackage(const QString &key, ModelPackage *package)
{
    QWriteLocker locker(&m_lock);
    s_modelPackageHash.insertMulti(key,package);
}

QList<ModelPackage *> SourcePackageManager::selectModelPackage(const QString &pid)
{
    QReadLocker locker(&m_lock);
    return s_modelPackageHash.values(pid);
}

int SourcePackageManager::removeModelPackage(const QString &pid)
{
    QWriteLocker locker(&m_lock);
    return s_modelPackageHash.remove(pid);
}
