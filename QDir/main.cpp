#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir testDir("C:/QtTestDirDelete");

    testDir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    testDir.setSorting(QDir::Size | QDir::Reversed);

    qDebug() << testDir.exists();
    if(!testDir.exists())
        testDir.mkpath(testDir.absolutePath());
    qDebug() << testDir.exists();

    qDebug() << "\n";

    foreach(QFileInfo checkItem, testDir.drives())
        qDebug() << checkItem;

    qDebug() << "\n";

    foreach(QFileInfo checkItem, testDir.entryInfoList())
        qDebug() << checkItem;

    return a.exec();
}
