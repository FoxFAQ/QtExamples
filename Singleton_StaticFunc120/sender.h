#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include "singleton.h"

class Sender : public QObject
{
    Q_OBJECT
public:
    explicit Sender(QObject *parent = nullptr);

    static void sendSignal();

signals:
    void signal();

public slots:
};

//Global variable__
typedef Singleton<Sender> Sender_;

#endif // SENDER_H
