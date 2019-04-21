#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QMutex>
#include <QDebug>

static QMutex qMutex;
static int NUMBER;

class thread : public QThread
{
public:
    thread();

    QString name = "Thread";
protected:
    virtual void run();
};

#endif // THREAD_H
