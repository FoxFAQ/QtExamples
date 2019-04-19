#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class thread : public QThread
{
public:
    thread();
    void run();
    QString name;
};

#endif // THREAD_H
