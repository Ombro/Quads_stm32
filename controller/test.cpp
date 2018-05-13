#include "test.h"
#include <QDebug>
test::test(QObject *parent) : QObject(parent)
{
    QObject::connect(this, SIGNAL(link()), this, SLOT(print_data()));
}




float test::get_shell_p()
{
    return data_shell_p;
}

float test::get_shell_i()
{
    return data_shell_i;
}

float test::get_core_p()
{
    return data_core_p;
}

float test::get_core_i()
{
    return data_core_i;
}

float test::get_core_d()
{
    return data_core_d;
}

void test::print_data()
{
    QDebug("helloworld!");
}

test::~test(){}
