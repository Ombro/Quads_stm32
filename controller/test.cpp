#include "Test.h"

Test::Test(QObject *parent) : QObject(parent)
{
    i = 1;
    qDebug("start");
}

Test::~Test(){}

QString Test::data() const
{
    return str;
}

void Test::setData(const QString &data)
{
    str = data;
    qDebug()<<str;
    emit data_Changed();
}

void Test::data_opt()
{
    qDebug("hello");
}

void Test::change_data()
{
    i++;
    qDebug("world");
}
