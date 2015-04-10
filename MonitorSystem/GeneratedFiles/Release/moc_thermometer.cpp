/****************************************************************************
** Meta object code from reading C++ file 'thermometer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Scada/src/thermometer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'thermometer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ThermoMeter_t {
    QByteArrayData data[22];
    char stringdata[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThermoMeter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThermoMeter_t qt_meta_stringdata_ThermoMeter = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 7),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 4),
QT_MOC_LITERAL(4, 26, 8),
QT_MOC_LITERAL(5, 35, 5),
QT_MOC_LITERAL(6, 41, 7),
QT_MOC_LITERAL(7, 49, 8),
QT_MOC_LITERAL(8, 58, 10),
QT_MOC_LITERAL(9, 69, 8),
QT_MOC_LITERAL(10, 78, 8),
QT_MOC_LITERAL(11, 87, 9),
QT_MOC_LITERAL(12, 97, 15),
QT_MOC_LITERAL(13, 113, 8),
QT_MOC_LITERAL(14, 122, 9),
QT_MOC_LITERAL(15, 132, 11),
QT_MOC_LITERAL(16, 144, 11),
QT_MOC_LITERAL(17, 156, 13),
QT_MOC_LITERAL(18, 170, 5),
QT_MOC_LITERAL(19, 176, 14),
QT_MOC_LITERAL(20, 191, 13),
QT_MOC_LITERAL(21, 205, 13)
    },
    "ThermoMeter\0setType\0\0Type\0setState\0"
    "State\0setName\0setTitle\0setChannel\0"
    "setValue\0setScale\0setCenter\0setMeterVisible\0"
    "setWidth\0setHeight\0setMinValue\0"
    "setMaxValue\0setScaleSteps\0Scale\0"
    "setScaleLength\0setScaleWidth\0setLiuidColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThermoMeter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x0a /* Public */,
       4,    1,  107,    2, 0x0a /* Public */,
       6,    1,  110,    2, 0x0a /* Public */,
       7,    1,  113,    2, 0x0a /* Public */,
       8,    1,  116,    2, 0x0a /* Public */,
       9,    1,  119,    2, 0x0a /* Public */,
      10,    1,  122,    2, 0x0a /* Public */,
      11,    1,  125,    2, 0x0a /* Public */,
      11,    2,  128,    2, 0x0a /* Public */,
      12,    1,  133,    2, 0x0a /* Public */,
      13,    1,  136,    2, 0x0a /* Public */,
      14,    1,  139,    2, 0x0a /* Public */,
      15,    1,  142,    2, 0x0a /* Public */,
      16,    1,  145,    2, 0x0a /* Public */,
      17,    2,  148,    2, 0x0a /* Public */,
      19,    2,  153,    2, 0x0a /* Public */,
      20,    2,  158,    2, 0x0a /* Public */,
      21,    1,  163,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 18, QMetaType::Double,    2,    2,
    QMetaType::Void, 0x80000000 | 18, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 18, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QColor,    2,

       0        // eod
};

void ThermoMeter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThermoMeter *_t = static_cast<ThermoMeter *>(_o);
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
        case 10: _t->setWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setMinValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setMaxValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setScaleSteps((*reinterpret_cast< Scale(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 15: _t->setScaleLength((*reinterpret_cast< Scale(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->setScaleWidth((*reinterpret_cast< Scale(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->setLiuidColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ThermoMeter::staticMetaObject = {
    { &QMeter::staticMetaObject, qt_meta_stringdata_ThermoMeter.data,
      qt_meta_data_ThermoMeter,  qt_static_metacall, 0, 0}
};


const QMetaObject *ThermoMeter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThermoMeter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThermoMeter.stringdata))
        return static_cast<void*>(const_cast< ThermoMeter*>(this));
    return QMeter::qt_metacast(_clname);
}

int ThermoMeter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMeter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
