#include "mythread1.h"

MyThread1::MyThread1(QObject *parent) : QThread(parent)
{

}

void MyThread1::run()
{
    qDebug()<<"当前MyThread1线程地址:"<<QThread::currentThread()<<endl;
    int num = 0;
    while (1)
    {
        num++;
        emit finish(num);
        if(num == 10000000)
            break;
        usleep(1);//延迟1纳秒
    }
}
