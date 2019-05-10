#ifndef CONNECTEDCLIENT_H
#define CONNECTEDCLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QThreadPool>
#include "mytask.h"

class ConnectedClient : public QObject
{
    Q_OBJECT
public:
    explicit ConnectedClient(QObject *parent = nullptr);
    void setSocket(qintptr socketDescriptor);

signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void taskResult(int number);
private:
    QTcpSocket *socket = nullptr;
};

#endif // CONNECTEDCLIENT_H
