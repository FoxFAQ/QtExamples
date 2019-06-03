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

bool MainWindow::doFilter(const QString str)
{
    if(str.toLower() == "one")
        return false;
    return true;
}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();

    QStringList itemsBefore;
    itemsBefore << "One" << "Two" << "Three";
    ui->listWidget->addItems(itemsBefore);

//    QStringList itemsAfter = QtConcurrent::blockingMapped(itemsBefore, &MainWindow::changeString);

    QStringList itemsAfter = QtConcurrent::blockingFiltered(itemsBefore, &MainWindow::doFilter);
    ui->listWidget_2->addItems(itemsAfter);
}
