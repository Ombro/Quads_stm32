#ifndef TCP_TRANSMISSION_H
#define TCP_TRANSMISSION_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QTcpSocket>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>

class Tcp_transmission : public QTcpSocket
{
    Q_OBJECT

    //tcp连接状态
    Q_PROPERTY(QString Connect_State READ Connect_State WRITE setConnect_State NOTIFY Connect_StateChanged)

    //pid参数
    Q_PROPERTY(QString shell_p READ shell_p WRITE setShell_p NOTIFY shell_pChanged)
    Q_PROPERTY(QString shell_i READ shell_i WRITE setShell_i NOTIFY shell_iChanged)
    Q_PROPERTY(QString core_p READ core_p WRITE setCore_p NOTIFY core_pChanged)
    Q_PROPERTY(QString core_i READ core_i WRITE setCore_i NOTIFY core_iChanged)
    Q_PROPERTY(QString core_d READ core_d WRITE setCore_d NOTIFY core_dChanged)
    Q_PROPERTY(QString Address READ Address WRITE setAddress NOTIFY AddressChanged)
    Q_PROPERTY(QString Port READ Port WRITE setPort NOTIFY PortChanged)

    //油门
    Q_PROPERTY(QString throttle READ throttle WRITE setThrottle NOTIFY throttleChanged)

    //方向
    Q_PROPERTY(QString x_dir READ x_dir WRITE setX_dir NOTIFY x_dirChanged)
    Q_PROPERTY(QString y_dir READ y_dir WRITE setY_dir NOTIFY y_dirChanged)

    //转向
    Q_PROPERTY(QString turn READ turn WRITE setTurn NOTIFY turnChanged)

public:
    explicit Tcp_transmission(QObject *parent = nullptr);
    ~Tcp_transmission();

    //pid参数
    QString shell_p() const;
    QString shell_i() const;
    QString core_p() const;
    QString core_i() const;
    QString core_d() const;
    void setShell_p(const QString &shell_p);
    void setShell_i(const QString &shell_i);
    void setCore_p(const QString &core_p);
    void setCore_i(const QString &core_p);
    void setCore_d(const QString &core_p);


    //tcp参数
    QString Address() const;
    QString Port() const;
    void setAddress(const QString &Address);
    void setPort(const QString &Port);

    //tcp连接状态
    QString Connect_State() const;
    void setConnect_State(QString &Connect_State);

    //油门
    QString throttle() const;
    void setThrottle(const QString &throttle);

    //方向
    QString x_dir() const;
    QString y_dir() const;
    void setX_dir(const QString &x_dir);
    void setY_dir(const QString &y_dir);

    //转向
    QString turn() const;
    void setTurn(const QString &turn);







    //延时
    void delay(unsigned int msec);

signals:
    void shell_pChanged();
    void shell_iChanged();
    void core_pChanged();
    void core_iChanged();
    void core_dChanged();

    void AddressChanged();
    void PortChanged();

    void Connect_StateChanged();

    void throttleChanged();

    void x_dirChanged();
    void y_dirChanged();

    void turnChanged();

public slots:

    void link_x_parm();
    void link_y_parm();
    void save_pidparm();

    void connecting(const QString &Address, const QString &Port);
    void disconnect();

    void connect_fail();
    void connect_success();

    void send_control_parm();

private:
    //单个pid参数
    QString value_shell_p;
    QString value_shell_i;
    QString value_core_p;
    QString value_core_i;
    QString value_core_d;

    //x、y轴pid数据包
    QString x_pid_parm;
    QString y_pid_parm;

    //tcp参数
    QString address;
    QString port;

    //tcp连接状态
    QString connect_state;

    //油门
    QString value_throttle;

    //x、y 方向
    QString stick_x_dir;
    QString stick_y_dir;

    //转向
    QString dir_turn;

    //控制参数
    QString control_parm;
};

#endif // TCP_TRANSMISSION_H
