#include "delegate.h"

Delegate::Delegate(QObject *parent)
{

}

QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *spBox = new QSpinBox(parent);
    spBox->setMinimum(0);
    spBox->setMaximum(122);
    return spBox;
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QSpinBox *spBox = static_cast<QSpinBox*>(editor);
    spBox->setValue(value);
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spBox = static_cast<QSpinBox*>(editor);
    spBox->interpretText();
    int value = spBox->value();
    model->setData(index, value, Qt::EditRole);
}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
