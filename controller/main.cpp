#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMetaObject>
#include <QObject>
#include <QtQml>
#include "Test.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<Test>("Qt.Test_class", 1, 0, "Test");

//    Test *a = new Test();

//    QObject::connect(a, SIGNAL(data_Changed()), a, SLOT(data_opt()));

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
