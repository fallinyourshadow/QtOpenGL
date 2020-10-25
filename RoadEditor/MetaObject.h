#ifndef METAOBJECT_H
#define METAOBJECT_H

#include <QObject>
#include <QSharedPointer>
#include "Model.h"
#include <QStandardItem>
#include "ModelPackage.h"


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
    ~MetaObject();
    Model * model();//返回当前引用的model
    void citeModel(Model * model);//引用一个model
    void removeModel();//
    //QStandardItem * item();
    virtual void initProperty();
    void hellow();
    ObjectType objectType();
    ModelPackage *modelPackage();
    bool citeModelPackage(class ModelPackage *package);
signals:

public slots:

protected:
    void setObjectType(ObjectType type);
private:
    //QStandardItem * m_pItem;
   // QReadWriteLock m_lock;
    Model * m_pModel;//所引用的模型
    ObjectType m_objectType;
    class ModelPackage * m_pModelPackage;

};

#endif // METAOBJECT_H
