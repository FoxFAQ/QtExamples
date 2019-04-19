#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(3);
    QStringList headerLabels;
    headerLabels << "Country/City name" << "People count" << "Number Added";
    ui->treeWidget->setHeaderLabels(headerLabels);
    ui->treeWidget->setColumnWidth(0, 150);
    ui->treeWidget->setColumnWidth(1, 150);
    ui->treeWidget->setColumnWidth(2, 150);

/*
addTopLevelItem(QTreeWidgetItem *item)
addTopLevelItems(const QList<QTreeWidgetItem *> &items)
insertTopLevelItem(int index, QTreeWidgetItem *item)
itemAbove(const QTreeWidgetItem *item) const
itemBelow(const QTreeWidgetItem *item) const
sortColumn() const
sortItems(int column, Qt::SortOrder order)
takeTopLevelItem(int index)
topLevelItem(int index) const
topLevelItemCount() const
*/

    for(int i = 0; i < 5; i++)
    {
        QTreeWidgetItem *top = new QTreeWidgetItem;
        top->setText(0, tr("World"));
        top->setText(1, "8 000 000 000");
        top->setText(2, QString::number(i+1));
        ui->treeWidget->addTopLevelItem(top);
        for(int j = 0; j < 2; j++)
        {
            QTreeWidgetItem *middle = new QTreeWidgetItem;
            middle->setText(0, tr("Middle"));
            middle->setText(1, "300 000");
            middle->setText(2, QString::number(i+1));
            top->addChild(middle);
            for(int k = 0; k < 1; k++)
            {
                QTreeWidgetItem *low = new QTreeWidgetItem;
                low->setText(0, tr("Low"));
                low->setText(1, "300");
                low->setText(2, QString::number(i+1));
                middle->addChild(low);
            }
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if(item->parent())
        qDebug() << "ABOVE: " << item->parent()->text(0) << item->parent()->text(1) << item->parent()->text(2);
    qDebug() << item->text(0) << item->text(1) << item->text(2) <<column;
    if(item->childCount())
        qDebug() << "BELOW: " << item->child(0)->text(0) << item->child(0)->text(1) << item->child(0)->text(2);
}

void MainWindow::on_actionAdd_Child_triggered()
{
    QTreeWidgetItem *child = new QTreeWidgetItem;
    child->setText(0, "Child");
    ui->treeWidget->currentItem()->addChild(child);
}
