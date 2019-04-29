#include "dial.h"
#include "ui_dial.h"

Dial::Dial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dial)
{
    ui->setupUi(this);

    LinkFilter *filter = new LinkFilter(this);
    this->installEventFilter(filter);
    connect(filter, &LinkFilter::linkClicked, this, &Dial::showLink);

    ui->pushButton->setWhatsThis("<a href='google.com'>Google!</a>");
}

Dial::~Dial()
{
    delete ui;
}

void Dial::showLink(const QString &link)
{
    QMessageBox::information(this, "Link clicked!", link);
}
