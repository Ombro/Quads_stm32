/****************************************************************************
** Meta object code from reading C++ file 'tcp_transmission.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcp_transmission.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcp_transmission.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tcp_transmission_t {
    QByteArrayData data[14];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tcp_transmission_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tcp_transmission_t qt_meta_stringdata_Tcp_transmission = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Tcp_transmission"
QT_MOC_LITERAL(1, 17, 14), // "shell_pChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "shell_iChanged"
QT_MOC_LITERAL(4, 48, 13), // "core_pChanged"
QT_MOC_LITERAL(5, 62, 13), // "core_iChanged"
QT_MOC_LITERAL(6, 76, 13), // "core_dChanged"
QT_MOC_LITERAL(7, 90, 11), // "link_x_parm"
QT_MOC_LITERAL(8, 102, 11), // "link_y_parm"
QT_MOC_LITERAL(9, 114, 7), // "shell_p"
QT_MOC_LITERAL(10, 122, 7), // "shell_i"
QT_MOC_LITERAL(11, 130, 6), // "core_p"
QT_MOC_LITERAL(12, 137, 6), // "core_i"
QT_MOC_LITERAL(13, 144, 6) // "core_d"

    },
    "Tcp_transmission\0shell_pChanged\0\0"
    "shell_iChanged\0core_pChanged\0core_iChanged\0"
    "core_dChanged\0link_x_parm\0link_y_parm\0"
    "shell_p\0shell_i\0core_p\0core_i\0core_d"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tcp_transmission[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       5,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::QString, 0x00495103,
      10, QMetaType::QString, 0x00495103,
      11, QMetaType::QString, 0x00495103,
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void Tcp_transmission::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tcp_transmission *_t = static_cast<Tcp_transmission *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shell_pChanged(); break;
        case 1: _t->shell_iChanged(); break;
        case 2: _t->core_pChanged(); break;
        case 3: _t->core_iChanged(); break;
        case 4: _t->core_dChanged(); break;
        case 5: _t->link_x_parm(); break;
        case 6: _t->link_y_parm(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Tcp_transmission::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tcp_transmission::shell_pChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Tcp_transmission::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tcp_transmission::shell_iChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Tcp_transmission::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tcp_transmission::core_pChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Tcp_transmission::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tcp_transmission::core_iChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Tcp_transmission::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tcp_transmission::core_dChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Tcp_transmission *_t = static_cast<Tcp_transmission *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->shell_p(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->shell_i(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->core_p(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->core_i(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->core_d(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Tcp_transmission *_t = static_cast<Tcp_transmission *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setShell_p(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setShell_i(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setCore_p(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setCore_i(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setCore_d(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Tcp_transmission::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tcp_transmission.data,
      qt_meta_data_Tcp_transmission,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Tcp_transmission::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tcp_transmission::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tcp_transmission.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Tcp_transmission::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Tcp_transmission::shell_pChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Tcp_transmission::shell_iChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Tcp_transmission::core_pChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Tcp_transmission::core_iChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Tcp_transmission::core_dChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
