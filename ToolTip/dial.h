#ifndef DIAL_H
#define DIAL_H

#include <QDialog>
#include "linkfilter.h"
#include <QMessageBox>

namespace Ui {
class Dial;
}

class Dial : public QDialog
{
    Q_OBJECT

public:
    explicit Dial(QWidget *parent = nullptr);
    ~Dial();

    void showLink(const QString& link);

private:
    Ui::Dial *ui;
};

#endif // DIAL_H
