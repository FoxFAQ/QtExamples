#ifndef QTCPSERV_H
#define QTCPSERV_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class QTcpServ : public QObject
{
    Q_OBJECT
public:
    explicit QTcpServ(QObject *parent = nullptr);

signals:

public slots:
    void newConnection();
private:
    QTcpServer *tcpServ = nullptr;
};

#endif // QTCPSERV_H
