#include "Object.h"

Object::Object(QObject *parent) : MetaObject(parent)
{
    setObjectType(OBJECT);
}

void Object::initProperty()
{
    MetaObject::initProperty();
}
