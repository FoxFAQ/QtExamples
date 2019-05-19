#include <QCoreApplication>
#include "dll97.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DLL97 dll97;
    dll97.test();

    return a.exec();
}
