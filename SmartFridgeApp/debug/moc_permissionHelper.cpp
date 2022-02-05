/****************************************************************************
** Meta object code from reading C++ file 'permissionHelper.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../permissionHelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'permissionHelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_permissionHelper_t {
    const uint offsetsAndSize[26];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_permissionHelper_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_permissionHelper_t qt_meta_stringdata_permissionHelper = {
    {
QT_MOC_LITERAL(0, 16), // "permissionHelper"
QT_MOC_LITERAL(17, 12), // "checkIfAdmin"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 6), // "userID"
QT_MOC_LITERAL(38, 19), // "checkViewPermission"
QT_MOC_LITERAL(58, 19), // "checkOpenPermission"
QT_MOC_LITERAL(78, 22), // "checkHistoryPermission"
QT_MOC_LITERAL(101, 20), // "checkOrderPermission"
QT_MOC_LITERAL(122, 6), // "update"
QT_MOC_LITERAL(129, 7), // "canView"
QT_MOC_LITERAL(137, 7), // "canOpen"
QT_MOC_LITERAL(145, 10), // "canHistory"
QT_MOC_LITERAL(156, 8) // "canOrder"

    },
    "permissionHelper\0checkIfAdmin\0\0userID\0"
    "checkViewPermission\0checkOpenPermission\0"
    "checkHistoryPermission\0checkOrderPermission\0"
    "update\0canView\0canOpen\0canHistory\0"
    "canOrder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_permissionHelper[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x02,    1 /* Public */,
       4,    1,   53,    2, 0x02,    3 /* Public */,
       5,    1,   56,    2, 0x02,    5 /* Public */,
       6,    1,   59,    2, 0x02,    7 /* Public */,
       7,    1,   62,    2, 0x02,    9 /* Public */,
       8,    5,   65,    2, 0x02,   11 /* Public */,

 // methods: parameters
    QMetaType::Int, QMetaType::QString,    3,
    QMetaType::Int, QMetaType::QString,    3,
    QMetaType::Int, QMetaType::QString,    3,
    QMetaType::Int, QMetaType::QString,    3,
    QMetaType::Int, QMetaType::QString,    3,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,   12,    3,

       0        // eod
};

void permissionHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<permissionHelper *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->checkIfAdmin((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->checkViewPermission((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->checkOpenPermission((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->checkHistoryPermission((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->checkOrderPermission((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->update((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject permissionHelper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_permissionHelper.offsetsAndSize,
    qt_meta_data_permissionHelper,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_permissionHelper_t
, QtPrivate::TypeAndForceComplete<permissionHelper, std::true_type>

, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>

>,
    nullptr
} };


const QMetaObject *permissionHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *permissionHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_permissionHelper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int permissionHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
