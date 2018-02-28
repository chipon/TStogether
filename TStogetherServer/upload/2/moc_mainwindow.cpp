/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TStogether/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[63];
    char stringdata0[1233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "sendStudentInfo"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "Student*"
QT_MOC_LITERAL(4, 37, 3), // "stu"
QT_MOC_LITERAL(5, 41, 25), // "send_student_info_request"
QT_MOC_LITERAL(6, 67, 17), // "UpdateStudentInfo"
QT_MOC_LITERAL(7, 85, 15), // "QList<QString>*"
QT_MOC_LITERAL(8, 101, 21), // "UpdateStudentInfoOKMW"
QT_MOC_LITERAL(9, 123, 25), // "UpdateStudentInfoFailedMW"
QT_MOC_LITERAL(10, 149, 19), // "SearchCourseRequest"
QT_MOC_LITERAL(11, 169, 25), // "SearchCourseResponseOKMid"
QT_MOC_LITERAL(12, 195, 14), // "QList<Course>*"
QT_MOC_LITERAL(13, 210, 4), // "list"
QT_MOC_LITERAL(14, 215, 25), // "SearchCourseResponseFDMid"
QT_MOC_LITERAL(15, 241, 16), // "AddCourseRequest"
QT_MOC_LITERAL(16, 258, 22), // "AddCourseResponseOKMid"
QT_MOC_LITERAL(17, 281, 22), // "AddCourseResponseFDMid"
QT_MOC_LITERAL(18, 304, 23), // "GetStudentCourseRequest"
QT_MOC_LITERAL(19, 328, 21), // "SendStudentCourseInfo"
QT_MOC_LITERAL(20, 350, 20), // "GetCourseInfoRequest"
QT_MOC_LITERAL(21, 371, 26), // "GetCourseInfoResponseOKMid"
QT_MOC_LITERAL(22, 398, 7), // "Course*"
QT_MOC_LITERAL(23, 406, 26), // "GetCourseInfoResponseFDMid"
QT_MOC_LITERAL(24, 433, 18), // "SendMessageRequest"
QT_MOC_LITERAL(25, 452, 24), // "SendMessageResponseOKMid"
QT_MOC_LITERAL(26, 477, 24), // "SendMessageResponseFDMid"
QT_MOC_LITERAL(27, 502, 23), // "GetRecentMessageRequest"
QT_MOC_LITERAL(28, 526, 29), // "GetRecentMessageResponseOKMid"
QT_MOC_LITERAL(29, 556, 15), // "QList<Message>*"
QT_MOC_LITERAL(30, 572, 29), // "GetRecentMessageResponseFDMid"
QT_MOC_LITERAL(31, 602, 28), // "on_student_info_tbtn_clicked"
QT_MOC_LITERAL(32, 631, 16), // "GetStudentInfoOK"
QT_MOC_LITERAL(33, 648, 20), // "GetStudentInfoFailed"
QT_MOC_LITERAL(34, 669, 19), // "UpdateStudentInfoOK"
QT_MOC_LITERAL(35, 689, 23), // "UpdateStudentInfoFailed"
QT_MOC_LITERAL(36, 713, 19), // "UpdateStudentInfoMW"
QT_MOC_LITERAL(37, 733, 4), // "type"
QT_MOC_LITERAL(38, 738, 28), // "on_course_search_btn_clicked"
QT_MOC_LITERAL(39, 767, 22), // "SearchCourseRequestMid"
QT_MOC_LITERAL(40, 790, 22), // "SearchCourseResponseOK"
QT_MOC_LITERAL(41, 813, 22), // "SearchCourseResponseFD"
QT_MOC_LITERAL(42, 836, 19), // "AddCourseRequestMid"
QT_MOC_LITERAL(43, 856, 19), // "AddCourseResponseOK"
QT_MOC_LITERAL(44, 876, 19), // "AddCourseResponseFD"
QT_MOC_LITERAL(45, 896, 26), // "GetStudentCourseResponseOK"
QT_MOC_LITERAL(46, 923, 26), // "GetStudentCourseResponseFD"
QT_MOC_LITERAL(47, 950, 17), // "ReadNewCourseInfo"
QT_MOC_LITERAL(48, 968, 32), // "on_course_list_itemDoubleClicked"
QT_MOC_LITERAL(49, 1001, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(50, 1018, 4), // "item"
QT_MOC_LITERAL(51, 1023, 23), // "GetCourseInfoResponseOK"
QT_MOC_LITERAL(52, 1047, 1), // "c"
QT_MOC_LITERAL(53, 1049, 23), // "GetCourseInfoResponseFD"
QT_MOC_LITERAL(54, 1073, 21), // "SendMessageRequestMid"
QT_MOC_LITERAL(55, 1095, 21), // "SendMessageResponseOK"
QT_MOC_LITERAL(56, 1117, 4), // "name"
QT_MOC_LITERAL(57, 1122, 3), // "cno"
QT_MOC_LITERAL(58, 1126, 3), // "msg"
QT_MOC_LITERAL(59, 1130, 21), // "SendMessageResponseFD"
QT_MOC_LITERAL(60, 1152, 26), // "GetRecentMessageRequestMid"
QT_MOC_LITERAL(61, 1179, 26), // "GetRecentMessageResponseOK"
QT_MOC_LITERAL(62, 1206, 26) // "GetRecentMessageResponseFD"

    },
    "MainWindow\0sendStudentInfo\0\0Student*\0"
    "stu\0send_student_info_request\0"
    "UpdateStudentInfo\0QList<QString>*\0"
    "UpdateStudentInfoOKMW\0UpdateStudentInfoFailedMW\0"
    "SearchCourseRequest\0SearchCourseResponseOKMid\0"
    "QList<Course>*\0list\0SearchCourseResponseFDMid\0"
    "AddCourseRequest\0AddCourseResponseOKMid\0"
    "AddCourseResponseFDMid\0GetStudentCourseRequest\0"
    "SendStudentCourseInfo\0GetCourseInfoRequest\0"
    "GetCourseInfoResponseOKMid\0Course*\0"
    "GetCourseInfoResponseFDMid\0"
    "SendMessageRequest\0SendMessageResponseOKMid\0"
    "SendMessageResponseFDMid\0"
    "GetRecentMessageRequest\0"
    "GetRecentMessageResponseOKMid\0"
    "QList<Message>*\0GetRecentMessageResponseFDMid\0"
    "on_student_info_tbtn_clicked\0"
    "GetStudentInfoOK\0GetStudentInfoFailed\0"
    "UpdateStudentInfoOK\0UpdateStudentInfoFailed\0"
    "UpdateStudentInfoMW\0type\0"
    "on_course_search_btn_clicked\0"
    "SearchCourseRequestMid\0SearchCourseResponseOK\0"
    "SearchCourseResponseFD\0AddCourseRequestMid\0"
    "AddCourseResponseOK\0AddCourseResponseFD\0"
    "GetStudentCourseResponseOK\0"
    "GetStudentCourseResponseFD\0ReadNewCourseInfo\0"
    "on_course_list_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0GetCourseInfoResponseOK\0"
    "c\0GetCourseInfoResponseFD\0"
    "SendMessageRequestMid\0SendMessageResponseOK\0"
    "name\0cno\0msg\0SendMessageResponseFD\0"
    "GetRecentMessageRequestMid\0"
    "GetRecentMessageResponseOK\0"
    "GetRecentMessageResponseFD"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      22,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  254,    2, 0x06 /* Public */,
       5,    1,  257,    2, 0x06 /* Public */,
       6,    2,  260,    2, 0x06 /* Public */,
       8,    0,  265,    2, 0x06 /* Public */,
       9,    0,  266,    2, 0x06 /* Public */,
      10,    2,  267,    2, 0x06 /* Public */,
      11,    1,  272,    2, 0x06 /* Public */,
      14,    0,  275,    2, 0x06 /* Public */,
      15,    2,  276,    2, 0x06 /* Public */,
      16,    0,  281,    2, 0x06 /* Public */,
      17,    0,  282,    2, 0x06 /* Public */,
      18,    1,  283,    2, 0x06 /* Public */,
      19,    1,  286,    2, 0x06 /* Public */,
      20,    2,  289,    2, 0x06 /* Public */,
      21,    1,  294,    2, 0x06 /* Public */,
      23,    0,  297,    2, 0x06 /* Public */,
      24,    2,  298,    2, 0x06 /* Public */,
      25,    3,  303,    2, 0x06 /* Public */,
      26,    0,  310,    2, 0x06 /* Public */,
      27,    2,  311,    2, 0x06 /* Public */,
      28,    2,  316,    2, 0x06 /* Public */,
      30,    0,  321,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      31,    0,  322,    2, 0x08 /* Private */,
      32,    1,  323,    2, 0x08 /* Private */,
      33,    0,  326,    2, 0x08 /* Private */,
      34,    0,  327,    2, 0x08 /* Private */,
      35,    0,  328,    2, 0x08 /* Private */,
       6,    1,  329,    2, 0x08 /* Private */,
      36,    2,  332,    2, 0x08 /* Private */,
      38,    0,  337,    2, 0x08 /* Private */,
      39,    2,  338,    2, 0x08 /* Private */,
      40,    1,  343,    2, 0x08 /* Private */,
      41,    0,  346,    2, 0x08 /* Private */,
      42,    2,  347,    2, 0x08 /* Private */,
      43,    0,  352,    2, 0x08 /* Private */,
      44,    0,  353,    2, 0x08 /* Private */,
      45,    1,  354,    2, 0x08 /* Private */,
      46,    0,  357,    2, 0x08 /* Private */,
      47,    1,  358,    2, 0x08 /* Private */,
      48,    1,  361,    2, 0x08 /* Private */,
      51,    1,  364,    2, 0x08 /* Private */,
      53,    0,  367,    2, 0x08 /* Private */,
      54,    2,  368,    2, 0x08 /* Private */,
      55,    3,  373,    2, 0x08 /* Private */,
      59,    0,  380,    2, 0x08 /* Private */,
      60,    2,  381,    2, 0x08 /* Private */,
      61,    2,  386,    2, 0x08 /* Private */,
      62,    0,  391,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 29,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,   13,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,   37,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,   37,   13,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,   37,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,   13,
    QMetaType::Void, 0x80000000 | 49,   50,
    QMetaType::Void, 0x80000000 | 22,   52,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,   37,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,   56,   57,   58,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,   37,   13,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 29,   57,   13,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendStudentInfo((*reinterpret_cast< Student*(*)>(_a[1]))); break;
        case 1: _t->send_student_info_request((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->UpdateStudentInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>*(*)>(_a[2]))); break;
        case 3: _t->UpdateStudentInfoOKMW(); break;
        case 4: _t->UpdateStudentInfoFailedMW(); break;
        case 5: _t->SearchCourseRequest((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>*(*)>(_a[2]))); break;
        case 6: _t->SearchCourseResponseOKMid((*reinterpret_cast< QList<Course>*(*)>(_a[1]))); break;
        case 7: _t->SearchCourseResponseFDMid(); break;
        case 8: _t->AddCourseRequest((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>*(*)>(_a[2]))); break;
        case 9: _t->AddCourseResponseOKMid(); break;
        case 10: _t->AddCourseResponseFDMid(); break;
        case 11: _t->GetStudentCourseRequest((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->SendStudentCourseInfo((*reinterpret_cast< QList<QString>*(*)>(_a[1]))); break;
        case 13: _t->GetCourseInfoRequest((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>*(*)>(_a[2]))); break;
        case 14: _t->GetCourseInfoResponseOKMid((*reinterpret_cast< Course*(*)>(_a[1]))); break;
        case 15: _t->GetCourseInfoResponseFDMid(); break;
        case 16: _t->SendMessageRequest((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>*(*)>(_a[2]))); break;
        case 17: _t->SendMessageResponseOKMid((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 18: _t->SendMessageResponseFDMid(); break;
        case 19: _t->GetRecentMessageRequest((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>*(*)>(_a[2]))); break;
        case 20: _t->GetRecentMessageResponseOKMid((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<Message>*(*)>(_a[2]))); break;
        case 21: _t->GetRecentMessageResponseFDMid(); break;
        case 22: _t->on_student_info_tbtn_clicked(); break;
        case 23: _t->GetStudentInfoOK((*reinterpret_cast< Student*(*)>(_a[1]))); break;
        case 24: _t->GetStudentInfoFailed(); break;
        case 25: _t->UpdateStudentInfoOK(); break;
        case 26: _t->UpdateStudentInfoFailed(); break;
        case 27: _t->UpdateStudentInfo((*reinterpret_cast< QList<QString>*(*)>(_a[1]))); break;
        case 28: _t->UpdateStudentInfoMW((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>*(*)>(_a[2]))); break;
        case 29: _t->on_course_search_btn_clicked(); break;
        case 30: _t->SearchCourseRequestMid((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>*(*)>(_a[2]))); break;
        case 31: _t->SearchCourseResponseOK((*reinterpret_cast< QList<Course>*(*)>(_a[1]))); break;
        case 32: _t->SearchCourseResponseFD(); break;
        case 33: _t->AddCourseRequestMid((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>*(*)>(_a[2]))); break;
        case 34: _t->AddCourseResponseOK(); break;
        case 35: _t->AddCourseResponseFD(); break;
        case 36: _t->GetStudentCourseResponseOK((*reinterpret_cast< QList<QString>*(*)>(_a[1]))); break;
        case 37: _t->GetStudentCourseResponseFD(); break;
        case 38: _t->ReadNewCourseInfo((*reinterpret_cast< QList<QString>*(*)>(_a[1]))); break;
        case 39: _t->on_course_list_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 40: _t->GetCourseInfoResponseOK((*reinterpret_cast< Course*(*)>(_a[1]))); break;
        case 41: _t->GetCourseInfoResponseFD(); break;
        case 42: _t->SendMessageRequestMid((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>*(*)>(_a[2]))); break;
        case 43: _t->SendMessageResponseOK((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 44: _t->SendMessageResponseFD(); break;
        case 45: _t->GetRecentMessageRequestMid((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>*(*)>(_a[2]))); break;
        case 46: _t->GetRecentMessageResponseOK((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<Message>*(*)>(_a[2]))); break;
        case 47: _t->GetRecentMessageResponseFD(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(Student * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendStudentInfo)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::send_student_info_request)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , QList<QString> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::UpdateStudentInfo)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::UpdateStudentInfoOKMW)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::UpdateStudentInfoFailedMW)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , QList<QString> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::SearchCourseRequest)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QList<Course> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::SearchCourseResponseOKMid)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::SearchCourseResponseFDMid)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , QList<QString> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::AddCourseRequest)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::AddCourseResponseOKMid)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::AddCourseResponseFDMid)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::GetStudentCourseRequest)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QList<QString> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::SendStudentCourseInfo)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , QList<QString> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::GetCourseInfoRequest)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(Course * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::GetCourseInfoResponseOKMid)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::GetCourseInfoResponseFDMid)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , QList<QString> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::SendMessageRequest)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::SendMessageResponseOKMid)) {
                *result = 17;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::SendMessageResponseFDMid)) {
                *result = 18;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , QList<QString> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::GetRecentMessageRequest)) {
                *result = 19;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int , QList<Message> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::GetRecentMessageResponseOKMid)) {
                *result = 20;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::GetRecentMessageResponseFDMid)) {
                *result = 21;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 48)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 48;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendStudentInfo(Student * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::send_student_info_request(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::UpdateStudentInfo(QString _t1, QList<QString> * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::UpdateStudentInfoOKMW()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::UpdateStudentInfoFailedMW()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MainWindow::SearchCourseRequest(QString _t1, QList<QString> * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::SearchCourseResponseOKMid(QList<Course> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::SearchCourseResponseFDMid()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void MainWindow::AddCourseRequest(QString _t1, QList<QString> * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::AddCourseResponseOKMid()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void MainWindow::AddCourseResponseFDMid()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void MainWindow::GetStudentCourseRequest(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MainWindow::SendStudentCourseInfo(QList<QString> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void MainWindow::GetCourseInfoRequest(QString _t1, QList<QString> * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MainWindow::GetCourseInfoResponseOKMid(Course * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void MainWindow::GetCourseInfoResponseFDMid()
{
    QMetaObject::activate(this, &staticMetaObject, 15, Q_NULLPTR);
}

// SIGNAL 16
void MainWindow::SendMessageRequest(QString _t1, QList<QString> * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void MainWindow::SendMessageResponseOKMid(QString _t1, int _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void MainWindow::SendMessageResponseFDMid()
{
    QMetaObject::activate(this, &staticMetaObject, 18, Q_NULLPTR);
}

// SIGNAL 19
void MainWindow::GetRecentMessageRequest(QString _t1, QList<QString> * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void MainWindow::GetRecentMessageResponseOKMid(int _t1, QList<Message> * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void MainWindow::GetRecentMessageResponseFDMid()
{
    QMetaObject::activate(this, &staticMetaObject, 21, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
