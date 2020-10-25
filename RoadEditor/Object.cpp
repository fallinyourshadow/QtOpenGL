#include "Object.h"

Object::Object(QObject *parent) : MetaObject(parent)
{
    setObjectType(OBJECT);
    setText("Object");
}

void Object::initProperty()
{
    MetaObject::initProperty();
}
