#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Window_triggered()
{
    myDialog = new Dialog(this);
    myDialog->show();
//    Dialog myDialog;
//    myDialog.setModal(true);
//    myDialog.exec();
}
