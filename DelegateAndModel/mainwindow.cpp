#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    delegate = new Delegate(this);

    model = new QStandardItemModel(4, 2, this);

    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 2; col++)
        {
            QModelIndex index = model->index(row, col, QModelIndex());
            model->setData(index, (row+1)*(col+1));
        }
    }

    ui->tableView->setModel(model);
    ui->tableView_2->setModel(model);

    ui->tableView->setItemDelegate(delegate);
    ui->tableView_2->setItemDelegate(delegate);

    ui->listView->setModel(model);
    ui->comboBox->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
