#include "Model.h"
#include "../Common/Common.h"
Model::Model(QString mid ,QObject *parent) : QObject(parent),m_name(mid)
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

QString Model::name()
{
    return m_name;
}

void Model::statusInit()
{
    m_status.isCited = false;
}

