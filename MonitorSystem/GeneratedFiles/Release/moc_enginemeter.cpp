/****************************************************************************
** Meta object code from reading C++ file 'enginemeter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Scada/src/enginemeter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enginemeter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EngineMeter_t {
    QByteArrayData data[5];
    char stringdata[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EngineMeter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EngineMeter_t qt_meta_stringdata_EngineMeter = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 10),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 4),
QT_MOC_LITERAL(4, 29, 11)
    },
    "EngineMeter\0setRuntime\0\0time\0changeValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EngineMeter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       1,    0,   32,    2, 0x08 /* Private */,
       4,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EngineMeter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EngineMeter *_t = static_cast<EngineMeter *>(_o);
        switch (_id) {
        case 0: _t->setRuntime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setRuntime(); break;
        case 2: _t->changeValue(); break;
        default: ;
        }
    }
}

const QMetaObject EngineMeter::staticMetaObject = {
    { &QBaseMeter::staticMetaObject, qt_meta_stringdata_EngineMeter.data,
      qt_meta_data_EngineMeter,  qt_static_metacall, 0, 0}
};


const QMetaObject *EngineMeter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EngineMeter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EngineMeter.stringdata))
        return static_cast<void*>(const_cast< EngineMeter*>(this));
    return QBaseMeter::qt_metacast(_clname);
}

int EngineMeter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QBaseMeter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
