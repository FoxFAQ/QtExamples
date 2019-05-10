#include "tcpserv.h"

TcpServ::TcpServ()
{
    QThreadPool::globalInstance()->setMaxThreadCount(15);
}

void TcpServ::startServer()
{
    qDebug() << Q_FUNC_INFO;

    if(listen(QHostAddress::Any,44444))
    {
        qDebug() << "Server started!";
    }
    else {
        qDebug() << "Server didn't start!";
    }
}

void TcpServ::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << Q_FUNC_INFO;

    ConnectedClient *client = new ConnectedClient(this);
    client->setSocket(socketDescriptor);
}
