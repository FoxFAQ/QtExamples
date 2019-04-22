#include <QCoreApplication>
#include "myobject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread wThread;
    MyObject wObject;

    wObject.doSetup(wThread);
    wObject.moveToThread(&wThread);

    wThread.start();

    return a.exec();
}
