#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getNumber(int &baseNumber)
{
    int high = 1343;
    int low = 343;
    int random = qrand() % ((high + 1) - low) + low;
    qDebug() << baseNumber << " -> " << random;
    baseNumber = random;
    return 0;
}

void MainWindow::on_pushButton_clicked()
{
    QList<int> list;

    for(int i = 0; i < 10000; i++)
    {
        list << i;
    }

    QtConcurrent::blockingMap(list, &MainWindow::getNumber);

    ui->listWidget->clear();

    for (int i = 0; i < list.count(); i++)
    {
        ui->listWidget->addItem(QString::number(i) + " -> " + QString::number(list[i]));
    }
}
