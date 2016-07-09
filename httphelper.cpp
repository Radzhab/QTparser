#include "httphelper.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>
#include <QEvent>
#include <QObject>

HttpHelper::HttpHelper()
{

}

QString HttpHelper::GetHtml()
{
    QNetworkAccessManager manager;

    QNetworkRequest request(QUrl("http://rabota05.ru"));
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);

    QNetworkReply *response = manager.get(request);

    QEventLoop event;
    connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();

    QString html = response->readAll(); // Source should be stored here
    return html;
}
