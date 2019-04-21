#include <QCoreApplication>
#include "thread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    thread thr1;
    thread thr2;
    thread thr3;
    thr1.name = "Thread 1";
    thr2.name = "Thread 2";
    thr3.name = "Thread 3";

    thr1.start();
    thr2.start();
    thr3.start();

    return a.exec();
}
