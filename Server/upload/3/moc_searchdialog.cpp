/****************************************************************************
** Meta object code from reading C++ file 'searchdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TStogether/searchdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SearchDialog_t {
    QByteArrayData data[17];
    char stringdata0[309];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SearchDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SearchDialog_t qt_meta_stringdata_SearchDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SearchDialog"
QT_MOC_LITERAL(1, 13, 19), // "SearchCourseRequest"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 15), // "QList<QString>*"
QT_MOC_LITERAL(4, 50, 16), // "AddCourseRequest"
QT_MOC_LITERAL(5, 67, 17), // "SendNewCourseInfo"
QT_MOC_LITERAL(6, 85, 22), // "SearchCourseResponseOK"
QT_MOC_LITERAL(7, 108, 14), // "QList<Course>*"
QT_MOC_LITERAL(8, 123, 4), // "list"
QT_MOC_LITERAL(9, 128, 22), // "SearchCourseResponseFD"
QT_MOC_LITERAL(10, 151, 28), // "on_course_search_btn_clicked"
QT_MOC_LITERAL(11, 180, 29), // "on_course_confirm_btn_clicked"
QT_MOC_LITERAL(12, 210, 25), // "on_course_add_btn_clicked"
QT_MOC_LITERAL(13, 236, 19), // "AddCourseResponseOK"
QT_MOC_LITERAL(14, 256, 19), // "AddCourseResponseFD"
QT_MOC_LITERAL(15, 276, 21), // "ReadStudentCourseInfo"
QT_MOC_LITERAL(16, 298, 10) // "courselist"

    },
    "SearchDialog\0SearchCourseRequest\0\0"
    "QList<QString>*\0AddCourseRequest\0"
    "SendNewCourseInfo\0SearchCourseResponseOK\0"
    "QList<Course>*\0list\0SearchCourseResponseFD\0"
    "on_course_search_btn_clicked\0"
    "on_course_confirm_btn_clicked\0"
    "on_course_add_btn_clicked\0AddCourseResponseOK\0"
    "AddCourseResponseFD\0ReadStudentCourseInfo\0"
    "courselist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       4,    2,   74,    2, 0x06 /* Public */,
       5,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   82,    2, 0x08 /* Private */,
       9,    0,   85,    2, 0x08 /* Private */,
      10,    0,   86,    2, 0x08 /* Private */,
      11,    0,   87,    2, 0x08 /* Private */,
      12,    0,   88,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    1,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   16,

       0        // eod
};

void SearchDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearchDialog *_t = static_cast<SearchDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SearchCourseRequest((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>*(*)>(_a[2]))); break;
        case 1: _t->AddCourseRequest((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>*(*)>(_a[2]))); break;
        case 2: _t->SendNewCourseInfo((*reinterpret_cast< QList<QString>*(*)>(_a[1]))); break;
        case 3: _t->SearchCourseResponseOK((*reinterpret_cast< QList<Course>*(*)>(_a[1]))); break;
        case 4: _t->SearchCourseResponseFD(); break;
        case 5: _t->on_course_search_btn_clicked(); break;
        case 6: _t->on_course_confirm_btn_clicked(); break;
        case 7: _t->on_course_add_btn_clicked(); break;
        case 8: _t->AddCourseResponseOK(); break;
        case 9: _t->AddCourseResponseFD(); break;
        case 10: _t->ReadStudentCourseInfo((*reinterpret_cast< QList<QString>*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SearchDialog::*_t)(QString , QList<QString> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchDialog::SearchCourseRequest)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SearchDialog::*_t)(QString , QList<QString> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchDialog::AddCourseRequest)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SearchDialog::*_t)(QList<QString> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchDialog::SendNewCourseInfo)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject SearchDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SearchDialog.data,
      qt_meta_data_SearchDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SearchDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SearchDialog.stringdata0))
        return static_cast<void*>(const_cast< SearchDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SearchDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void SearchDialog::SearchCourseRequest(QString _t1, QList<QString> * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SearchDialog::AddCourseRequest(QString _t1, QList<QString> * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SearchDialog::SendNewCourseInfo(QList<QString> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
