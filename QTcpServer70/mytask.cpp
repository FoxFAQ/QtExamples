#include "mytask.h"

MyTask::MyTask()
{

}

void MyTask::run()
{
    qDebug() << "Task Started";

    int number = 0;

    for(int i = 0; i < 100000; i++)
        number += i;

    qDebug() << "Task is Done";

    emit result(number);
}
