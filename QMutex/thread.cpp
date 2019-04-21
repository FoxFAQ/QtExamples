#include "thread.h"

thread::thread()
{

}

void thread::run()
{
//    QMutexLocker mLocker(&qMutex);
//    qMutex.lock();
    if(name == "Thread 1")
    {
        qMutex.lock();
        for(int i = 0; i < 100000; i++)
        {
            NUMBER++;
        }
        qDebug() << name + " Mutex" << NUMBER;
        qMutex.unlock();
    }
    else if(name == "Thread 2")
    {
        qMutex.lock();
        for(int i = 0; i < 100000; i++)
        {
            NUMBER++;
        }
        qDebug() << name + " Mutex" << NUMBER;
        qMutex.unlock();
    }
    else if(name == "Thread 3")
    {
        qMutex.lock();
        for(int i = 0; i < 100000; i++)
        {
            NUMBER++;
        }
        qDebug() << name + " Mutex" << NUMBER;
        qMutex.unlock();
    }


    qDebug() << name + " No mutex" << NUMBER;
//    qMutex.unlock();
}

