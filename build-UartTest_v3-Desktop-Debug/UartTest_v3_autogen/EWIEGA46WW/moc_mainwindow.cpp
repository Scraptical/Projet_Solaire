/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UartTest_v3/mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[26];
    char stringdata0[11];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[15];
    char stringdata5[12];
    char stringdata6[5];
    char stringdata7[12];
    char stringdata8[22];
    char stringdata9[4];
    char stringdata10[14];
    char stringdata11[7];
    char stringdata12[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 11),  // "setupSerial"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 11),  // "verifSerial"
        QT_MOC_LITERAL(36, 14),  // "readSerialData"
        QT_MOC_LITERAL(51, 11),  // "trameISjson"
        QT_MOC_LITERAL(63, 4),  // "data"
        QT_MOC_LITERAL(68, 11),  // "convertData"
        QT_MOC_LITERAL(80, 21),  // "std::pair<double,int>"
        QT_MOC_LITERAL(102, 3),  // "doc"
        QT_MOC_LITERAL(106, 13),  // "updateUIvalue"
        QT_MOC_LITERAL(120, 6),  // "valeur"
        QT_MOC_LITERAL(127, 8)   // "makeFile"
    },
    "MainWindow",
    "setupSerial",
    "",
    "verifSerial",
    "readSerialData",
    "trameISjson",
    "data",
    "convertData",
    "std::pair<double,int>",
    "doc",
    "updateUIvalue",
    "valeur",
    "makeFile"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    1,   59,    2, 0x08,    4 /* Private */,
       7,    1,   62,    2, 0x08,    6 /* Private */,
      10,    1,   65,    2, 0x08,    8 /* Private */,
      12,    0,   68,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QJsonDocument, QMetaType::QByteArray,    6,
    0x80000000 | 8, QMetaType::QJsonDocument,    9,
    QMetaType::Void, 0x80000000 | 8,   11,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'setupSerial'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'verifSerial'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readSerialData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'trameISjson'
        QtPrivate::TypeAndForceComplete<QJsonDocument, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'convertData'
        QtPrivate::TypeAndForceComplete<QPair<double,int>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonDocument, std::false_type>,
        // method 'updateUIvalue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPair<double,int>, std::false_type>,
        // method 'makeFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setupSerial(); break;
        case 1: _t->verifSerial(); break;
        case 2: _t->readSerialData(); break;
        case 3: { QJsonDocument _r = _t->trameISjson((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonDocument*>(_a[0]) = std::move(_r); }  break;
        case 4: { std::pair<double,int> _r = _t->convertData((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::pair<double,int>*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->updateUIvalue((*reinterpret_cast< std::add_pointer_t<std::pair<double,int>>>(_a[1]))); break;
        case 6: _t->makeFile(); break;
        default: ;
        }
    }
}

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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
