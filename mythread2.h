#ifndef MYTHREAD2_H
#define MYTHREAD2_H

#include <QObject>
#include <QDebug>
#include <QThread>
class MyThread2 : public QObject
{
    Q_OBJECT
public:
    explicit MyThread2(QObject *parent = nullptr);

    void working();
signals:
    void finish(int num);
};

#endif // MYTHREAD2_H
