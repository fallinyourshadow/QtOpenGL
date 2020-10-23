#include "Model.h"
#include "../Common/Common.h"
Model::Model(QObject *parent) : QObject(parent)
{
    statusInit();

}

Model::Status Model::status()
{
    QReadLocker locker(&m_lock);
    return m_status;
}

bool Model::loading(const QString &path)
{
    DEBUG(path);
    return true;
}

void Model::statusInit()
{
    m_status.isCited = false;
}

