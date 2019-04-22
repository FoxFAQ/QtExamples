#include "myobject.h"

MyObject::MyObject(QObject *parent) : QObject(parent)
{

}

void MyObject::doSetup(QThread &wThread)
{
    connect(&wThread, &QThread::started, this, &MyObject::doWork);
}

void MyObject::doWork()
{
    for(int i = 0; i < 100; i++)
        qDebug() << i;
}
