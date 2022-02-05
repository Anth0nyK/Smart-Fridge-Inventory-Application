#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <login.h>
#include <inventorymodel.h>
#include <profileinfo.h>
#include <itemHelper.h>
//#include <tablemodel.h>
#include <itemmodel.h>
#include <fridgeHandler.h>
#include <orderHelper.h>
#include <ordermodel.h>
#include <suppliermodel.h>
#include <orderitemsmodel.h>
#include <orderdetailmodel.h>
#include <activityLogHelper.h>
#include <activitylogmodel.h>
#include <permissionmodel.h>
#include <permissionHelper.h>
#include <restaurantInfoHelper.h>
#include <usersmodel.h>
#include <usersManagementHelper.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<login>("login",1,0,"LoginClass");
    qmlRegisterType<inventoryModel>("inventorymodel",1,0,"InventoryModel");
    qmlRegisterType<profileinfo>("profileinfo",1,0,"ProfileHelper");
    qmlRegisterType<itemHelper>("iteminfo",1,0,"ItemHelper");
    qmlRegisterType<itemModel>("itemmodel",1,0,"ItemModel");
    qmlRegisterType<fridgeHandler>("fridgeHandler",1,0,"FridgeHandler");
    qmlRegisterType<orderHelper>("orderHelper",1,0,"OrderHelper");
    qmlRegisterType<orderModel>("ordermodel",1,0,"OrderModel");
    qmlRegisterType<supplierModel>("suppliermodel",1,0,"SupplierModel");
    qmlRegisterType<orderitemsmodel>("orderitemsmodel",1,0,"OrderItemsModel");
    qmlRegisterType<orderdetailModel>("orderdetailmodel",1,0,"OrderdetailModel");
    qmlRegisterType<activityLogHelper>("activityLogHelper",1,0,"ActivityLogHelper");
    qmlRegisterType<activitylogmodel>("activitylogmodel",1,0,"Activitylogmodel");
    qmlRegisterType<permissionModel>("permissionModel",1,0,"PermissionModel");
    qmlRegisterType<permissionHelper>("permissionHelper",1,0,"PermissionHelper");
    qmlRegisterType<restaurantinfoHelper>("restaurantinfoHelper",1,0,"RestaurantinfoHelper");
    qmlRegisterType<usersmodel>("usersmodel",1,0,"UsersModel");
    qmlRegisterType<usersManagementHelper>("usersManagementHelper",1,0,"UsersManagementHelper");

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
