#include "tcp_transmission.h"

Tcp_transmission::Tcp_transmission(QObject *parent) : QObject(parent)
{

}

Tcp_transmission::~Tcp_transmission()
{

}

QString Tcp_transmission::shell_p() const
{
    return value_shell_p;
}

QString Tcp_transmission::shell_i() const
{
    return value_shell_i;
}

QString Tcp_transmission::core_p() const
{
    return value_core_p;
}

QString Tcp_transmission::core_i() const
{
    return value_core_i;
}

QString Tcp_transmission::core_d() const
{
    return value_core_d;
}

void Tcp_transmission::setShell_p(const QString &shell_p)
{
    value_shell_p = shell_p;
}

void Tcp_transmission::setShell_i(const QString &shell_i)
{
    value_shell_i = shell_i;
}

void Tcp_transmission::setCore_p(const QString &core_p)
{
    value_core_p = core_p;
}

void Tcp_transmission::setCore_i(const QString &core_i)
{
    value_core_i = core_i;
}

void Tcp_transmission::setCore_d(const QString &core_d)
{
    value_core_d = core_d;
}

void Tcp_transmission::link_x_parm()
{
    x_pid_parm = value_shell_p + "," + \
                    value_shell_i + "," + \
                    value_core_p + "," + \
                    value_core_i + "," + \
                    value_core_d;
    qDebug("x_pid_parm:" + x_pid_parm.toUtf8());
}

void Tcp_transmission::link_y_parm()
{
    y_pid_parm = value_shell_p + "," + \
                    value_shell_i + "," + \
                    value_core_p + "," + \
                    value_core_i + "," + \
                    value_core_d;
    qDebug("y_pid_parm:" + y_pid_parm.toUtf8());
}
