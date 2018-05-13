#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QQuickItem>


class test : public QObject
{
    Q_OBJECT


//    Q_PROPERTY(float data_shell_p READ data_shell_p NOTIFY shell_p_change)
//    Q_PROPERTY(float data_shell_i READ data_shell_p NOTIFY shell_i_change)
//    Q_PROPERTY(float data_core_p READ data_core_p NOTIFY core_p_change)
//    Q_PROPERTY(float data_core_i READ data_core_i NOTIFY core_i_change)
//    Q_PROPERTY(float data_core_d READ data_core_d NOTIFY core_d_change)
    Q_PROPERTY(float data_shell_p READ get_shell_p)
    Q_PROPERTY(float data_shell_i READ get_shell_p)
    Q_PROPERTY(float data_core_p READ get_core_p)
    Q_PROPERTY(float data_core_i READ get_core_i)
    Q_PROPERTY(float data_core_d READ get_core_d)

    Q_PROPERTY(Qstring pid_parm READ pid_parm NOTIFY link)

public:
    explicit test(QObject *parent = nullptr);
    ~test();

    float get_shell_p();
    float get_shell_i();
    float get_core_p();
    float get_core_i();
    float get_core_d();



signals:
//    void shell_p_change();
//    void shell_i_change();
//    void core_p_change();
//    void core_i_change();
//    void core_d_change();
    void link();
public slots:
//    void send_data();
    void print_data();

private:
    float data_shell_p;
    float data_shell_i;
    float data_core_p;
    float data_core_i;
    float data_core_d;

};

#endif // TEST_H
