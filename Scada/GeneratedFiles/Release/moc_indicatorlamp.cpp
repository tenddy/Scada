/****************************************************************************
** Meta object code from reading C++ file 'indicatorlamp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/indicatorlamp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'indicatorlamp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IndicatorLamp_t {
    QByteArrayData data[17];
    char stringdata[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IndicatorLamp_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IndicatorLamp_t qt_meta_stringdata_IndicatorLamp = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 7),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 4),
QT_MOC_LITERAL(4, 28, 8),
QT_MOC_LITERAL(5, 37, 5),
QT_MOC_LITERAL(6, 43, 7),
QT_MOC_LITERAL(7, 51, 8),
QT_MOC_LITERAL(8, 60, 10),
QT_MOC_LITERAL(9, 71, 8),
QT_MOC_LITERAL(10, 80, 8),
QT_MOC_LITERAL(11, 89, 9),
QT_MOC_LITERAL(12, 99, 15),
QT_MOC_LITERAL(13, 115, 12),
QT_MOC_LITERAL(14, 128, 12),
QT_MOC_LITERAL(15, 141, 9),
QT_MOC_LITERAL(16, 151, 7)
    },
    "IndicatorLamp\0setType\0\0Type\0setState\0"
    "State\0setName\0setTitle\0setChannel\0"
    "setValue\0setScale\0setCenter\0setMeterVisible\0"
    "setLampColor\0stateChanged\0setRadius\0"
    "twinkle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IndicatorLamp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x0a /* Public */,
       4,    1,   87,    2, 0x0a /* Public */,
       6,    1,   90,    2, 0x0a /* Public */,
       7,    1,   93,    2, 0x0a /* Public */,
       8,    1,   96,    2, 0x0a /* Public */,
       9,    1,   99,    2, 0x0a /* Public */,
      10,    1,  102,    2, 0x0a /* Public */,
      11,    1,  105,    2, 0x0a /* Public */,
      11,    2,  108,    2, 0x0a /* Public */,
      12,    1,  113,    2, 0x0a /* Public */,
      13,    1,  116,    2, 0x0a /* Public */,
      14,    0,  119,    2, 0x0a /* Public */,
      15,    1,  120,    2, 0x0a /* Public */,
      16,    0,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void IndicatorLamp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IndicatorLamp *_t = static_cast<IndicatorLamp *>(_o);
        switch (_id) {
        case 0: _t->setType((*reinterpret_cast< Type(*)>(_a[1]))); break;
        case 1: _t->setState((*reinterpret_cast< State(*)>(_a[1]))); break;
        case 2: _t->setName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setChannel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setCenter((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 8: _t->setCenter((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 9: _t->setMeterVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setLampColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 11: _t->stateChanged(); break;
        case 12: _t->setRadius((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->twinkle(); break;
        default: ;
        }
    }
}

const QMetaObject IndicatorLamp::staticMetaObject = {
    { &QMeter::staticMetaObject, qt_meta_stringdata_IndicatorLamp.data,
      qt_meta_data_IndicatorLamp,  qt_static_metacall, 0, 0}
};


const QMetaObject *IndicatorLamp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IndicatorLamp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IndicatorLamp.stringdata))
        return static_cast<void*>(const_cast< IndicatorLamp*>(this));
    return QMeter::qt_metacast(_clname);
}

int IndicatorLamp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMeter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
