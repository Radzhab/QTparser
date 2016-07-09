#ifndef HTTPHELPER_H
#define HTTPHELPER_H
#include <QObject>


class HttpHelper:public QObject{
Q_OBJECT
public:
    explicit HttpHelper();
    QString GetHtml();
};

#endif // HTTPHELPER_H
