#include<QDebug>
#include<QThread>
#define DEBUG(content) \
    qDebug()<< "[" << __FILE__ << ","<< __LINE__<<"," << __FUNCDNAME__ <<"]:\n"<< content
#define LOC(string) \
    QString::fromLocal8Bit(string)
