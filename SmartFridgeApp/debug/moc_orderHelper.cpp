/****************************************************************************
** Meta object code from reading C++ file 'orderHelper.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../orderHelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orderHelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_orderHelper_t {
    const uint offsetsAndSize[22];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_orderHelper_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_orderHelper_t qt_meta_stringdata_orderHelper = {
    {
QT_MOC_LITERAL(0, 11), // "orderHelper"
QT_MOC_LITERAL(12, 7), // "getUUID"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 11), // "createOrder"
QT_MOC_LITERAL(33, 7), // "orderID"
QT_MOC_LITERAL(41, 8), // "fridgeID"
QT_MOC_LITERAL(50, 12), // "supplierName"
QT_MOC_LITERAL(63, 13), // "supplierEmail"
QT_MOC_LITERAL(77, 14), // "addItemToOrder"
QT_MOC_LITERAL(92, 8), // "itemName"
QT_MOC_LITERAL(101, 9) // "itemCount"

    },
    "orderHelper\0getUUID\0\0createOrder\0"
    "orderID\0fridgeID\0supplierName\0"
    "supplierEmail\0addItemToOrder\0itemName\0"
    "itemCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_orderHelper[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x02,    1 /* Public */,
       3,    4,   33,    2, 0x02,    2 /* Public */,
       8,    3,   42,    2, 0x02,    7 /* Public */,

 // methods: parameters
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    9,   10,

       0        // eod
};

void orderHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<orderHelper *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QString _r = _t->getUUID();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->createOrder((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: { int _r = _t->addItemToOrder((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject orderHelper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_orderHelper.offsetsAndSize,
    qt_meta_data_orderHelper,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_orderHelper_t
, QtPrivate::TypeAndForceComplete<orderHelper, std::true_type>

, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>

>,
    nullptr
} };


const QMetaObject *orderHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *orderHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_orderHelper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int orderHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE