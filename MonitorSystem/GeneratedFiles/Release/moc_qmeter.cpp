/****************************************************************************
** Meta object code from reading C++ file 'qmeter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Scada/src/qmeter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmeter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMeter_t {
    QByteArrayData data[16];
    char stringdata[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMeter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMeter_t qt_meta_stringdata_QMeter = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 12),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 12),
QT_MOC_LITERAL(4, 34, 15),
QT_MOC_LITERAL(5, 50, 7),
QT_MOC_LITERAL(6, 58, 4),
QT_MOC_LITERAL(7, 63, 8),
QT_MOC_LITERAL(8, 72, 5),
QT_MOC_LITERAL(9, 78, 7),
QT_MOC_LITERAL(10, 86, 8),
QT_MOC_LITERAL(11, 95, 10),
QT_MOC_LITERAL(12, 106, 8),
QT_MOC_LITERAL(13, 115, 8),
QT_MOC_LITERAL(14, 124, 9),
QT_MOC_LITERAL(15, 134, 15)
    },
    "QMeter\0ScaleChanged\0\0stateChanged\0"
    "visiableChanged\0setType\0Type\0setState\0"
    "State\0setName\0setTitle\0setChannel\0"
    "setValue\0setScale\0setCenter\0setMeterVisible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMeter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    0,   82,    2, 0x06 /* Public */,
       4,    0,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   84,    2, 0x0a /* Public */,
       7,    1,   87,    2, 0x0a /* Public */,
       9,    1,   90,    2, 0x0a /* Public */,
      10,    1,   93,    2, 0x0a /* Public */,
      11,    1,   96,    2, 0x0a /* Public */,
      12,    1,   99,    2, 0x0a /* Public */,
      13,    1,  102,    2, 0x0a /* Public */,
      14,    1,  105,    2, 0x0a /* Public */,
      14,    2,  108,    2, 0x0a /* Public */,
      15,    1,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void QMeter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMeter *_t = static_cast<QMeter *>(_o);
        switch (_id) {
        case 0: _t->ScaleChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->stateChanged(); break;
        case 2: _t->visiableChanged(); break;
        case 3: _t->setType((*reinterpret_cast< Type(*)>(_a[1]))); break;
        case 4: _t->setState((*reinterpret_cast< State(*)>(_a[1]))); break;
        case 5: _t->setName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setChannel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->setCenter((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 11: _t->setCenter((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 12: _t->setMeterVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QMeter::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMeter::ScaleChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (QMeter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMeter::stateChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (QMeter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMeter::visiableChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject QMeter::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QMeter.data,
      qt_meta_data_QMeter,  qt_static_metacall, 0, 0}
};


const QMetaObject *QMeter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMeter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMeter.stringdata))
        return static_cast<void*>(const_cast< QMeter*>(this));
    return QWidget::qt_metacast(_clname);
}

int QMeter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void QMeter::ScaleChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QMeter::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QMeter::visiableChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
