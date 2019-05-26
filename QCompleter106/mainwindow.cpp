#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList completionList;
    completionList << "Jeez" << "Bryan" << "Max" << "Beth";

    myStringCompleter_ = new QCompleter(completionList, this);
    myStringCompleter_->setCaseSensitivity(Qt::CaseInsensitive);

    ui->lineEdit->setCompleter(myStringCompleter_);

    //MODEL

    myDirModelCompleter_ = new QCompleter(this);
    myDirModelCompleter_->setModel(new QDirModel(myDirModelCompleter_));
    ui->lineEdit_2->setCompleter(myDirModelCompleter_);

}

MainWindow::~MainWindow()
{
    delete ui;
}
