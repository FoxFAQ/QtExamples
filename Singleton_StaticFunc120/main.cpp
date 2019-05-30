#include <QCoreApplication>
#include "sender.h"
#include "consumer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Consumer consumer;
    //From the object
    Sender_::Instance()->sendSignal();
    //Just From the static function, no object
    Sender::sendSignal();

    return a.exec();
}
