#include<QDebug>
#include<QThread>

#define DEBUG_TITLE \
    qDebug()<< "[" << __FILE__ << ","<< __LINE__<<"," << __FUNCNAME__ << "," << QThread::currentThreadId() <<"]:\n"
#define DEBUG(content) \
    qDebug() << content

#define LOC(string) \
    QString::fromLocal8Bit(string)
