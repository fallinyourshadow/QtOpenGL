#ifndef SOURCEPACKAGEMANAGER_H
#define SOURCEPACKAGEMANAGER_H

#include <QObject>
#include <QMultiHash>
#include "ModelPackage.h"
#include <QReadWriteLock>

class SourcePackageManager : public QObject
{
    Q_OBJECT
public:
    explicit SourcePackageManager(QObject *parent = nullptr);

    void appendModelPackage(const QString &packageName, ModelPackage *packageAddr);//增
    QList<ModelPackage *> selectModelPackage(const QString &pid);//查
    int removeModelPackage(const QString &pid);//删
signals:

public slots:

private:
    QReadWriteLock m_lock;
    static QMultiHash<QString, ModelPackage *> * s_modelPackageHash;

};

#endif // SOURCEPACKAGEMANAGER_H
