#ifndef HTTPHELPER_H
#define HTTPHELPER_H
#include <QObject>


class HttpHelper:public QObject{
Q_OBJECT
public:
    explicit HttpHelper();
    void GetHtml();
};

#endif // HTTPHELPER_H
