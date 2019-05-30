#include "sender.h"

Sender::Sender(QObject *parent) : QObject(parent)
{

}

void Sender::sendSignal()
{
    Sender_::Instance()->signal();
}
