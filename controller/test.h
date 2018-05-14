#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QQuickItem>
#include <QDebug>
#include <QString>

class Test: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString data READ data WRITE setData NOTIFY data_Changed)
public:
    explicit Test(QObject *parent = nullptr);
    ~Test();

    Q_INVOKABLE void change_data();

    QString data() const;
    void setData(const QString &data);
signals:
    void data_Changed();
public slots:
    void data_opt();

private:
    int i;
    QString str;
};

#endif // TEST_H
