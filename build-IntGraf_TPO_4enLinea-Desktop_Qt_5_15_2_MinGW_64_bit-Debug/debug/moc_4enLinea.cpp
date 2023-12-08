/****************************************************************************
** Meta object code from reading C++ file '4enLinea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../IntGraf_TPO_4enLinea/4enLinea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file '4enLinea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 20), // "on_Rein_Cont_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 18), // "on_Mov_Izq_clicked"
QT_MOC_LITERAL(4, 52, 30), // "on_Colores_Jug_1_textActivated"
QT_MOC_LITERAL(5, 83, 4), // "arg1"
QT_MOC_LITERAL(6, 88, 30), // "on_Colores_Jug_2_textActivated"
QT_MOC_LITERAL(7, 119, 18), // "on_Mov_Der_clicked"
QT_MOC_LITERAL(8, 138, 19), // "on_Conf_Pos_clicked"
QT_MOC_LITERAL(9, 158, 11), // "serial_read"
QT_MOC_LITERAL(10, 170, 27), // "on_Conf_Color_Jug_1_clicked"
QT_MOC_LITERAL(11, 198, 27), // "on_Conf_Color_Jug_2_clicked"
QT_MOC_LITERAL(12, 226, 24), // "on_ConectarBoton_clicked"
QT_MOC_LITERAL(13, 251, 25), // "on_Comienzo_Juego_clicked"
QT_MOC_LITERAL(14, 277, 26) // "on_Reiniciar_Juego_clicked"

    },
    "MainWindow\0on_Rein_Cont_clicked\0\0"
    "on_Mov_Izq_clicked\0on_Colores_Jug_1_textActivated\0"
    "arg1\0on_Colores_Jug_2_textActivated\0"
    "on_Mov_Der_clicked\0on_Conf_Pos_clicked\0"
    "serial_read\0on_Conf_Color_Jug_1_clicked\0"
    "on_Conf_Color_Jug_2_clicked\0"
    "on_ConectarBoton_clicked\0"
    "on_Comienzo_Juego_clicked\0"
    "on_Reiniciar_Juego_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    1,   76,    2, 0x08 /* Private */,
       6,    1,   79,    2, 0x08 /* Private */,
       7,    0,   82,    2, 0x08 /* Private */,
       8,    0,   83,    2, 0x08 /* Private */,
       9,    0,   84,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Rein_Cont_clicked(); break;
        case 1: _t->on_Mov_Izq_clicked(); break;
        case 2: _t->on_Colores_Jug_1_textActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_Colores_Jug_2_textActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_Mov_Der_clicked(); break;
        case 5: _t->on_Conf_Pos_clicked(); break;
        case 6: _t->serial_read(); break;
        case 7: _t->on_Conf_Color_Jug_1_clicked(); break;
        case 8: _t->on_Conf_Color_Jug_2_clicked(); break;
        case 9: _t->on_ConectarBoton_clicked(); break;
        case 10: _t->on_Comienzo_Juego_clicked(); break;
        case 11: _t->on_Reiniciar_Juego_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
