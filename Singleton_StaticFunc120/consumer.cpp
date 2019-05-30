#include "consumer.h"

Consumer::Consumer(QObject *parent) : QObject(parent)
{
    connect(Sender_::Instance(), SIGNAL(signal()), this, SLOT(signalReceived()));
}

void Consumer::signalReceived()
{
    qDebug() << Q_FUNC_INFO;
}
