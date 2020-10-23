#ifndef METAOBJECT_H
#define METAOBJECT_H

#include <QObject>
#include <QSharedPointer>
#include <QWeakPointer>
#include "Model.h"
#include <QStandardItem>

class MetaObject : public QObject
{
    Q_OBJECT
public:
    explicit MetaObject(QObject *parent = nullptr);
    QWeakPointer<Model *> model();//返回当前引用的model
    void citeModel(QSharedPointer<Model *> &model);//引用一个model
    void removeModel();//
signals:

public slots:
private:
    QStandardItem * m_pItem;
    QWeakPointer<Model *> m_pModel;//所引用的模型
    void initProperty();
};

#endif // METAOBJECT_H
