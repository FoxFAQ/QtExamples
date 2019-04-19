#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::warning(this, "Text 1", "Text 2");
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this, "Text 1", "Text 2");
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::critical(this, "Text 1", "Text 2");
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::question(this, "Text 1", "Text 2");
    QMessageBox::question(this, "Text 1", "Text 2", QMessageBox::YesToAll  | QMessageBox::Yes | QMessageBox::No | QMessageBox::NoToAll);
}
