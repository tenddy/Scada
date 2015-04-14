/****************************************************************************
** Meta object code from reading C++ file 'pageconfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pageconfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pageconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PageConfig_t {
    QByteArrayData data[17];
    char stringdata[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PageConfig_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PageConfig_t qt_meta_stringdata_PageConfig = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 10),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 20),
QT_MOC_LITERAL(4, 44, 24),
QT_MOC_LITERAL(5, 69, 16),
QT_MOC_LITERAL(6, 86, 17),
QT_MOC_LITERAL(7, 104, 18),
QT_MOC_LITERAL(8, 123, 17),
QT_MOC_LITERAL(9, 141, 7),
QT_MOC_LITERAL(10, 149, 8),
QT_MOC_LITERAL(11, 158, 13),
QT_MOC_LITERAL(12, 172, 11),
QT_MOC_LITERAL(13, 184, 11),
QT_MOC_LITERAL(14, 196, 8),
QT_MOC_LITERAL(15, 205, 14),
QT_MOC_LITERAL(16, 220, 8)
    },
    "PageConfig\0updatePage\0\0on_tabWidgetSelected\0"
    "on_treeWidgetItemClicked\0QTreeWidgetItem*\0"
    "on_updatePageName\0on_updateMeterName\0"
    "on_meterPosAdjust\0current\0previous\0"
    "on_pageAdjust\0preMeterNum\0curMeterNum\0"
    "lampFlag\0savePageConfig\0filepath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PageConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    1,   60,    2, 0x0a /* Public */,
       4,    1,   63,    2, 0x0a /* Public */,
       6,    1,   66,    2, 0x0a /* Public */,
       7,    1,   69,    2, 0x0a /* Public */,
       8,    2,   72,    2, 0x0a /* Public */,
      11,    3,   77,    2, 0x0a /* Public */,
      15,    1,   84,    2, 0x0a /* Public */,
      15,    0,   87,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   12,   13,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,

       0        // eod
};

void PageConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PageConfig *_t = static_cast<PageConfig *>(_o);
        switch (_id) {
        case 0: _t->updatePage(); break;
        case 1: _t->on_tabWidgetSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_treeWidgetItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_updatePageName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_updateMeterName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_meterPosAdjust((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->on_pageAdjust((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 7: _t->savePageConfig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->savePageConfig(); break;
        default: ;
        }
    }
}

const QMetaObject PageConfig::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PageConfig.data,
      qt_meta_data_PageConfig,  qt_static_metacall, 0, 0}
};


const QMetaObject *PageConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PageConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PageConfig.stringdata))
        return static_cast<void*>(const_cast< PageConfig*>(this));
    return QWidget::qt_metacast(_clname);
}

int PageConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
