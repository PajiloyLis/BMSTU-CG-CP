/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "inc/main_window.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[74];
    char stringdata0[521];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 16), // "ModelPathFetched"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 6), // "string"
QT_MOC_LITERAL(36, 4), // "path"
QT_MOC_LITERAL(41, 19), // "WindSettingsFetched"
QT_MOC_LITERAL(61, 5), // "speed"
QT_MOC_LITERAL(67, 5), // "angle"
QT_MOC_LITERAL(73, 30), // "SimulationSpeedSettingsFetched"
QT_MOC_LITERAL(104, 1), // "x"
QT_MOC_LITERAL(106, 18), // "StartButtonHandler"
QT_MOC_LITERAL(125, 11), // "WindChanged"
QT_MOC_LITERAL(137, 22), // "SimulationSpeedChanged"
QT_MOC_LITERAL(160, 24), // "LoadModelActionTriggered"
QT_MOC_LITERAL(185, 18), // "ClearButtonClicked"
QT_MOC_LITERAL(204, 21), // "AddPointButtonClicked"
QT_MOC_LITERAL(226, 18), // "DrawingModeChanged"
QT_MOC_LITERAL(245, 22), // "LeftMouseButtonClicked"
QT_MOC_LITERAL(268, 1), // "y"
QT_MOC_LITERAL(270, 23), // "RightMouseButtonClicked"
QT_MOC_LITERAL(294, 27), // "ShiftLeftMouseButtonClicked"
QT_MOC_LITERAL(322, 17), // "FillButtonClicked"
QT_MOC_LITERAL(340, 8), // "ShowTime"
QT_MOC_LITERAL(349, 4), // "time"
QT_MOC_LITERAL(354, 15), // "RotateCurCamera"
QT_MOC_LITERAL(370, 2), // "dx"
QT_MOC_LITERAL(373, 2), // "dy"
QT_MOC_LITERAL(376, 13), // "MoveCurCamera"
QT_MOC_LITERAL(390, 15), // "Camera_Movement"
QT_MOC_LITERAL(406, 4), // "move"
QT_MOC_LITERAL(411, 10), // "delta_time"
QT_MOC_LITERAL(422, 14), // "ScaleCurCamera"
QT_MOC_LITERAL(437, 1), // "k"
QT_MOC_LITERAL(439, 15), // "StartSimulation"
QT_MOC_LITERAL(455, 24), // "SmokeTimerElapsedHandler"
QT_MOC_LITERAL(480, 19), // "WindSettingsHandler"
QT_MOC_LITERAL(500, 20) // "SpeedSettingsHandler"

    },
    "MainWindow\0ModelPathFetched\0\0string\0"
    "path\0WindSettingsFetched\0speed\0angle\0"
    "SimulationSpeedSettingsFetched\0x\0"
    "StartButtonHandler\0WindChanged\0"
    "SimulationSpeedChanged\0LoadModelActionTriggered\0"
    "ClearButtonClicked\0AddPointButtonClicked\0"
    "DrawingModeChanged\0LeftMouseButtonClicked\0"
    "y\0RightMouseButtonClicked\0"
    "ShiftLeftMouseButtonClicked\0"
    "FillButtonClicked\0ShowTime\0time\0"
    "RotateCurCamera\0dx\0dy\0MoveCurCamera\0"
    "Camera_Movement\0move\0delta_time\0"
    "ScaleCurCamera\0k\0StartSimulation\0"
    "SmokeTimerElapsedHandler\0WindSettingsHandler\0"
    "SpeedSettingsHandler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  146,    2, 0x06,    1 /* Public */,
       5,    2,  149,    2, 0x06,    3 /* Public */,
       8,    1,  154,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  157,    2, 0x0a,    8 /* Public */,
      11,    0,  158,    2, 0x0a,    9 /* Public */,
      12,    0,  159,    2, 0x0a,   10 /* Public */,
      13,    0,  160,    2, 0x0a,   11 /* Public */,
      14,    0,  161,    2, 0x0a,   12 /* Public */,
      15,    0,  162,    2, 0x0a,   13 /* Public */,
      16,    0,  163,    2, 0x0a,   14 /* Public */,
      17,    2,  164,    2, 0x0a,   15 /* Public */,
      19,    0,  169,    2, 0x0a,   18 /* Public */,
      20,    2,  170,    2, 0x0a,   19 /* Public */,
      21,    2,  175,    2, 0x0a,   22 /* Public */,
      22,    1,  180,    2, 0x0a,   25 /* Public */,
      24,    2,  183,    2, 0x0a,   27 /* Public */,
      27,    2,  188,    2, 0x0a,   30 /* Public */,
      31,    1,  193,    2, 0x0a,   33 /* Public */,
      33,    0,  196,    2, 0x0a,   35 /* Public */,
      34,    0,  197,    2, 0x0a,   36 /* Public */,
      35,    0,  198,    2, 0x0a,   37 /* Public */,
      36,    0,  199,    2, 0x0a,   38 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   18,
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   25,   26,
    QMetaType::Void, 0x80000000 | 28, QMetaType::Float,   29,   30,
    QMetaType::Void, QMetaType::Float,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ModelPathFetched((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 1: _t->WindSettingsFetched((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->SimulationSpeedSettingsFetched((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->StartButtonHandler(); break;
        case 4: _t->WindChanged(); break;
        case 5: _t->SimulationSpeedChanged(); break;
        case 6: _t->LoadModelActionTriggered(); break;
        case 7: _t->ClearButtonClicked(); break;
        case 8: _t->AddPointButtonClicked(); break;
        case 9: _t->DrawingModeChanged(); break;
        case 10: _t->LeftMouseButtonClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 11: _t->RightMouseButtonClicked(); break;
        case 12: _t->ShiftLeftMouseButtonClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 13: _t->FillButtonClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 14: _t->ShowTime((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 15: _t->RotateCurCamera((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2]))); break;
        case 16: _t->MoveCurCamera((*reinterpret_cast< std::add_pointer_t<Camera_Movement>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2]))); break;
        case 17: _t->ScaleCurCamera((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 18: _t->StartSimulation(); break;
        case 19: _t->SmokeTimerElapsedHandler(); break;
        case 20: _t->WindSettingsHandler(); break;
        case 21: _t->SpeedSettingsHandler(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::ModelPathFetched)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::WindSettingsFetched)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SimulationSpeedSettingsFetched)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const string &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const double &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Camera_Movement &, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::ModelPathFetched(const string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::WindSettingsFetched(const int & _t1, const int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::SimulationSpeedSettingsFetched(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
