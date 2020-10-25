#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QReadWriteLock>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QString name,QObject *parent = nullptr);
    typedef struct Status{
        bool isCited;
    }Status;
    Status status();//获得状态
    bool loading(const QString &path);
    QString name();
signals:

public slots:

private:
    QReadWriteLock m_lock;
    Status m_status;
    QString m_name;
    void statusInit();
};

#endif // MODEL_H
