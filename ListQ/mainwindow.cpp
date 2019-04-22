#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<int> list;
    list << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10;
    qDebug() << list << list[0] << list.at(0);

    QListIterator<int> lIter(list);

    lIter.toBack();
    while(lIter.hasPrevious())
        qDebug() << lIter.previous();
    while(lIter.hasNext())
        qDebug() << lIter.next();

    QMutableListIterator<int> mutIter(list);

    while(mutIter.hasNext())
    {
        mutIter.next();
        if(mutIter.value() == 4 || mutIter.value() == 8)
            mutIter.remove();
        //setValue(val);
    }
    qDebug() << list;

}

MainWindow::~MainWindow()
{
    delete ui;
}
