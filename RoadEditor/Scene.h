#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include "MetaObject.h"

class Scene : public MetaObject
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SCENE_H
