#include "myudp.h"

MyUdp::MyUdp(QObject *parent) : QObject(parent)
{
    socket_ = new QUdpSocket(this);
    socket_->bind(QHostAddress::LocalHost, 1234);
    connect(socket_, &QUdpSocket::readyRead, this, &MyUdp::readyRead);
}

void MyUdp::sayHello()
{
    QByteArray data;
    data.append("Hello from UDP socket!");
    socket_->writeDatagram(data, QHostAddress::LocalHost, 1234);
}

void MyUdp::readyRead()
{
    QByteArray buffer;
    buffer.resize(socket_->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;
    socket_->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    qDebug() << sender.toString() << senderPort << buffer;
}
