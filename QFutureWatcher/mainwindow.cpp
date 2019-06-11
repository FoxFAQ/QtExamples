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

void MainWindow::doTask(int &number)
{
    qDebug() << "Starting " << number;

    for(int i = 0; i < 10; i++)
    {
        QThread::currentThread()->msleep(50);
        qDebug() << "Processing " << number << i << " of " << 10;
    }

    qDebug() << "Stopped " << number;
}

void MainWindow::on_pushButton_clicked()
{
    QVector<int> vector;
    for(int i = 0; i < ui->spinBox->value(); i++)
    {
        vector << i;
    }

    QProgressDialog pDialog;
    pDialog.setLabelText("Processing");

    QFutureWatcher<void> watcher;

    connect(&pDialog, &QProgressDialog::canceled, &watcher, &QFutureWatcher<void>::cancel);
    connect(&watcher, &QFutureWatcher<void>::finished, &pDialog, &QProgressDialog::reset);
    connect(&watcher, &QFutureWatcher<void>::progressRangeChanged, &pDialog, &QProgressDialog::setRange);
    connect(&watcher, &QFutureWatcher<void>::progressValueChanged, &pDialog, &QProgressDialog::setValue);

    watcher.setFuture(QtConcurrent::map(vector, &MainWindow::doTask));

    pDialog.exec();
    watcher.waitForFinished();

    if(watcher.isCanceled())
    {
        qDebug() << "canceled!!!";
    }
    else
    {
        qDebug() << "FINISHED!!!";
    }
}
