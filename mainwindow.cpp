#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //第一种方式
    m = new MyThread1;//1.1创建子线程对象1
    //1.2在下方
    //1.3接收子线程传递的数据
    connect(m,&MyThread1::finish,this,[=](int num)
    {
        ui->label_2->setNum(num);
    });
    //第二种方式
    t =new QThread; //2.1.创建子线程对象
    m2 = new MyThread2;//2.2创建任务类对象
    m2->moveToThread(t); //2.3.将任务对象移动到某个子线程中
    connect(this,&MainWindow::start,m2,&MyThread2::working);//2.5发送信号执行work函数
    //2.6接收子线程的数据
    connect(m2,&MyThread2::finish,this,[=](int num)
    {
        ui->label_3->setNum(num);
    });

    //释放资源
    connect(this,&MainWindow::destroyed,this,[=]()
    {
        qDebug()<<"析构";
        //第一种
        m->quit();
        m->wait();
        m->deleteLater();

        //第二种
        t->quit();
        t->wait();
        t->deleteLater();
        m2->deleteLater();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::workOnMainThread()
{
    qDebug()<<"当前MainThread线程地址:"<<QThread::currentThread()<<endl;
    int num = 0;
    while (1)
    {
        num++;
        ui->label->setNum(num);
        if(num == 10000000)
            break;

    }
}




void MainWindow::on_btnStartOnMainThread_clicked()
{
    workOnMainThread();
}

void MainWindow::on_btnStartOnThread1_clicked()
{
    //1.2启动子线程1
    m->start();
}

void MainWindow::on_btnStartOnThread2_clicked()
{
    //2.4.启动子线程,并发送信号执行work函数
    t->start();
    emit start();
}
