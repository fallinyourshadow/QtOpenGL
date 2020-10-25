#include "MetaObject.h"
#include "../Common/Common.h"
MetaObject::MetaObject(QObject *parent) :
    QObject(parent),
    m_pModel(),
    m_objectType(META_OBJECT)
{

    initProperty();
}

MetaObject::~MetaObject()
{
    DEBUG_TITLE << "delete";

    //m_pModel.clear();
    //m_pModelPackage.clear();
}

Model * MetaObject::model()
{
    return m_pModel;
}

void MetaObject::citeModel(Model * model)
{
    m_pModel = model;
}

void MetaObject::removeModel()
{
    m_pModel = nullptr;
}

//QStandardItem *MetaObject::item()
//{
//    return m_pItem;
//}

void MetaObject::initProperty()
{
    m_pModelPackage = nullptr;
    m_pModel = nullptr;

}

void MetaObject::hellow()
{
    DEBUG("HELLOW");
}

MetaObject::ObjectType MetaObject::objectType()
{
    return  m_objectType;
}

ModelPackage * MetaObject::modelPackage()
{
     //QReadLocker locker(&m_lock);
    return m_pModelPackage;
}

bool MetaObject::citeModelPackage( class ModelPackage *package)
{
    //QWriteLocker locker(&m_lock);
    m_pModelPackage = package;

    return true;
}

void MetaObject::setObjectType(ObjectType type)
{
    m_objectType = type;
}
