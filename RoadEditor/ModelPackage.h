#ifndef MODELPACKAGE_H
#define MODELPACKAGE_H

#include <QObject>
#include <QHash>
#include "Model.h"
#include <QReadWriteLock>
#include <QSharedPointer>

class ModelPackage:public QObject
{
    Q_OBJECT
public:
   explicit ModelPackage(QObject * parent = nullptr);
   ~ModelPackage();
   bool appendModel(const QString &mid, Model *model);//增加模型对象
   const QSharedPointer<Model*> selectModel(const QString &mid);//查询model
   QSharedPointer<Model *> takeModel(const QString &mid);//删除模型对象
private:
    QReadWriteLock m_lock;
    QString m_packageName;
    QHash<QString, QSharedPointer<Model *>> m_modelHash;
};

#endif // MODELPACKAGE_H
