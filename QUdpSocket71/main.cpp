#include <QCoreApplication>
#include "myudp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyUdp myUdpServer;
    MyUdp myUdpClient;
    myUdpClient.sayHello();

    return a.exec();
}
