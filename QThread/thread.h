#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QDebug>
class thread : public QThread
{
public:
    thread();
    void run();
    QString name;
};

#endif // THREAD_H
