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

    void connectSock();
signals:

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private:
    QTcpSocket *socket = nullptr;
};

#endif // TCPSOCK_H
