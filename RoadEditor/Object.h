#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include "MetaObject.h"

class Object : public MetaObject
{
    Q_OBJECT
public:
    explicit Object(QObject *parent = nullptr);

signals:

public slots:
};

#endif // OBJECT_H
