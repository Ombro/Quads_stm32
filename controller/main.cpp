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
    
//    qmlRegisterType<Test>("Qt.Test_class", 1, 0, "Test");



    QQmlApplicationEngine engine;



//    Test qmltest;
//    context ->setContextProperty("QMltest", &qmltest);
//    qmltest.setData("hello");
    QQmlContext* context = engine.rootContext();
    Tcp_transmission tcp;
    context ->setContextProperty("TCP", &tcp);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
