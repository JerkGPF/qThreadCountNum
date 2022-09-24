#ifndef MYTHREAD1_H
#define MYTHREAD1_H

#include <QDebug>
#include <QThread>
class MyThread1 : public QThread
{
    Q_OBJECT
public:
    explicit MyThread1(QObject *parent = nullptr);

    void run() override;
signals:

    void finish(int num);
};

#endif // MYTHREAD1_H
