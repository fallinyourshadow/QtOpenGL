#ifndef METAOBJECT_H
#define METAOBJECT_H

#include <QObject>
#include <QSharedPointer>
#include <QWeakPointer>
#include "Model.h"
#include <QStandardItem>



class MetaObject : public QObject , public QStandardItem
{

    Q_OBJECT
public:
    typedef enum ObjectType{
        META_OBJECT,
        SCENE,
        TOP_SCENE,
        OBJECT
    }ObjectType;
    explicit MetaObject(QObject *parent = nullptr);
    QWeakPointer<Model *> model();//返回当前引用的model
    void citeModel(QSharedPointer<Model *> &model);//引用一个model
    void removeModel();//
    //QStandardItem * item();
    virtual void initProperty();
    void hellow();
    ObjectType objectType();
signals:

public slots:

protected:
    void setObjectType(ObjectType type);
private:
    //QStandardItem * m_pItem;
    QWeakPointer<Model *> m_pModel;//所引用的模型
    ObjectType m_objectType;

};

#endif // METAOBJECT_H
