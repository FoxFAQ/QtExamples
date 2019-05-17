#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

void loadSettings()
{
    qDebug() << Q_FUNC_INFO;
    QSettings settings("CompanyName", "QSettings92");

    settings.beginGroup("doubleInt");
    double valD = settings.value("double", 7.777).toDouble();
    int valInt = settings.value("int", 7).toInt();
    qDebug() << valD << valInt;
    settings.endGroup();
}

void saveSettings()
{
    qDebug() << Q_FUNC_INFO;
    QSettings settings("CompanyName", "QSettings92");

    settings.beginGroup("doubleInt");
    settings.setValue("double", 9.999);
    settings.setValue("int", 4);
    settings.endGroup();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    loadSettings();

    saveSettings();

    return a.exec();
}
