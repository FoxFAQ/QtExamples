#ifndef MYTASK_H
#define MYTASK_H

#include <QObject>
#include <QRunnable>
#include <QDebug>

class MyTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    MyTask();

signals:
    void result(int number);

protected:
    void run();
};

#endif // MYTASK_H
