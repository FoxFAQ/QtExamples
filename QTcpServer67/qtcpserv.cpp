#include "qtcpserv.h"

QTcpServ::QTcpServ(QObject *parent) : QObject(parent)
{
    tcpServ = new QTcpServer(this);

    connect(tcpServ, &QTcpServer::newConnection, this, &QTcpServ::newConnection);

    if(tcpServ->listen(QHostAddress::Any, 8888))
        qDebug() << "Server started!";
    else {
        qDebug() << "Server didn't start!";
    }
}

void QTcpServ::newConnection()
{
    qDebug() << Q_FUNC_INFO;

    QTcpSocket *tcpSock = tcpServ->nextPendingConnection();

    tcpSock->write("Hi hi!");

    tcpSock->waitForBytesWritten(1000);

    tcpSock->close();
}
