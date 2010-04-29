/****************************************************************************
** Meta object code from reading C++ file 'QTUtils.h'
**
** Created: Thu Apr 22 16:12:09 2010
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QTUtils.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTUtils.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IntegerWidget[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_IntegerWidget[] = {
    "IntegerWidget\0\0valueChanged(int)\0"
};

const QMetaObject IntegerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IntegerWidget,
      qt_meta_data_IntegerWidget, 0 }
};

const QMetaObject *IntegerWidget::metaObject() const
{
    return &staticMetaObject;
}

void *IntegerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IntegerWidget))
        return static_cast<void*>(const_cast< IntegerWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int IntegerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void IntegerWidget::valueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_DoubleWidget[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   35,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DoubleWidget[] = {
    "DoubleWidget\0\0valueChanged(double)\0i\0"
    "changeValue(int)\0"
};

const QMetaObject DoubleWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DoubleWidget,
      qt_meta_data_DoubleWidget, 0 }
};

const QMetaObject *DoubleWidget::metaObject() const
{
    return &staticMetaObject;
}

void *DoubleWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DoubleWidget))
        return static_cast<void*>(const_cast< DoubleWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DoubleWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: changeValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DoubleWidget::valueChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
