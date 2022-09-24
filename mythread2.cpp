#include "mythread2.h"

MyThread2::MyThread2(QObject *parent) : QObject(parent)
{

}

void MyThread2::working()
{
    qDebug()<<"当前MyThread2线程地址:"<<QThread::currentThread()<<endl;
    int num = 0;
    while (1)
    {
        num++;
        emit finish(num);
        if(num == 10000000)
            break;
        QThread::usleep(1);//延迟1纳秒

    }
}
