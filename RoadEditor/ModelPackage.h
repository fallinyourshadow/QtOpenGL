#ifndef MODELPACKAGE_H
#define MODELPACKAGE_H

#include <QObject>
#include <QHash>
#include "Model.h"
#include <QReadWriteLock>
class ModelPackage:public QObject
{
    Q_OBJECT
public:
   explicit ModelPackage(QObject * parent);
   bool appendModel(const QString &mid, Model* model);//增加模型对象
   Model* selectModel(const QString &mid);//查询model
   bool deleteModel(const QString &mid);//删除模型对象
private:
    QReadWriteLock m_lock;
    QString m_pid;
    QHash<QString, Model*> m_modelHash;
};

#endif // MODELPACKAGE_H
