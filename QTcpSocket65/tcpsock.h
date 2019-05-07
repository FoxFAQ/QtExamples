#ifndef TCPSOCK_H
#define TCPSOCK_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class TcpSock : public QObject
{
    Q_OBJECT
public:
    explicit TcpSock(QObject *parent = nullptr);

    void connect();
signals:

public slots:
private:
    QTcpSocket *socket = nullptr;
};

#endif // TCPSOCK_H
