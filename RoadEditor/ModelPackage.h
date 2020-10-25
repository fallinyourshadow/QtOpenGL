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
   explicit ModelPackage(const QString &name, QObject * parent = nullptr);
   ~ModelPackage();
   bool appendModel(const QString &mid, Model *model);//增加模型对象
   Model *selectModel(const QString &mid);//查询model
   Model * takeModel(const QString &mid);//删除模型对象
   int modelSize();
   QString name();
   const QHash<QString, Model *> modelPackage();
private:
    QReadWriteLock m_lock;
    QString m_packageName;
    QHash<QString, Model *> m_modelHash;
};

#endif // MODELPACKAGE_H
