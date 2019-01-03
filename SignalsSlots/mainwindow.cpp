#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar_2, SLOT(setValue(int)));
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MainWindow::setProgressBar3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}

void MainWindow::setProgressBar3(int value)
{
    ui->progressBar_3->setValue(value);
}
