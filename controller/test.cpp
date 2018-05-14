#include "Test.h"

Test::Test(QObject *parent) : QObject(parent)
{
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
    qDebug(str.toUtf8());
}
