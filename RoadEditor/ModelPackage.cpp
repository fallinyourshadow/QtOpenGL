#include "ModelPackage.h"

ModelPackage::ModelPackage(QObject *parent):QObject(parent)
{

}

bool ModelPackage::appendModel(const QString &mid, Model *model)
{
    QWriteLocker locker(&m_lock);
    if(m_modelHash.contains(mid))
        return false;
    m_modelHash.insert(mid, model);
    return true;
}

Model *ModelPackage::selectModel(const QString &mid)
{
    QReadLocker locker(&m_lock);
    if(!m_modelHash.contains(mid))
        return nullptr;
    return m_modelHash.value(mid);
}

bool ModelPackage::deleteModel(const QString &mid)
{
    QWriteLocker locker(&m_lock);
    if(!m_modelHash.contains(mid))//如果不包含
        return false;
    if(m_modelHash.value(mid)->status().isCited)//如果正在被引用
        return false;
    m_modelHash.remove(mid);//删除
    return true;
}
