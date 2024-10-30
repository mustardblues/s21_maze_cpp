/****************************************************************************
** Meta object code from reading C++ file 'maze_widget.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/view/includes/maze_widget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maze_widget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__MazeWidget_t {
    const uint offsetsAndSize[26];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_s21__MazeWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_s21__MazeWidget_t qt_meta_stringdata_s21__MazeWidget = {
    {
QT_MOC_LITERAL(0, 15), // "s21::MazeWidget"
QT_MOC_LITERAL(16, 11), // "resizeEvent"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 13), // "QResizeEvent*"
QT_MOC_LITERAL(43, 5), // "event"
QT_MOC_LITERAL(49, 16), // "dragHeightSlider"
QT_MOC_LITERAL(66, 15), // "dragWidthSlider"
QT_MOC_LITERAL(82, 21), // "clickedSettingsButton"
QT_MOC_LITERAL(104, 17), // "clickedBackButton"
QT_MOC_LITERAL(122, 17), // "clickedSaveButton"
QT_MOC_LITERAL(140, 17), // "clickedLoadButton"
QT_MOC_LITERAL(158, 19), // "clickedCreateButton"
QT_MOC_LITERAL(178, 21) // "clickedFindPathButton"

    },
    "s21::MazeWidget\0resizeEvent\0\0QResizeEvent*\0"
    "event\0dragHeightSlider\0dragWidthSlider\0"
    "clickedSettingsButton\0clickedBackButton\0"
    "clickedSaveButton\0clickedLoadButton\0"
    "clickedCreateButton\0clickedFindPathButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__MazeWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x08,    1 /* Private */,
       5,    0,   71,    2, 0x08,    3 /* Private */,
       6,    0,   72,    2, 0x08,    4 /* Private */,
       7,    0,   73,    2, 0x08,    5 /* Private */,
       8,    0,   74,    2, 0x08,    6 /* Private */,
       9,    0,   75,    2, 0x08,    7 /* Private */,
      10,    0,   76,    2, 0x08,    8 /* Private */,
      11,    0,   77,    2, 0x08,    9 /* Private */,
      12,    0,   78,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
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

void s21::MazeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MazeWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resizeEvent((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        case 1: _t->dragHeightSlider(); break;
        case 2: _t->dragWidthSlider(); break;
        case 3: _t->clickedSettingsButton(); break;
        case 4: _t->clickedBackButton(); break;
        case 5: _t->clickedSaveButton(); break;
        case 6: _t->clickedLoadButton(); break;
        case 7: _t->clickedCreateButton(); break;
        case 8: _t->clickedFindPathButton(); break;
        default: ;
        }
    }
}

const QMetaObject s21::MazeWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseWidget::staticMetaObject>(),
    qt_meta_stringdata_s21__MazeWidget.offsetsAndSize,
    qt_meta_data_s21__MazeWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__MazeWidget_t
, QtPrivate::TypeAndForceComplete<MazeWidget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *s21::MazeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::MazeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__MazeWidget.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int s21::MazeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
