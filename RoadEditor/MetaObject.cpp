#include "MetaObject.h"

MetaObject::MetaObject(QObject *parent) : QObject(parent)
{
    initProperty();
}

Model *MetaObject::model()
{
    return m_pModel;
}

void MetaObject::citeModel(QSharedPointer<Model *> model)
{
    if(m_pModel != nullptr)
        m_pModel->
}

void MetaObject::initProperty()
{
    m_pModel = nullptr;
}
