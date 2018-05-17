#include "tcp_transmission.h"

Tcp_transmission::Tcp_transmission(QObject *parent): QTcpSocket(parent)
{
    connect_state = "connect state";

    address = "192.168.4.1";
    port = "6666";

    value_shell_p = "0";
    value_shell_i = "0";
    value_core_p = "0";
    value_core_i = "0";
    value_core_d = "0";
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
    x_pid_parm =    "@X"          +       \
                    value_shell_p + "," + \
                    value_shell_i + "," + \
                    value_core_p  + "," + \
                    value_core_i  + "," + \
                    value_core_d  +       \
                    "#";
    write(x_pid_parm.toUtf8());
}

void Tcp_transmission::link_y_parm()
{
    y_pid_parm =    "@Y"          +       \
                    value_shell_p + "," + \
                    value_shell_i + "," + \
                    value_core_p  + "," + \
                    value_core_i  + "," + \
                    value_core_d  +       \
                    "#";
    write(y_pid_parm.toUtf8());
}



QString Tcp_transmission::Address() const
{
    return address;
}
QString Tcp_transmission::Port() const
{
    return port;
}
void Tcp_transmission::setAddress(const QString &Address)
{
    address = Address;
//    qDebug(address.toUtf8());
}
void Tcp_transmission::setPort(const QString &Port)
{
    port = Port;
//    qDebug(port.toUtf8());
}





void Tcp_transmission::connecting(const QString &Address, const QString &Port)
{
    connectToHost(Address, Port.toUInt());
//    write("hello");
}

void Tcp_transmission::disconnect()
{
    disconnectFromHost();
}



void Tcp_transmission::connect_success()
{
    connect_state = "connected ^_^";
    emit Connect_StateChanged();
    qDebug("connected");
}

void Tcp_transmission::connect_fail()
{
    connect_state = "connecting...";
    emit Connect_StateChanged();
    qDebug("disconnected");
}




QString Tcp_transmission::Connect_State() const
{
    return connect_state;
}
void Tcp_transmission::setConnect_State(QString &Connect_State)
{
    Connect_State = connect_state;
}

//QString Tcp_transmission::success() const
//{
//    return connect_state;
//}

//QString Tcp_transmission::fail() const
//{
//    return connect_state;
//}

//void Tcp_transmission::setSuccess(const QString &success)
//{
//    Tcp_transmission::connect_state = "connected!!!";

//}
//void Tcp_transmission::setFail(const QString &fail)
//{
//    Tcp_transmission::connect_state = "connecting...";
//}




