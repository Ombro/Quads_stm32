#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMetaObject>
#include <QObject>
#include <QtQml>
#include "Test.h"
#include <QQmlContext>
#include "tcp_transmission.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;




    QQmlContext* context = engine.rootContext();
    Tcp_transmission tcp;
    context ->setContextProperty("TCP", &tcp);

    QObject::connect(&tcp, SIGNAL(connected()), &tcp, SLOT(connect_success()));
    QObject::connect(&tcp, SIGNAL(disconnected()), &tcp, SLOT(connect_fail()));


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
