#include "ModelPackage.h"

ModelPackage::ModelPackage(QObject *parent):QObject(parent)
{

}

ModelPackage::~ModelPackage()
{
    QSharedPointer<Model *> v;
    foreach(v,m_modelHash)
    {
        v.clear();
    }
}

bool ModelPackage::appendModel(const QString &mid, Model *model)
{
    QWriteLocker locker(&m_lock);
    if(m_modelHash.contains(mid))//如果已经包含返回false
        return false;
    QSharedPointer<Model *> shared_model;
    shared_model.reset(&model);
    m_modelHash.insert(mid, shared_model);
    return true;
}

const QSharedPointer<Model *> ModelPackage::selectModel(const QString &mid)
{
    QReadLocker locker(&m_lock);
    if(!m_modelHash.contains(mid))//如果没有找到返回空
        return nullptr;
    return m_modelHash.value(mid);
}

QSharedPointer<Model *> ModelPackage::takeModel(const QString &mid)
{
    QWriteLocker locker(&m_lock);
    if(!m_modelHash.contains(mid))//如果不包含返回false
        return nullptr;
    return m_modelHash.take(mid);//删除
}
