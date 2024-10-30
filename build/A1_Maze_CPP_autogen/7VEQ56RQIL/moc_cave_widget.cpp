/****************************************************************************
** Meta object code from reading C++ file 'cave_widget.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/view/includes/cave_widget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cave_widget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__CaveWidget_t {
    const uint offsetsAndSize[38];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_s21__CaveWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_s21__CaveWidget_t qt_meta_stringdata_s21__CaveWidget = {
    {
QT_MOC_LITERAL(0, 15), // "s21::CaveWidget"
QT_MOC_LITERAL(16, 11), // "resizeEvent"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 13), // "QResizeEvent*"
QT_MOC_LITERAL(43, 5), // "event"
QT_MOC_LITERAL(49, 16), // "dragHeightSlider"
QT_MOC_LITERAL(66, 15), // "dragWidthSlider"
QT_MOC_LITERAL(82, 15), // "dragGenerations"
QT_MOC_LITERAL(98, 14), // "dragLiveChance"
QT_MOC_LITERAL(113, 14), // "dragBirthLimit"
QT_MOC_LITERAL(128, 14), // "dragDeathLimit"
QT_MOC_LITERAL(143, 13), // "dragFrequency"
QT_MOC_LITERAL(157, 21), // "clickedSettingsButton"
QT_MOC_LITERAL(179, 17), // "clickedBackButton"
QT_MOC_LITERAL(197, 17), // "clickedSaveButton"
QT_MOC_LITERAL(215, 17), // "clickedLoadButton"
QT_MOC_LITERAL(233, 19), // "clickedCreateButton"
QT_MOC_LITERAL(253, 18), // "clickedClearButton"
QT_MOC_LITERAL(272, 21) // "cellularAutomatonDemo"

    },
    "s21::CaveWidget\0resizeEvent\0\0QResizeEvent*\0"
    "event\0dragHeightSlider\0dragWidthSlider\0"
    "dragGenerations\0dragLiveChance\0"
    "dragBirthLimit\0dragDeathLimit\0"
    "dragFrequency\0clickedSettingsButton\0"
    "clickedBackButton\0clickedSaveButton\0"
    "clickedLoadButton\0clickedCreateButton\0"
    "clickedClearButton\0cellularAutomatonDemo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__CaveWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x08,    1 /* Private */,
       5,    0,  107,    2, 0x08,    3 /* Private */,
       6,    0,  108,    2, 0x08,    4 /* Private */,
       7,    0,  109,    2, 0x08,    5 /* Private */,
       8,    0,  110,    2, 0x08,    6 /* Private */,
       9,    0,  111,    2, 0x08,    7 /* Private */,
      10,    0,  112,    2, 0x08,    8 /* Private */,
      11,    0,  113,    2, 0x08,    9 /* Private */,
      12,    0,  114,    2, 0x08,   10 /* Private */,
      13,    0,  115,    2, 0x08,   11 /* Private */,
      14,    0,  116,    2, 0x08,   12 /* Private */,
      15,    0,  117,    2, 0x08,   13 /* Private */,
      16,    0,  118,    2, 0x08,   14 /* Private */,
      17,    0,  119,    2, 0x08,   15 /* Private */,
      18,    0,  120,    2, 0x08,   16 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void s21::CaveWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CaveWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resizeEvent((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        case 1: _t->dragHeightSlider(); break;
        case 2: _t->dragWidthSlider(); break;
        case 3: _t->dragGenerations(); break;
        case 4: _t->dragLiveChance(); break;
        case 5: _t->dragBirthLimit(); break;
        case 6: _t->dragDeathLimit(); break;
        case 7: _t->dragFrequency(); break;
        case 8: _t->clickedSettingsButton(); break;
        case 9: _t->clickedBackButton(); break;
        case 10: _t->clickedSaveButton(); break;
        case 11: _t->clickedLoadButton(); break;
        case 12: _t->clickedCreateButton(); break;
        case 13: _t->clickedClearButton(); break;
        case 14: _t->cellularAutomatonDemo(); break;
        default: ;
        }
    }
}

const QMetaObject s21::CaveWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseWidget::staticMetaObject>(),
    qt_meta_stringdata_s21__CaveWidget.offsetsAndSize,
    qt_meta_data_s21__CaveWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__CaveWidget_t
, QtPrivate::TypeAndForceComplete<CaveWidget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *s21::CaveWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::CaveWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__CaveWidget.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int s21::CaveWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
