/****************************************************************************
** Meta object code from reading C++ file 'MyLCDNumber.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyLCDNumber.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyLCDNumber.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyLCDNumber_t {
    QByteArrayData data[22];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyLCDNumber_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyLCDNumber_t qt_meta_stringdata_MyLCDNumber = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MyLCDNumber"
QT_MOC_LITERAL(1, 12, 22), // "desactivarValorAbsolut"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 15), // "valorPerDefecte"
QT_MOC_LITERAL(4, 52, 5), // "valor"
QT_MOC_LITERAL(5, 58, 10), // "enviarAOp1"
QT_MOC_LITERAL(6, 69, 8), // "valorRes"
QT_MOC_LITERAL(7, 78, 15), // "evniarInfoError"
QT_MOC_LITERAL(8, 94, 3), // "str"
QT_MOC_LITERAL(9, 98, 16), // "enviarEstilError"
QT_MOC_LITERAL(10, 115, 11), // "assignarOp1"
QT_MOC_LITERAL(11, 127, 11), // "assignarOp2"
QT_MOC_LITERAL(12, 139, 4), // "suma"
QT_MOC_LITERAL(13, 144, 5), // "resta"
QT_MOC_LITERAL(14, 150, 13), // "multiplicacio"
QT_MOC_LITERAL(15, 164, 7), // "divisio"
QT_MOC_LITERAL(16, 172, 19), // "canviarValorAbsolut"
QT_MOC_LITERAL(17, 192, 8), // "acumular"
QT_MOC_LITERAL(18, 201, 5), // "reset"
QT_MOC_LITERAL(19, 207, 5), // "error"
QT_MOC_LITERAL(20, 213, 5), // "tipus"
QT_MOC_LITERAL(21, 219, 10) // "resetError"

    },
    "MyLCDNumber\0desactivarValorAbsolut\0\0"
    "valorPerDefecte\0valor\0enviarAOp1\0"
    "valorRes\0evniarInfoError\0str\0"
    "enviarEstilError\0assignarOp1\0assignarOp2\0"
    "suma\0resta\0multiplicacio\0divisio\0"
    "canviarValorAbsolut\0acumular\0reset\0"
    "error\0tipus\0resetError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyLCDNumber[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    1,   95,    2, 0x06 /* Public */,
       5,    1,   98,    2, 0x06 /* Public */,
       7,    1,  101,    2, 0x06 /* Public */,
       9,    1,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  107,    2, 0x0a /* Public */,
      11,    1,  110,    2, 0x0a /* Public */,
      12,    0,  113,    2, 0x0a /* Public */,
      13,    0,  114,    2, 0x0a /* Public */,
      14,    0,  115,    2, 0x0a /* Public */,
      15,    0,  116,    2, 0x0a /* Public */,
      16,    0,  117,    2, 0x0a /* Public */,
      17,    0,  118,    2, 0x0a /* Public */,
      18,    0,  119,    2, 0x0a /* Public */,
      19,    1,  120,    2, 0x0a /* Public */,
      21,    0,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,

       0        // eod
};

void MyLCDNumber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyLCDNumber *_t = static_cast<MyLCDNumber *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->desactivarValorAbsolut(); break;
        case 1: _t->valorPerDefecte((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->enviarAOp1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->evniarInfoError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->enviarEstilError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->assignarOp1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->assignarOp2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->suma(); break;
        case 8: _t->resta(); break;
        case 9: _t->multiplicacio(); break;
        case 10: _t->divisio(); break;
        case 11: _t->canviarValorAbsolut(); break;
        case 12: _t->acumular(); break;
        case 13: _t->reset(); break;
        case 14: _t->error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->resetError(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyLCDNumber::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyLCDNumber::desactivarValorAbsolut)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyLCDNumber::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyLCDNumber::valorPerDefecte)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyLCDNumber::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyLCDNumber::enviarAOp1)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyLCDNumber::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyLCDNumber::evniarInfoError)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MyLCDNumber::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyLCDNumber::enviarEstilError)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MyLCDNumber::staticMetaObject = {
    { &QLCDNumber::staticMetaObject, qt_meta_stringdata_MyLCDNumber.data,
      qt_meta_data_MyLCDNumber,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyLCDNumber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyLCDNumber::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyLCDNumber.stringdata0))
        return static_cast<void*>(const_cast< MyLCDNumber*>(this));
    return QLCDNumber::qt_metacast(_clname);
}

int MyLCDNumber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLCDNumber::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MyLCDNumber::desactivarValorAbsolut()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MyLCDNumber::valorPerDefecte(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyLCDNumber::enviarAOp1(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyLCDNumber::evniarInfoError(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyLCDNumber::enviarEstilError(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
