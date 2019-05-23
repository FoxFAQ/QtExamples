#include "proxytest.h"

ProxyTest::ProxyTest(QObject *parent) : QObject(parent)
{

}

void ProxyTest::getUrl()
{
    qDebug() << Q_FUNC_INFO;

    QNetworkProxy proxy;
    proxy.setType(QNetworkProxy::DefaultProxy);
    proxy.setHostName("127.0.0.1");
    proxy.setPort(9150);
//    proxy.setUser("username");
//    proxy.setPassword("password");
    QNetworkProxy::setApplicationProxy(proxy);

    QNetworkAccessManager *nAM = new QNetworkAccessManager(this);
    connect(nAM, &QNetworkAccessManager::finished, this, &ProxyTest::replyFinished);
    nAM->get(QNetworkRequest(QUrl("http://www.ip-adress.eu/")));
}

void ProxyTest::replyFinished(QNetworkReply *reply)
{
    qDebug() << Q_FUNC_INFO;

    if(reply->isOpen())
    {
        qDebug() << reply->read(5000);
        reply->close();
    }
}
