/****************************************************************************
** Meta object code from reading C++ file 'edit_control_op.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "edit_control_op.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edit_control_op.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_edit_Control_OP_t {
    QByteArrayData data[4];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_edit_Control_OP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_edit_Control_OP_t qt_meta_stringdata_edit_Control_OP = {
    {
QT_MOC_LITERAL(0, 0, 15), // "edit_Control_OP"
QT_MOC_LITERAL(1, 16, 7), // "onFocus"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8) // "hasFocus"

    },
    "edit_Control_OP\0onFocus\0\0hasFocus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_edit_Control_OP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void edit_Control_OP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        edit_Control_OP *_t = static_cast<edit_Control_OP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onFocus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject edit_Control_OP::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_edit_Control_OP.data,
      qt_meta_data_edit_Control_OP,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *edit_Control_OP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *edit_Control_OP::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_edit_Control_OP.stringdata0))
        return static_cast<void*>(const_cast< edit_Control_OP*>(this));
    return QDialog::qt_metacast(_clname);
}

int edit_Control_OP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
