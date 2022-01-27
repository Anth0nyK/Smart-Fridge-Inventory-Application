/****************************************************************************
** Meta object code from reading C++ file 'tablemodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../tablemodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tablemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TableModel_t {
    const uint offsetsAndSize[10];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TableModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TableModel_t qt_meta_stringdata_TableModel = {
    {
QT_MOC_LITERAL(0, 10), // "TableModel"
QT_MOC_LITERAL(11, 11), // "QML.Element"
QT_MOC_LITERAL(23, 4), // "auto"
QT_MOC_LITERAL(28, 18), // "QML.AddedInVersion"
QT_MOC_LITERAL(47, 5) // "65281"

    },
    "TableModel\0QML.Element\0auto\0"
    "QML.AddedInVersion\0""65281"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TableModel[] = {

 // content:
      10,       // revision
       0,       // classname
       2,   14, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

       0        // eod
};

void TableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject TableModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_TableModel.offsetsAndSize,
    qt_meta_data_TableModel,
    qt_static_metacall,
    nullptr,
qt_metaTypeArray<
TableModel



>,
    nullptr
} };


const QMetaObject *TableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TableModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int TableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
