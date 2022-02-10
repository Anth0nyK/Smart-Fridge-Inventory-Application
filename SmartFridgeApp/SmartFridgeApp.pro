QT += quick
QT += sql
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        activitylogmodel.cpp \
        inventorymodel.cpp \
        itemmodel.cpp \
        main.cpp \
        noticemodel.cpp \
        order2model.cpp \
        orderdelivermodel.cpp \
        orderdetailmodel.cpp \
        orderitemsmodel.cpp \
        ordermodel.cpp \
        permissionmodel.cpp \
        suppliermodel.cpp \
        usersmodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    activityLogHelper.h \
    activitylogmodel.h \
    fridgeHandler.h \
    inventorymodel.h \
    itemHelper.h \
    itemmodel.h \
    login.h \
    noticeHelper.h \
    noticemodel.h \
    order2model.h \
    orderHelper.h \
    orderdelivermodel.h \
    orderdetailmodel.h \
    orderitemsmodel.h \
    ordermodel.h \
    permissionHelper.h \
    permissionmodel.h \
    profileinfo.h \
    reorderHelper.h \
    restaurantInfoHelper.h \
    suppliermodel.h \
    usersManagementHelper.h \
    usersmodel.h
