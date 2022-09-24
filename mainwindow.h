#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mythread1.h"
#include "mythread2.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void workOnMainThread();
signals:
    void start();
private slots:

    void on_btnStartOnMainThread_clicked();

    void on_btnStartOnThread1_clicked();

    void on_btnStartOnThread2_clicked();

private:
    Ui::MainWindow *ui;
    MyThread1 *m;
    QThread *t;
    MyThread2 *m2;
};
#endif // MAINWINDOW_H
