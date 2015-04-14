/****************************************************************************
** Meta object code from reading C++ file 'indicatorconfigdlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../indicatorconfigdlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'indicatorconfigdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IndicatorConfigDlg_t {
    QByteArrayData data[13];
    char stringdata[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IndicatorConfigDlg_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IndicatorConfigDlg_t qt_meta_stringdata_IndicatorConfigDlg = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 20),
QT_MOC_LITERAL(2, 40, 0),
QT_MOC_LITERAL(3, 41, 13),
QT_MOC_LITERAL(4, 55, 15),
QT_MOC_LITERAL(5, 71, 14),
QT_MOC_LITERAL(6, 86, 23),
QT_MOC_LITERAL(7, 110, 17),
QT_MOC_LITERAL(8, 128, 14),
QT_MOC_LITERAL(9, 143, 13),
QT_MOC_LITERAL(10, 157, 17),
QT_MOC_LITERAL(11, 175, 17),
QT_MOC_LITERAL(12, 193, 16)
    },
    "IndicatorConfigDlg\0indicatorNameChanged\0"
    "\0posNumChanged\0setMeterPageNum\0"
    "setMeterPosNum\0on_titleLineEditChanged\0"
    "on_titleVisiabled\0on_pageChanged\0"
    "on_posChanged\0on_centerXChanged\0"
    "on_centerYChanged\0on_radiusChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IndicatorConfigDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    2,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   77,    2, 0x0a /* Public */,
       5,    1,   80,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    1,   84,    2, 0x0a /* Public */,
       8,    1,   87,    2, 0x0a /* Public */,
       9,    0,   90,    2, 0x0a /* Public */,
      10,    1,   91,    2, 0x0a /* Public */,
      11,    1,   94,    2, 0x0a /* Public */,
      12,    1,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void IndicatorConfigDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IndicatorConfigDlg *_t = static_cast<IndicatorConfigDlg *>(_o);
        switch (_id) {
        case 0: _t->indicatorNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->posNumChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setMeterPageNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setMeterPosNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_titleLineEditChanged(); break;
        case 5: _t->on_titleVisiabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_pageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_posChanged(); break;
        case 8: _t->on_centerXChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_centerYChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_radiusChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IndicatorConfigDlg::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IndicatorConfigDlg::indicatorNameChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (IndicatorConfigDlg::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IndicatorConfigDlg::posNumChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject IndicatorConfigDlg::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IndicatorConfigDlg.data,
      qt_meta_data_IndicatorConfigDlg,  qt_static_metacall, 0, 0}
};


const QMetaObject *IndicatorConfigDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IndicatorConfigDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IndicatorConfigDlg.stringdata))
        return static_cast<void*>(const_cast< IndicatorConfigDlg*>(this));
    return QWidget::qt_metacast(_clname);
}

int IndicatorConfigDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void IndicatorConfigDlg::indicatorNameChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IndicatorConfigDlg::posNumChanged(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
