#include "tcpsock.h"

TcpSock::TcpSock(QObject *parent) : QObject(parent)
{

}

void TcpSock::connectSock()
{
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::connected, this, &TcpSock::connected);
    connect(socket, &QTcpSocket::disconnected, this, &TcpSock::disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &TcpSock::readyRead);
    connect(socket, &QTcpSocket::bytesWritten, this, &TcpSock::bytesWritten);

    socket->connectToHost("google.com", 80);

    if(!socket->waitForConnected(3000))
    {
        qDebug() << "Not connected!" << socket->errorString();
    }
}

void TcpSock::connected()
{
    qDebug() << Q_FUNC_INFO;

    socket->write("Hello server/r/n");
}

void TcpSock::disconnected()
{
    qDebug() << Q_FUNC_INFO;
}

void TcpSock::bytesWritten(qint64 bytes)
{
    qDebug() << Q_FUNC_INFO << bytes;
}

void TcpSock::readyRead()
{
    qDebug() << Q_FUNC_INFO << socket->readAll();
}
