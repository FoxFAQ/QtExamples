#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar_2, SLOT(setValue(int)));
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MainWindow::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}

void MainWindow::setValue(int value)
{
    ui->progressBar_2->setValue(value);
}
