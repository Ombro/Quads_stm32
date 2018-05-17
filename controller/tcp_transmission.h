#ifndef TCP_TRANSMISSION_H
#define TCP_TRANSMISSION_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QTcpSocket>


class Tcp_transmission : public QTcpSocket
{
    Q_OBJECT
    Q_PROPERTY(QString shell_p READ shell_p WRITE setShell_p NOTIFY shell_pChanged)
    Q_PROPERTY(QString shell_i READ shell_i WRITE setShell_i NOTIFY shell_iChanged)
    Q_PROPERTY(QString core_p READ core_p WRITE setCore_p NOTIFY core_pChanged)
    Q_PROPERTY(QString core_i READ core_i WRITE setCore_i NOTIFY core_iChanged)
    Q_PROPERTY(QString core_d READ core_d WRITE setCore_d NOTIFY core_dChanged)
    Q_PROPERTY(QString Address READ Address WRITE setAddress NOTIFY AddressChanged)
    Q_PROPERTY(QString Port READ Port WRITE setPort NOTIFY PortChanged)

    Q_PROPERTY(QString Connect_State READ Connect_State WRITE setConnect_State NOTIFY Connect_StateChanged)


public:
    explicit Tcp_transmission(QObject *parent = nullptr);
    ~Tcp_transmission();

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

    QString Address() const;
    QString Port() const;
    void setAddress(const QString &Address);
    void setPort(const QString &Port);


    QString Connect_State() const;
    void setConnect_State(QString &Connect_State);
//    QString success() const;
//    QString fail() const;
//    void setSuccess(const QString &success);
//    void setFail(const QString &fail);


signals:
    void shell_pChanged();
    void shell_iChanged();
    void core_pChanged();
    void core_iChanged();
    void core_dChanged();

    void AddressChanged();
    void PortChanged();

    void Connect_StateChanged();

public slots:

    void link_x_parm();
    void link_y_parm();

    void connecting(const QString &Address, const QString &Port);
    void disconnect();

    void connect_fail();
    void connect_success();

private:
    QString value_shell_p;
    QString value_shell_i;
    QString value_core_p;
    QString value_core_i;
    QString value_core_d;

    QString x_pid_parm;
    QString y_pid_parm;

    QString address;
    QString port;

    QString connect_state;


};

#endif // TCP_TRANSMISSION_H
