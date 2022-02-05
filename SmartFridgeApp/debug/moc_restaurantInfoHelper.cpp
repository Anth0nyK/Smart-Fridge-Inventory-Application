/****************************************************************************
** Meta object code from reading C++ file 'restaurantInfoHelper.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../restaurantInfoHelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'restaurantInfoHelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_restaurantinfoHelper_t {
    const uint offsetsAndSize[34];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_restaurantinfoHelper_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_restaurantinfoHelper_t qt_meta_stringdata_restaurantinfoHelper = {
    {
QT_MOC_LITERAL(0, 20), // "restaurantinfoHelper"
QT_MOC_LITERAL(21, 6), // "update"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 4), // "name"
QT_MOC_LITERAL(34, 8), // "address1"
QT_MOC_LITERAL(43, 8), // "address2"
QT_MOC_LITERAL(52, 8), // "address3"
QT_MOC_LITERAL(61, 3), // "tel"
QT_MOC_LITERAL(65, 8), // "fridgeID"
QT_MOC_LITERAL(74, 7), // "getName"
QT_MOC_LITERAL(82, 11), // "getAddress1"
QT_MOC_LITERAL(94, 11), // "getAddress2"
QT_MOC_LITERAL(106, 11), // "getAddress3"
QT_MOC_LITERAL(118, 6), // "getTel"
QT_MOC_LITERAL(125, 7), // "canView"
QT_MOC_LITERAL(133, 7), // "canOpen"
QT_MOC_LITERAL(141, 6) // "userID"

    },
    "restaurantinfoHelper\0update\0\0name\0"
    "address1\0address2\0address3\0tel\0fridgeID\0"
    "getName\0getAddress1\0getAddress2\0"
    "getAddress3\0getTel\0canView\0canOpen\0"
    "userID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_restaurantinfoHelper[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    6,   56,    2, 0x02,    1 /* Public */,
       9,    1,   69,    2, 0x02,    8 /* Public */,
      10,    1,   72,    2, 0x02,   10 /* Public */,
      11,    1,   75,    2, 0x02,   12 /* Public */,
      12,    1,   78,    2, 0x02,   14 /* Public */,
      13,    1,   81,    2, 0x02,   16 /* Public */,
       1,    3,   84,    2, 0x02,   18 /* Public */,

 // methods: parameters
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,
    QMetaType::QString, QMetaType::QString,    8,
    QMetaType::QString, QMetaType::QString,    8,
    QMetaType::QString, QMetaType::QString,    8,
    QMetaType::QString, QMetaType::QString,    8,
    QMetaType::QString, QMetaType::QString,    8,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,   15,   16,

       0        // eod
};

void restaurantinfoHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<restaurantinfoHelper *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->update((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->getName((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->getAddress1((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->getAddress2((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getAddress3((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getTel((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->update((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject restaurantinfoHelper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_restaurantinfoHelper.offsetsAndSize,
    qt_meta_data_restaurantinfoHelper,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_restaurantinfoHelper_t
, QtPrivate::TypeAndForceComplete<restaurantinfoHelper, std::true_type>

, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>

>,
    nullptr
} };


const QMetaObject *restaurantinfoHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *restaurantinfoHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_restaurantinfoHelper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int restaurantinfoHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
