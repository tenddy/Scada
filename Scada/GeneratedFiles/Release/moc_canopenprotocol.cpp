/****************************************************************************
** Meta object code from reading C++ file 'canopenprotocol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CanOpen/canopenprotocol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canopenprotocol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CanOpenProtocol_t {
    QByteArrayData data[9];
    char stringdata[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CanOpenProtocol_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CanOpenProtocol_t qt_meta_stringdata_CanOpenProtocol = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 9),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 3),
QT_MOC_LITERAL(4, 31, 4),
QT_MOC_LITERAL(5, 36, 9),
QT_MOC_LITERAL(6, 46, 4),
QT_MOC_LITERAL(7, 51, 11),
QT_MOC_LITERAL(8, 63, 8)
    },
    "CanOpenProtocol\0readReady\0\0run\0time\0"
    "eventFlag\0stop\0receiveData\0saveData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CanOpenProtocol[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   50,    2, 0x0a /* Public */,
       3,    1,   55,    2, 0x2a /* Public | MethodCloned */,
       3,    0,   58,    2, 0x2a /* Public | MethodCloned */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    4,    5,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CanOpenProtocol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CanOpenProtocol *_t = static_cast<CanOpenProtocol *>(_o);
        switch (_id) {
        case 0: _t->readReady(); break;
        case 1: _t->run((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->run((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->run(); break;
        case 4: _t->stop(); break;
        case 5: _t->receiveData(); break;
        case 6: _t->saveData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CanOpenProtocol::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanOpenProtocol::readReady)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CanOpenProtocol::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CanOpenProtocol.data,
      qt_meta_data_CanOpenProtocol,  qt_static_metacall, 0, 0}
};


const QMetaObject *CanOpenProtocol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CanOpenProtocol::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CanOpenProtocol.stringdata))
        return static_cast<void*>(const_cast< CanOpenProtocol*>(this));
    return QObject::qt_metacast(_clname);
}

int CanOpenProtocol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CanOpenProtocol::readReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
