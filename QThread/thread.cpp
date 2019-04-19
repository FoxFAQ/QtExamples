#include "thread.h"
#include <QDebug>

thread::thread()
{

}

void thread::run()
{
    for(int i = 0; i < 100; i++)
        qDebug() << name << i;
}
