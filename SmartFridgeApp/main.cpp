#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <login.h>
#include <inventorymodel.h>
#include <profileinfo.h>
#include <iteminfo.h>
//#include <tablemodel.h>
#include <itemmodel.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<login>("login",1,0,"LoginClass");
    qmlRegisterType<inventoryModel>("inventorymodel",1,0,"InventoryModel");
    qmlRegisterType<profileinfo>("profileinfo",1,0,"ProfileHelper");
    qmlRegisterType<iteminfo>("iteminfo",1,0,"ItemHelper");
    qmlRegisterType<itemModel>("itemmodel",1,0,"ItemModel");

    //qmlRegisterType<TableModel>("tablemodel",1,0,"TableModel");

    QQmlApplicationEngine engine;

    //const QUrl url(QStringLiteral("qrc:/main.qml"));
    const QUrl url(QStringLiteral("qrc:/Login.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
