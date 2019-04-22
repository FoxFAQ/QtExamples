#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QDebug>
#include <QThread>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = nullptr);
    void doSetup(QThread &wThread);
signals:

public slots:
    void doWork();
};

#endif // MYOBJECT_H
