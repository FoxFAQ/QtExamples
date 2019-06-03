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

QString MainWindow::changeString(QString str)
{
    str.append(" Added Text!");
    return str;
}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();

    QStringList itemsBefore;
    itemsBefore << "1" << "2" << "3";
    ui->listWidget->addItems(itemsBefore);

    QStringList itemsAfter = QtConcurrent::blockingMapped(itemsBefore, &MainWindow::changeString);

    ui->listWidget_2->addItems(itemsAfter);
}
