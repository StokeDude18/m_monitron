/****************************************************************************
** Meta object code from reading C++ file 'm_monitron_0_0.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "m_monitron_0_0.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'm_monitron_0_0.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_m_monitron_0_0_t {
    QByteArrayData data[10];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_m_monitron_0_0_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_m_monitron_0_0_t qt_meta_stringdata_m_monitron_0_0 = {
    {
QT_MOC_LITERAL(0, 0, 14), // "m_monitron_0_0"
QT_MOC_LITERAL(1, 15, 26), // "on_b_Apply_Changes_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 39), // "on_cb_Module_Select_currentIn..."
QT_MOC_LITERAL(4, 83, 5), // "index"
QT_MOC_LITERAL(5, 89, 7), // "onFocus"
QT_MOC_LITERAL(6, 97, 8), // "hasFocus"
QT_MOC_LITERAL(7, 106, 14), // "cbIndexChanged"
QT_MOC_LITERAL(8, 121, 24), // "on_b_Calibration_clicked"
QT_MOC_LITERAL(9, 146, 17) // "on_b_exit_clicked"

    },
    "m_monitron_0_0\0on_b_Apply_Changes_clicked\0"
    "\0on_cb_Module_Select_currentIndexChanged\0"
    "index\0onFocus\0hasFocus\0cbIndexChanged\0"
    "on_b_Calibration_clicked\0on_b_exit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_m_monitron_0_0[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    1,   45,    2, 0x08 /* Private */,
       5,    1,   48,    2, 0x08 /* Private */,
       7,    1,   51,    2, 0x08 /* Private */,
       8,    0,   54,    2, 0x08 /* Private */,
       9,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void m_monitron_0_0::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        m_monitron_0_0 *_t = static_cast<m_monitron_0_0 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_b_Apply_Changes_clicked(); break;
        case 1: _t->on_cb_Module_Select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onFocus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->cbIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_b_Calibration_clicked(); break;
        case 5: _t->on_b_exit_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject m_monitron_0_0::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_m_monitron_0_0.data,
      qt_meta_data_m_monitron_0_0,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *m_monitron_0_0::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *m_monitron_0_0::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_m_monitron_0_0.stringdata0))
        return static_cast<void*>(const_cast< m_monitron_0_0*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int m_monitron_0_0::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
