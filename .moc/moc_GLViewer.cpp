/****************************************************************************
** Meta object code from reading C++ file 'GLViewer.h'
**
** Created: Tue May 18 16:12:29 2010
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GLViewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLViewer[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      12,   10,    9,    9, 0x0a,
      33,   31,    9,    9, 0x0a,
      57,   55,    9,    9, 0x0a,
      74,   72,    9,    9, 0x0a,
      91,    9,   86,    9, 0x0a,
      99,   72,    9,    9, 0x0a,
     122,    9,   86,    9, 0x0a,
     141,   72,    9,    9, 0x0a,
     155,    9,   86,    9, 0x0a,
     170,    9,  166,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLViewer[] = {
    "GLViewer\0\0b\0setWireframe(bool)\0m\0"
    "setRenderingMode(int)\0n\0setRender(int)\0"
    "c\0setHD(bool)\0bool\0getHD()\0"
    "setUseBackground(bool)\0getUseBackground()\0"
    "setScene(int)\0getScene()\0int\0getRender()\0"
};

const QMetaObject GLViewer::staticMetaObject = {
    { &QGLViewer::staticMetaObject, qt_meta_stringdata_GLViewer,
      qt_meta_data_GLViewer, 0 }
};

const QMetaObject *GLViewer::metaObject() const
{
    return &staticMetaObject;
}

void *GLViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLViewer))
        return static_cast<void*>(const_cast< GLViewer*>(this));
    return QGLViewer::qt_metacast(_clname);
}

int GLViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLViewer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setWireframe((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: setRenderingMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: setRender((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: setHD((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: { bool _r = getHD();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: setUseBackground((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: { bool _r = getUseBackground();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: setScene((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: { bool _r = getScene();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { int _r = getRender();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
