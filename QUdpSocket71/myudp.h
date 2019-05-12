#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QDebug>

class MyUdp : public QObject
{
    Q_OBJECT
public:
    explicit MyUdp(QObject *parent = nullptr);
    void sayHello();

signals:

public slots:
    void readyRead();

private:
    QUdpSocket *socket_;
};

#endif // MYUDP_H
