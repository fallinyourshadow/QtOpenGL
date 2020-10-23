#ifndef TOPSCENE_H
#define TOPSCENE_H

#include <QObject>
#include "Scene.h"
class Topscene : public Scene
{
    Q_OBJECT
public:
    explicit Topscene(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TOPSCENE_H
