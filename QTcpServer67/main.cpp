#include <QCoreApplication>
#include "qtcpserv.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpServ tcpServ;

    return a.exec();
}
