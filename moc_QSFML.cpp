/****************************************************************************
** Meta object code from reading C++ file 'QSFML.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "inc/QSFML.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSFML.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSFMLCanvas_t {
    const uint offsetsAndSize[42];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_QSFMLCanvas_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_QSFMLCanvas_t qt_meta_stringdata_QSFMLCanvas = {
    {
QT_MOC_LITERAL(0, 11), // "QSFMLCanvas"
QT_MOC_LITERAL(12, 15), // "LeftMouseButton"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 1), // "x"
QT_MOC_LITERAL(31, 1), // "y"
QT_MOC_LITERAL(33, 20), // "ShiftLeftMouseButton"
QT_MOC_LITERAL(54, 16), // "RightMouseButton"
QT_MOC_LITERAL(71, 21), // "LeftMouseButtonDouble"
QT_MOC_LITERAL(93, 14), // "LeftKeyPressed"
QT_MOC_LITERAL(108, 15), // "RightKeyPressed"
QT_MOC_LITERAL(124, 12), // "UpKeyPressed"
QT_MOC_LITERAL(137, 14), // "DownKeyPressed"
QT_MOC_LITERAL(152, 11), // "WKeyPressed"
QT_MOC_LITERAL(164, 15), // "Camera_Movement"
QT_MOC_LITERAL(180, 4), // "move"
QT_MOC_LITERAL(185, 11), // "AKeyPressed"
QT_MOC_LITERAL(197, 11), // "SKeyPressed"
QT_MOC_LITERAL(209, 11), // "DKeyPressed"
QT_MOC_LITERAL(221, 15), // "WheelScrolledUp"
QT_MOC_LITERAL(237, 1), // "k"
QT_MOC_LITERAL(239, 17) // "WheelScrolledDown"

    },
    "QSFMLCanvas\0LeftMouseButton\0\0x\0y\0"
    "ShiftLeftMouseButton\0RightMouseButton\0"
    "LeftMouseButtonDouble\0LeftKeyPressed\0"
    "RightKeyPressed\0UpKeyPressed\0"
    "DownKeyPressed\0WKeyPressed\0Camera_Movement\0"
    "move\0AKeyPressed\0SKeyPressed\0DKeyPressed\0"
    "WheelScrolledUp\0k\0WheelScrolledDown"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSFMLCanvas[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   98,    2, 0x06,    1 /* Public */,
       5,    2,  103,    2, 0x06,    4 /* Public */,
       6,    0,  108,    2, 0x06,    7 /* Public */,
       7,    2,  109,    2, 0x06,    8 /* Public */,
       8,    0,  114,    2, 0x06,   11 /* Public */,
       9,    0,  115,    2, 0x06,   12 /* Public */,
      10,    0,  116,    2, 0x06,   13 /* Public */,
      11,    0,  117,    2, 0x06,   14 /* Public */,
      12,    1,  118,    2, 0x06,   15 /* Public */,
      15,    1,  121,    2, 0x06,   17 /* Public */,
      16,    1,  124,    2, 0x06,   19 /* Public */,
      17,    1,  127,    2, 0x06,   21 /* Public */,
      18,    1,  130,    2, 0x06,   23 /* Public */,
      20,    1,  133,    2, 0x06,   25 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Float,   19,
    QMetaType::Void, QMetaType::Float,   19,

       0        // eod
};

void QSFMLCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSFMLCanvas *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->LeftMouseButton((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->ShiftLeftMouseButton((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->RightMouseButton(); break;
        case 3: _t->LeftMouseButtonDouble((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->LeftKeyPressed(); break;
        case 5: _t->RightKeyPressed(); break;
        case 6: _t->UpKeyPressed(); break;
        case 7: _t->DownKeyPressed(); break;
        case 8: _t->WKeyPressed((*reinterpret_cast< std::add_pointer_t<Camera_Movement>>(_a[1]))); break;
        case 9: _t->AKeyPressed((*reinterpret_cast< std::add_pointer_t<Camera_Movement>>(_a[1]))); break;
        case 10: _t->SKeyPressed((*reinterpret_cast< std::add_pointer_t<Camera_Movement>>(_a[1]))); break;
        case 11: _t->DKeyPressed((*reinterpret_cast< std::add_pointer_t<Camera_Movement>>(_a[1]))); break;
        case 12: _t->WheelScrolledUp((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 13: _t->WheelScrolledDown((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QSFMLCanvas::*)(const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::LeftMouseButton)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QSFMLCanvas::*)(const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::ShiftLeftMouseButton)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QSFMLCanvas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::RightMouseButton)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QSFMLCanvas::*)(const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::LeftMouseButtonDouble)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QSFMLCanvas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::LeftKeyPressed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QSFMLCanvas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::RightKeyPressed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QSFMLCanvas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::UpKeyPressed)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (QSFMLCanvas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::DownKeyPressed)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (QSFMLCanvas::*)(const Camera_Movement & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::WKeyPressed)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (QSFMLCanvas::*)(const Camera_Movement & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::AKeyPressed)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (QSFMLCanvas::*)(const Camera_Movement & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::SKeyPressed)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (QSFMLCanvas::*)(const Camera_Movement & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::DKeyPressed)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (QSFMLCanvas::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::WheelScrolledUp)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (QSFMLCanvas::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSFMLCanvas::WheelScrolledDown)) {
                *result = 13;
                return;
            }
        }
    }
}

const QMetaObject QSFMLCanvas::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QSFMLCanvas.offsetsAndSize,
    qt_meta_data_QSFMLCanvas,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_QSFMLCanvas_t
, QtPrivate::TypeAndForceComplete<QSFMLCanvas, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Camera_Movement &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Camera_Movement &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Camera_Movement &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Camera_Movement &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>



>,
    nullptr
} };


const QMetaObject *QSFMLCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSFMLCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSFMLCanvas.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "sf::RenderWindow"))
        return static_cast< sf::RenderWindow*>(this);
    return QWidget::qt_metacast(_clname);
}

int QSFMLCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void QSFMLCanvas::LeftMouseButton(const int & _t1, const int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSFMLCanvas::ShiftLeftMouseButton(const int & _t1, const int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSFMLCanvas::RightMouseButton()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QSFMLCanvas::LeftMouseButtonDouble(const int & _t1, const int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QSFMLCanvas::LeftKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QSFMLCanvas::RightKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QSFMLCanvas::UpKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QSFMLCanvas::DownKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QSFMLCanvas::WKeyPressed(const Camera_Movement & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QSFMLCanvas::AKeyPressed(const Camera_Movement & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void QSFMLCanvas::SKeyPressed(const Camera_Movement & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void QSFMLCanvas::DKeyPressed(const Camera_Movement & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void QSFMLCanvas::WheelScrolledUp(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void QSFMLCanvas::WheelScrolledDown(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
