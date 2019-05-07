#include <QCoreApplication>
#include "tcpsock.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TcpSock sock;
    sock.connectSock();

    return a.exec();
}
