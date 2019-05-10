#ifndef TCPSERV_H
#define TCPSERV_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include "connectedclient.h"

class TcpServ : public QTcpServer
{
    Q_OBJECT
public:
    TcpServ();
    void startServer();
protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // TCPSERV_H
