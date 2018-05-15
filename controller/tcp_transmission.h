#ifndef TCP_TRANSMISSION_H
#define TCP_TRANSMISSION_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QTcpSocket>

class Tcp_transmission : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString shell_p READ shell_p WRITE setShell_p NOTIFY shell_pChanged)
    Q_PROPERTY(QString shell_i READ shell_i WRITE setShell_i NOTIFY shell_iChanged)
    Q_PROPERTY(QString core_p READ core_p WRITE setCore_p NOTIFY core_pChanged)
    Q_PROPERTY(QString core_i READ core_i WRITE setCore_i NOTIFY core_iChanged)
    Q_PROPERTY(QString core_d READ core_d WRITE setCore_d NOTIFY core_dChanged)

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



signals:
    void shell_pChanged();
    void shell_iChanged();
    void core_pChanged();
    void core_iChanged();
    void core_dChanged();

public slots:
    void link_x_parm();
    void link_y_parm();

private:
    QString value_shell_p;
    QString value_shell_i;
    QString value_core_p;
    QString value_core_i;
    QString value_core_d;

    QString x_pid_parm;
    QString y_pid_parm;
};

#endif // TCP_TRANSMISSION_H
