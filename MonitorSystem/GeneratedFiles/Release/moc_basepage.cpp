/****************************************************************************
** Meta object code from reading C++ file 'basepage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Scada/src/basepage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BasePage_t {
    QByteArrayData data[9];
    char stringdata[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BasePage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BasePage_t qt_meta_stringdata_BasePage = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 6),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 9),
QT_MOC_LITERAL(4, 27, 11),
QT_MOC_LITERAL(5, 39, 15),
QT_MOC_LITERAL(6, 55, 12),
QT_MOC_LITERAL(7, 68, 11),
QT_MOC_LITERAL(8, 80, 4)
    },
    "BasePage\0setRow\0\0setColumn\0setMaxLamps\0"
    "setLampsEnabled\0updateLayout\0setPageName\0"
    "name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BasePage[] = {

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
       1,    1,   44,    2, 0x0a /* Public */,
       3,    1,   47,    2, 0x0a /* Public */,
       4,    1,   50,    2, 0x0a /* Public */,
       5,    1,   53,    2, 0x0a /* Public */,
       6,    0,   56,    2, 0x0a /* Public */,
       7,    1,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void BasePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BasePage *_t = static_cast<BasePage *>(_o);
        switch (_id) {
        case 0: _t->setRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setMaxLamps((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setLampsEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->updateLayout(); break;
        case 5: _t->setPageName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject BasePage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BasePage.data,
      qt_meta_data_BasePage,  qt_static_metacall, 0, 0}
};


const QMetaObject *BasePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BasePage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BasePage.stringdata))
        return static_cast<void*>(const_cast< BasePage*>(this));
    return QWidget::qt_metacast(_clname);
}

int BasePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
