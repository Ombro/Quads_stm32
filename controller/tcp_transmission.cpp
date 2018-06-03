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

    stick_x_dir = "0";
    stick_y_dir = "0";
    value_throttle = "0";
}

Tcp_transmission::~Tcp_transmission()
{

}


/************************* TCP连接 *************************/
//tcp设置
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




//建立/断开tcp连接
void Tcp_transmission::connecting(const QString &Address, const QString &Port)
{
    connectToHost(Address, Port.toUInt());
//    write("hello");
}

void Tcp_transmission::disconnect()
{
    disconnectFromHost();
}


//判断tcp连接状态
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
/**********************************************************/

/*********************** PID参数设置 ***********************/
//获取设置的5个 PID 参数
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


//连接pid参数字符串，打包数据
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

//发送保存pid参数命令
void Tcp_transmission::save_pidparm()
{
    QString temp = "@*#";
    write(temp.toUtf8());
}
/**********************************************************/



/************************** 控制 **************************/
//油门
QString Tcp_transmission::throttle() const
{
    return value_throttle;
}

void Tcp_transmission::setThrottle(const QString &throttle)
{
    value_throttle = throttle;
}

//方向控制
QString Tcp_transmission::x_dir() const
{
    return stick_x_dir;
}
QString Tcp_transmission::y_dir() const
{
    return stick_y_dir;
}
void Tcp_transmission::setX_dir(const QString &x_dir)
{
    stick_x_dir = x_dir;
}
void Tcp_transmission::setY_dir(const QString &y_dir)
{
    stick_y_dir = y_dir;
}

//转向
QString Tcp_transmission::turn() const
{
    return dir_turn;
}
void Tcp_transmission::setTurn(const QString &turn)
{
    dir_turn = turn;
}

//发送控制数据包
void Tcp_transmission::send_control_parm()
{
    control_parm =  "@M"            +       \
                    value_throttle  + "," + \
                    stick_x_dir     + "," + \
                    stick_y_dir     + "," + \
                    dir_turn        +       \
                    "#";
    write(control_parm.toUtf8());
    delay(80);
}


/*********************************************************/


/************************** 延时 **************************/
void Tcp_transmission::delay(unsigned int msec)
{
    QTime _Timer = QTime::currentTime();
    QTime _NowTimer;
    do{
         _NowTimer=QTime::currentTime();
    }while (_Timer.msecsTo(_NowTimer)<=msec);
}
/*********************************************************/
