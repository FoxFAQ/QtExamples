#include <QCoreApplication>
#include "tcpserv.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TcpServ tcpServ;
    tcpServ.startServer();

    return a.exec();
}
