/****************************************************************************
** Meta object code from reading C++ file 'base_widget.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/view/includes/base_widget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'base_widget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__BaseWidget_t {
    const uint offsetsAndSize[22];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_s21__BaseWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_s21__BaseWidget_t qt_meta_stringdata_s21__BaseWidget = {
    {
QT_MOC_LITERAL(0, 15), // "s21::BaseWidget"
QT_MOC_LITERAL(16, 10), // "backToMenu"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 16), // "dragHeightSlider"
QT_MOC_LITERAL(45, 15), // "dragWidthSlider"
QT_MOC_LITERAL(61, 21), // "clickedSettingsButton"
QT_MOC_LITERAL(83, 17), // "clickedBackButton"
QT_MOC_LITERAL(101, 17), // "clickedSaveButton"
QT_MOC_LITERAL(119, 17), // "clickedLoadButton"
QT_MOC_LITERAL(137, 19), // "clickedCreateButton"
QT_MOC_LITERAL(157, 17) // "clickedMenuButton"

    },
    "s21::BaseWidget\0backToMenu\0\0"
    "dragHeightSlider\0dragWidthSlider\0"
    "clickedSettingsButton\0clickedBackButton\0"
    "clickedSaveButton\0clickedLoadButton\0"
    "clickedCreateButton\0clickedMenuButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__BaseWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   69,    2, 0x09,    2 /* Protected */,
       4,    0,   70,    2, 0x09,    3 /* Protected */,
       5,    0,   71,    2, 0x09,    4 /* Protected */,
       6,    0,   72,    2, 0x09,    5 /* Protected */,
       7,    0,   73,    2, 0x09,    6 /* Protected */,
       8,    0,   74,    2, 0x09,    7 /* Protected */,
       9,    0,   75,    2, 0x09,    8 /* Protected */,
      10,    0,   76,    2, 0x09,    9 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
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

void s21::BaseWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BaseWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->backToMenu(); break;
        case 1: _t->dragHeightSlider(); break;
        case 2: _t->dragWidthSlider(); break;
        case 3: _t->clickedSettingsButton(); break;
        case 4: _t->clickedBackButton(); break;
        case 5: _t->clickedSaveButton(); break;
        case 6: _t->clickedLoadButton(); break;
        case 7: _t->clickedCreateButton(); break;
        case 8: _t->clickedMenuButton(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BaseWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseWidget::backToMenu)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject s21::BaseWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_s21__BaseWidget.offsetsAndSize,
    qt_meta_data_s21__BaseWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__BaseWidget_t
, QtPrivate::TypeAndForceComplete<BaseWidget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *s21::BaseWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::BaseWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__BaseWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int s21::BaseWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void s21::BaseWidget::backToMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
