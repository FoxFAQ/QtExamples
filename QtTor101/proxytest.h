#ifndef PROXYTEST_H
#define PROXYTEST_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>
#include <QNetworkProxy>

class ProxyTest : public QObject
{
    Q_OBJECT
public:
    explicit ProxyTest(QObject *parent = nullptr);

signals:

public slots:
    void getUrl();
    void replyFinished(QNetworkReply *reply);
};

#endif // PROXYTEST_H
