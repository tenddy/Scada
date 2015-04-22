/****************************************************************************
** Meta object code from reading C++ file 'qscalesetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qscalesetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qscalesetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QScaleSetting_t {
    QByteArrayData data[7];
    char stringdata[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QScaleSetting_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QScaleSetting_t qt_meta_stringdata_QScaleSetting = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 29),
QT_MOC_LITERAL(2, 44, 0),
QT_MOC_LITERAL(3, 45, 32),
QT_MOC_LITERAL(4, 78, 26),
QT_MOC_LITERAL(5, 105, 28),
QT_MOC_LITERAL(6, 134, 29)
    },
    "QScaleSetting\0on_pushButton_addData_clicked\0"
    "\0on_pushButton_deleteData_clicked\0"
    "on_pushButton_save_clicked\0"
    "on_pushButton_cancel_clicked\0"
    "on_pushButton_default_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QScaleSetting[] = {

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
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QScaleSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QScaleSetting *_t = static_cast<QScaleSetting *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_addData_clicked(); break;
        case 1: _t->on_pushButton_deleteData_clicked(); break;
        case 2: _t->on_pushButton_save_clicked(); break;
        case 3: _t->on_pushButton_cancel_clicked(); break;
        case 4: _t->on_pushButton_default_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QScaleSetting::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QScaleSetting.data,
      qt_meta_data_QScaleSetting,  qt_static_metacall, 0, 0}
};


const QMetaObject *QScaleSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QScaleSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QScaleSetting.stringdata))
        return static_cast<void*>(const_cast< QScaleSetting*>(this));
    return QWidget::qt_metacast(_clname);
}

int QScaleSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
