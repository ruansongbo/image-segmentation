/****************************************************************************
** Meta object code from reading C++ file 'detection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../detection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'detection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Detection_t {
    QByteArrayData data[8];
    char stringdata[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Detection_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Detection_t qt_meta_stringdata_Detection = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Detection"
QT_MOC_LITERAL(1, 10, 10), // "camera_set"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "template_set"
QT_MOC_LITERAL(4, 35, 12), // "paramter_set"
QT_MOC_LITERAL(5, 48, 14), // "connection_set"
QT_MOC_LITERAL(6, 63, 10), // "system_set"
QT_MOC_LITERAL(7, 74, 15) // "history_display"

    },
    "Detection\0camera_set\0\0template_set\0"
    "paramter_set\0connection_set\0system_set\0"
    "history_display"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Detection[] = {

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
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Detection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Detection *_t = static_cast<Detection *>(_o);
        switch (_id) {
        case 0: _t->camera_set(); break;
        case 1: _t->template_set(); break;
        case 2: _t->paramter_set(); break;
        case 3: _t->connection_set(); break;
        case 4: _t->system_set(); break;
        case 5: _t->history_display(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Detection::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Detection.data,
      qt_meta_data_Detection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Detection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Detection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Detection.stringdata))
        return static_cast<void*>(const_cast< Detection*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Detection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
