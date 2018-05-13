#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QQuickItem>

class test : public QObject
{
    Q_OBJECT

//    Q_PROPERTY(Qstring data READ data WRITE setdata NOTIFY datachange)

public:
    explicit test(QObject *parent = nullptr);

signals:


public slots:

};

#endif // TEST_H
