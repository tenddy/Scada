/****************************************************************************
** Meta object code from reading C++ file 'pageconfigdlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pageconfigdlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pageconfigdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PageConfigDlg_t {
    QByteArrayData data[12];
    char stringdata[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PageConfigDlg_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PageConfigDlg_t qt_meta_stringdata_PageConfigDlg = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 15),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 19),
QT_MOC_LITERAL(4, 51, 11),
QT_MOC_LITERAL(5, 63, 11),
QT_MOC_LITERAL(6, 75, 8),
QT_MOC_LITERAL(7, 84, 18),
QT_MOC_LITERAL(8, 103, 17),
QT_MOC_LITERAL(9, 121, 20),
QT_MOC_LITERAL(10, 142, 18),
QT_MOC_LITERAL(11, 161, 17)
    },
    "PageConfigDlg\0pageNameChanged\0\0"
    "pageMeterNumChanged\0preMeterNum\0"
    "curMeterNum\0lampFlag\0on_pageNameChanged\0"
    "on_pageRowChanged\0on_pageColumnChanged\0"
    "on_pageLampChecked\0on_lampNumChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PageConfigDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    3,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   59,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
       9,    1,   63,    2, 0x08 /* Private */,
      10,    1,   66,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void PageConfigDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PageConfigDlg *_t = static_cast<PageConfigDlg *>(_o);
        switch (_id) {
        case 0: _t->pageNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->pageMeterNumChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->on_pageNameChanged(); break;
        case 3: _t->on_pageRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pageColumnChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_pageLampChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_lampNumChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PageConfigDlg::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PageConfigDlg::pageNameChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (PageConfigDlg::*_t)(int , int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PageConfigDlg::pageMeterNumChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject PageConfigDlg::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PageConfigDlg.data,
      qt_meta_data_PageConfigDlg,  qt_static_metacall, 0, 0}
};


const QMetaObject *PageConfigDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PageConfigDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PageConfigDlg.stringdata))
        return static_cast<void*>(const_cast< PageConfigDlg*>(this));
    return QWidget::qt_metacast(_clname);
}

int PageConfigDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void PageConfigDlg::pageNameChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PageConfigDlg::pageMeterNumChanged(int _t1, int _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
