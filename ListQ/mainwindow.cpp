#include "mainwindow.h"
#include "ui_mainwindow.h"

bool caseInsensitiveLessThan(const QString &s1, const QString &s2)
  {
      return s1.toLower() < s2.toLower();
  }

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    Index lookup 1
    Insertion n
    Prepending Am1
    Appending Am1
    */

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

    /*
    Index lookup n
    Insertion 1
    Prepending 1
    Appending 1
    */

    QLinkedList<int> llist;
    llist << 1 << 7 << 7 << 7;

    foreach(int i, llist)
        qDebug() << i;

    /*
    Index lookup 1
    Insertion n
    Prepending n
    Appending Am1
    */
    QVector<int> vec[1024];

    /*
    Key lookup
    Average log n
    Worst case log n
    Insertion
    Average log n
    Worst case log n
    */
    QMap<int, QString> idName;
    /*
    Key lookup
    Average log n
    Worst case log n
    Insertion
    Average log n
    Worst case log n
    */
    QMultiMap<QString, int> nameId;

    /*
    Key lookup
    Average Am1
    Worst case n
    Insertion
    Average Am1
    Worst case n
    */
    QHash<int, QString> idNameHash;
    QMultiHash<QString, int> nameIdHash;

    QStringList strList;
    strList << "Sun " << "iS " << "shINIng!";
    qDebug() << strList;
    foreach(const QString &str, strList)
        qDebug() << str;

    /*
    Key lookup
    Average Am1
    Worst case n
    Insertion
    Average Am1
    Worst case n
    */
    QSet<QString> stringSet;
    stringSet << "one" << "two" << "three";
    qDebug() << stringSet;


    QList<int> list1;
    list1 << 33 << 12 << 68 << 6 << 12;
    std::sort(list1.begin() + 1, list1.end() - 1);
    qDebug() << list1;
    std::sort(list1.begin() + 1, list1.end() - 1, std::greater<int>());
    qDebug() << list1;

    qDebug() << strList;
    std::sort(strList.begin(), strList.end(), caseInsensitiveLessThan);
    qDebug() << strList;

    QVector<QString> strVec(3);
    std::copy(strList.begin() + 1, strList.end(), strVec.begin() + 1);
    foreach(const QString &str, strVec)
        qDebug() << str;

    std::fill(strVec.begin(), strVec.end(), "FILLED!");
    qDebug() << strVec;
}

MainWindow::~MainWindow()
{
    delete ui;
}
