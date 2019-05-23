#include <QCoreApplication>
#include "proxytest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ProxyTest proxyTest;
    proxyTest.getUrl();

    return a.exec();
}
