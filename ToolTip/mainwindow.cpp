#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->setToolTip("Hello <font color='red' size='11'><b>World</b></font>"
                               "<ul>"
                               "<li>1</li>"
                               "<li>2</li>"
                               "<li>3</li>"
                               "</ul>");

    ui->pushButton_2->setToolTip("<img src='qrc:/tooltip/1.jpg'> Hello <font color='red' size='11'><b>World</b></font>");

    ui->pushButton_3->setToolTip("<img src=':/tooltip/1.png'> Hello <font color='red' size='11'><b>World</b></font>");

//    ui->pushButton->setWhatsThis("<a href=google.com>click</a>");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dial dial(this);
    dial.exec();
}
