#include "ModelPackage.h"

ModelPackage::ModelPackage(const QString &name, QObject *parent):QObject(parent)
{
    m_packageName = name;
}

ModelPackage::~ModelPackage()
{
   Model * v;
    foreach(v,m_modelHash)
    {
        delete v;
    }
}

bool ModelPackage::appendModel(const QString &mid, Model *model)
{
    QWriteLocker locker(&m_lock);
    if(m_modelHash.contains(mid))//如果已经包含返回false
        return false;
    m_modelHash.insert(mid,model);
    return true;
}

Model *ModelPackage::selectModel(const QString &mid)
{
    QReadLocker locker(&m_lock);
    if(!m_modelHash.contains(mid))//如果没有找到返回空
        return nullptr;
    return m_modelHash.value(mid);
}

Model * ModelPackage::takeModel(const QString &mid)
{
    QWriteLocker locker(&m_lock);
    if(!m_modelHash.contains(mid))//如果不包含返回false
        return nullptr;
    return m_modelHash.take(mid);//删除
}

int ModelPackage::modelSize()
{
    QReadLocker locker(&m_lock);
    return m_modelHash.size();
}

QString ModelPackage::name()
{
    return m_packageName;
}

const QHash<QString, Model *> ModelPackage::modelPackage()
{
    QReadLocker locker(&m_lock);
    return m_modelHash;
}
