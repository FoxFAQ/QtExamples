#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include <QDebug>

/*
QIODevice::NotOpen
QIODevice::ReadOnly
QIODevice::WriteOnly
QIODevice::ReadWrite
QIODevice::Append
QIODevice::Truncate
QIODevice::Text
QIODevice::Unbuffered
QIODevice::NewOnly
QIODevice::ExistingOnly
*/

void writeDataStream(QString fileName)
{
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);   // we will serialize the data into the file
    out.writeRawData("1234567", 10);
    out << QString("the answer is");   // serialize a string
    out << (qint32)42;        // serialize an integer
    file.close();
}

void readDataStream(QString fileName)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);    // read the data serialized from the file
    QString str;
    qint32 a;
    char data[100];
    in.readRawData(data, 10);
    in >> str >> a;           // extract "the answer is" and 42
    qDebug() << data << str << a;
    file.close();
}

void writeTextStream(QString fileName)
{
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);   // we will serialize the data into the file
    out << QString("the answer is\n");   // serialize a string
    out << (qint32)42;        // serialize an integer
    file.close();
}

void readTextStream(QString fileName)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);    // read the data serialized from the file
    QString str;
    while(in.readLineInto(&str))
    {
        qDebug() << str;
    }
    file.close();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //writeDataStream("E:/delete.txt");
    //readDataStream("E:/delete.txt");

    //writeTextStream("E:/delete2.txt");
    //readTextStream("E:/delete2.txt");

    readTextStream(":/files/QFile.pro");

    return a.exec();
}
