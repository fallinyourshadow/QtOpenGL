#include<QDebug>
#include<QThread>

#define DEBUG_TITLE \
    qDebug()<< "[" << __FILE__ << ","<< __LINE__<<"," << __FUNCDNAME__ << "," << QThread::currentThreadId() <<"]:\n"
#define DEBUG(content) \
    qDebug() << content

#define LOC(string) \
    QString::fromLocal8Bit(string)

#define DELETER(ptr) \
    delete ptr; \
    ptr = nullptr
