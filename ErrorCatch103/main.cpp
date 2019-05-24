#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try
    {//nice stuff for DLL
//        throw "Char Error";
//        throw QString("QSTRING Error");
        throw 4;
    }
    catch(char *cErr)
    {
        qDebug() << "Char Error = " << cErr;
    }
    catch(QString qErr)
    {
        qDebug() << "QSTRING Error = " << qErr;
    }
    catch (...)
    {
        qDebug() << "Unknow Error";
    }

    return a.exec();
}
