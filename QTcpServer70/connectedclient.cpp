#include "connectedclient.h"

ConnectedClient::ConnectedClient(QObject *parent) : QObject(parent)
{
    qDebug() << Q_FUNC_INFO << QThreadPool::globalInstance()->maxThreadCount();
}

void ConnectedClient::setSocket(qintptr socketDescriptor)
{
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::connected, this, &ConnectedClient::connected);
    connect(socket, &QTcpSocket::disconnected, this, &ConnectedClient::disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &ConnectedClient::readyRead);

    socket->setSocketDescriptor(socketDescriptor);

    qDebug() << "Socket Descriptor set";
}

void ConnectedClient::connected()
{
    qDebug() << Q_FUNC_INFO;
}

void ConnectedClient::disconnected()
{
    qDebug() << Q_FUNC_INFO;
}

void ConnectedClient::readyRead()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << socket->readAll();

    MyTask *myTask = new MyTask();
    myTask->setAutoDelete(true);
    connect(myTask, &MyTask::result, this, &ConnectedClient::taskResult, Qt::QueuedConnection);
    QThreadPool::globalInstance()->start(myTask);
}

void ConnectedClient::taskResult(int number)
{
    qDebug() << Q_FUNC_INFO << number;
    QByteArray buffer;
    buffer.append("\r\nTask Result = ");
    buffer.append(QString::number(number));

    socket->write(buffer);
}
