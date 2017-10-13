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
struct qt_meta_stringdata_detection_t {
    QByteArrayData data[9];
    char stringdata[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_detection_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_detection_t qt_meta_stringdata_detection = {
    {
QT_MOC_LITERAL(0, 0, 9), // "detection"
QT_MOC_LITERAL(1, 10, 10), // "openCamera"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "readFrame"
QT_MOC_LITERAL(4, 32, 11), // "closeCamera"
QT_MOC_LITERAL(5, 44, 14), // "takingPictures"
QT_MOC_LITERAL(6, 59, 10), // "Mat2QImage"
QT_MOC_LITERAL(7, 70, 7), // "cv::Mat"
QT_MOC_LITERAL(8, 78, 5) // "cvImg"

    },
    "detection\0openCamera\0\0readFrame\0"
    "closeCamera\0takingPictures\0Mat2QImage\0"
    "cv::Mat\0cvImg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_detection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QImage, 0x80000000 | 7,    8,

       0        // eod
};

void detection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        detection *_t = static_cast<detection *>(_o);
        switch (_id) {
        case 0: _t->openCamera(); break;
        case 1: _t->readFrame(); break;
        case 2: _t->closeCamera(); break;
        case 3: _t->takingPictures(); break;
        case 4: { QImage _r = _t->Mat2QImage((*reinterpret_cast< cv::Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject detection::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_detection.data,
      qt_meta_data_detection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *detection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *detection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_detection.stringdata))
        return static_cast<void*>(const_cast< detection*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int detection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
