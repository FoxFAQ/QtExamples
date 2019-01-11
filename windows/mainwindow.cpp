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

void MainWindow::on_actionModal_triggered()
{
    Dialog dial;
    dial.exec();
}

void MainWindow::on_actionNot_Modal_triggered()
{
    Dialog *newDialog = new Dialog(this);
    newDialog->show();
}
