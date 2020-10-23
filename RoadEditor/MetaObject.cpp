#include "MetaObject.h"

MetaObject::MetaObject(QObject *parent) :
    QObject(parent),
    m_pModel()
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

void MetaObject::initProperty()
{
    m_pModel.clear();
}
