#include "Model.h"

Model::Model(QObject *parent) : QObject(parent)
{
    statusInit();
}

Model::Status Model::status()
{
    QReadLocker locker(&m_lock);
    return m_status;
}

void Model::statusInit()
{
    m_status.isCited = false;
}
