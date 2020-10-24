#include "MetaObject.h"
#include "../Common/Common.h"
MetaObject::MetaObject(QObject *parent) :
    QObject(parent),
    m_pModel(),
    m_objectType(META_OBJECT)
{
    initProperty();
}

QWeakPointer<Model *> MetaObject::model()
{
    return m_pModel;
}

void MetaObject::citeModel(QSharedPointer<Model *> &model)
{
    m_pModel.clear();
    m_pModel = model.toWeakRef();
}

void MetaObject::removeModel()
{
    m_pModel.clear();
}

//QStandardItem *MetaObject::item()
//{
//    return m_pItem;
//}

void MetaObject::initProperty()
{

    m_pModel.clear();
}

void MetaObject::hellow()
{
    DEBUG("HELLOW");
}

MetaObject::ObjectType MetaObject::objectType()
{
    return  m_objectType;
}



void MetaObject::setObjectType(ObjectType type)
{
    m_objectType = type;
}
