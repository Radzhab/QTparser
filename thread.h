#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QPlainTextEdit>
#include <httphelper.h>
class Worker : public QObject
{
    Q_OBJECT
    QThread workerThread;
    HttpHelper *helper;

public slots:
    void doWork(const QString &result) {

        emit resultReady(helper->GetHtml());
    }

signals:
    void resultReady(const QString &result);
};

class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;
    QPlainTextEdit *textDesk;


public:
    Controller(QPlainTextEdit *txt): textDesk(txt) {
        Worker *worker = new Worker;
        worker->moveToThread(&workerThread);
        connect(&workerThread, SIGNAL(finished()), worker, SLOT(deleteLater()));
        connect(this, SIGNAL(operate(QString)), worker, SLOT(doWork(QString)));
        connect(worker, SIGNAL(resultReady(QString)), this, SLOT(handleResults(QString)));
        workerThread.start();
    }
    ~Controller() {
        workerThread.quit();
        workerThread.wait();
    }
public slots:
    void handleResults(const QString &str)
    {
        textDesk->appendHtml(str);
    }
signals:
    void operate(const QString &);
};

#endif // THREAD_H
