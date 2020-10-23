#ifndef METAOBJECT_H
#define METAOBJECT_H

#include <QObject>
#include <QSharedPointer>
#include "Model.h"
class MetaObject : public QObject
{
    Q_OBJECT
public:
    explicit MetaObject(QObject *parent = nullptr);
    QSharedPointer<Model *> model();//返回当前引用的model
    void citeModel(QSharedPointer<Model *> model);//引用一个model
    void removeModel();//
signals:

public slots:
private:
    Model * m_pModel;
    void initProperty();
};

#endif // METAOBJECT_H
