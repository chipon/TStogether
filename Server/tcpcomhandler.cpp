#include "tcpcomhandler.h"
#include <QDebug>
#include <utils.h>
#include <database.h>
#include <QDataStream>

void TCPComHandler::handleData()
{
    if(readFile || sendFile) return;
    QString type;
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_7);
    in>>type;

    qDebug()<<type;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_7);
    if(type=="Login"){
        QString pwd;
        QString userstr,numberstr;
        in>>userstr>>numberstr>>pwd;
        user=userstr.toInt();
        number=numberstr.toInt();
        if(number==0 || pwd==0){
            out<<tr("LoginFailed");
        }else if(Database::login(user,number,pwd)){
            out<<tr("LoginOK");
        }else{
            out<<tr("LoginFailed");
        }
    }else if(type=="GetStudentInfo"){
        Student stu=Database::get_student_by_sno(number);
        if(stu.sno){
            out<<tr("GetStudentInfoOK");
            out<<stu.sno<<stu.snickname<<stu.spwd<<stu.sname<<stu.sgrade<<stu.sdept<<stu.smajor<<stu.ssignature;
            //qDebug()<<stu.sno<<stu.snickname<<stu.spwd<<stu.sname<<stu.sgrade<<stu.sdept<<stu.smajor<<stu.ssignature;
        }else{
            out<<tr("GetStudentInfoFailed");
        }
    }else if(type=="GetTeacherInfo"){
        Teacher t=Database::get_teacher_by_tno(number);
        if(t.tno){
            out<<tr("GetTeacherInfoOK");
            out<<t.tdept<<t.temail<<t.tname<<t.tno<<t.tpwd;
            //qDebug()<<t.tdept<<t.temail<<t.tname<<t.tno<<t.tpwd;
        }else{
            out<<tr("GetTeacherInfoFailed");
        }
    }else if(type=="UpdateStudentInfo"){
        QString nickname,pwd,signature;
        in>>nickname>>pwd>>signature;
        int flag=Database::update_student_info(nickname,pwd,signature,number);
        if(flag) out<<tr("UpdateStudentInfoOK");
        else out<<tr("UpdateStudentInfoFailed");
    }else if(type=="UpdateTeacherInfo"){
        QString pwd,email;
        in>>pwd>>email;
        int flag=Database::update_teacher_info(pwd,email,number);
        if(flag) out<<tr("UpdateTeacherInfoOK");
        else out<<tr("UpdateTeacherInfoFailed");
    }else if(type=="GetDeptInfo"){
        QList<Dept> list=Database::get_dept_info();
        if(list.size()){
            out<<tr("GetDeptInfoOK");
            out<<list.size();
            foreach (Dept dept, list) {
                out<<dept.dname;
                //qDebug()<<dept.dname;
                out<<dept.majors.size();
                foreach (QString s, dept.majors) {
                    out<<s;
                    //qDebug()<<s;
                }
            }
        }else{
            out<<tr("GetDeptInfoFailed");
        }
    }else if(type=="FindTeacherByTno"){
        QString tnostr;
        in>>tnostr;
        //qDebug()<<tnostr;
        QString tname=Database::find_teacher_by_tno(tnostr.toInt());
        if(tname.length()){
            out<<tr("FindTeacherByTnoOK");
            out<<tname;
        }
        else out<<tr("FindTeacherByTnoFailed");
    }else if(type=="CreateCourseRequest"){
        Course c;
        int size;
        QString sizestr,tmptno;
        in>>c.cdept>>c.cintro>>c.cmajor>>c.cname;
        //qDebug()<<c.cdept<<c.cintro<<c.cmajor<<c.cname;

        in>>sizestr;
        size=sizestr.toInt();
        for(int i=0;i<size;++i){
            in>>tmptno;
            c.tnolist.append(tmptno.toInt());
        }
        int cno=Database::create_course(c);
        if(cno==0) out<<tr("CreateCourseResponseFD");
        else{
            out<<tr("CreateCourseResponseOK");
            out<<cno;
        }
    }else if(type=="GetTeacherCourseRequest"){
        QList<QString> list=Database::get_teacher_course(number);
        //qDebug()<<"size"<<list.size();
        if(!list.size()) out<<tr("GetTeacherCourseResponseFD");
        else{
            out<<tr("GetTeacherCourseResponseOK");
            out<<list.size();
            foreach (QString s, list) {
                out<<s;
                qDebug()<<s;
            }
        }
    }else if(type=="GetCourseInfoRequest"){
        QString cnostr;
        in>>cnostr;
        Course c=Database::get_course_info_by_cno(cnostr.toInt());
        if(c.cno==0){
            out<<tr("GetCourseInfoResponseFD");
        }else{
            out<<tr("GetCourseInfoResponseOK");
            out<<c.cdept<<c.cintro<<c.cmajor<<c.cname<<c.cno<<c.cnotice;
            //qDebug()<<c.cdept<<c.cintro<<c.cmajor<<c.cname<<c.cno<<c.cnotice;
            out<<c.tnamelist.size();
            foreach (QString s, c.tnamelist) {
                out<<s;
            }
            out<<c.tnolist.size();
            foreach (int i, c.tnolist) {
                out<<i;
            }
        }
    }else if(type=="SearchCourseRequest"){
        QString search;
        in>>search;
        QList<Course> list=Database::search_course(search,number);
        if(!list.size()){
            out<<tr("SearchCourseResponseFD");
        }else{
            out<<tr("SearchCourseResponseOK");
            out<<list.size();
            foreach (Course c, list) {
                out<<c.cname<<c.cno<<c.ctime;
                qDebug()<<c.cname<<c.cno<<c.ctime;
                out<<c.tnamelist.size();
                foreach (QString s, c.tnamelist) {
                    out<<s;
                }
            }
        }
    }else if(type=="AddCourseRequest"){
        QString cnostr;
        in>>cnostr;
        bool flag=Database::add_course_by_cno(number,cnostr.toInt());
        if(flag){
            out<<tr("AddCourseResponseOK");
        }else{
            out<<tr("AddCourseResponseFD");
        }
    }else if(type=="GetStudentCourseRequest"){
        QList<QString> list=Database::get_student_course(number);
//        if(!list.size()){
//            //out<<tr("GetStudentCourseResponseFD");
//        }else{
            out<<tr("GetStudentCourseResponseOK");
            out<<list.size();
            foreach (QString s, list) {
                out<<s;
            }
//        }
    }else if(type=="SendMessageRequest"){
        QString msg,cnostr;
        in>>msg>>cnostr;
        QString name=Database::add_message(user==1,number,cnostr.toInt(),msg);
        if(!name.length()){
            out<<tr("SendMessageResponseFD");
        }else{
            if(user) name+="老师";
            qDebug()<<"name"<<name;
            emit SendMessageRequest(user==1,number,cnostr.toInt(),name,msg);
        }
    }else if(type=="GetRecentMessageRequest"){
        QString cnostr;
        in>>cnostr;
        QList<Message> list=Database::get_recent_message(cnostr.toInt());
        out<<tr("GetRecentMessageResponseOK");
        out<<cnostr.toInt();
        out<<list.size();
        foreach (Message m, list) {
            if(user) m.name+="老师";
            out<<m.msg<<m.name<<m.time;
            //qDebug()<<m.time;
        }
    }else if(type=="UploadFileRequest"){
        in>>cnostr;
        //in.commitTransaction();
        qDebug()<<"cno"<<cnostr;
        totalBytes=0;
        bytesReceived=0;
        fileNameSize=0;
        Utils::sleep(0.1);
        readFile=true;
        return;
    }else if(type=="DownloadFileRequest"){
        QString fnostr;
        in>>fnostr;
        QString path=Database::get_courseware_path(fnostr.toInt());
        qDebug()<<path;
        if(!path.length()){
            this->sendData("DownloadFileResponseFD");
            return;
        }
        this->sendData("DownloadFileResponseOK");
        Utils::sleep(0.1);
        localFile=new QFile(path);
        if(!localFile->open(QFile::ReadOnly)){
            qDebug()<<"open	file error!";
            return;
        }

        sendFile=true;
        totalBytes=localFile->size();
        bytesWritten=0;
        loadSize=4*1024;

        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_7);    //要设置版本, 版本号要和接受端读取版本号一致
        QString	fileName=path.right(path.size()-path.lastIndexOf('/')-1);
        //qDebug()<<fileName;
        out<<qint64(0)<<qint64(0)<<fileName;
        totalBytes+=block.size();
        out.device()->seek(0);
        out<<totalBytes<<qint64((block.size()-sizeof(qint64)*2));
        //out<<totalBytes<<qint64(block.size()-sizeof(qint64)*2);
        qDebug()<<totalBytes<<qint64(block.size()-sizeof(qint64)*2)<<fileName;

        bytesToWrite=totalBytes-socket->write(block);

        block.resize(0);
    }else if(type=="GetCoursewareRequest"){
        QString cnostr;
        in>>cnostr;
        QList<Courseware> list=Database::get_courseware_info_by_cno(cnostr.toInt());
        qDebug()<<list.size();
        if(!list.size()) out<<tr("GetCoursewareResponseFD");
        else{
            out<<tr("GetCoursewareResponseOK");
            out<<list.size();
            foreach (Courseware cw, list) {
                out<<cw.cwname<<cw.cwno;
                qDebug()<<cw.cwname<<cw.cwno;
            }
        }
    }
    socket->write(block);
}

void TCPComHandler::UpdateClientProgress(qint64 numBytes)
{
    if(!sendFile) return;
    qDebug()<<bytesWritten<<numBytes;
    bytesWritten+=(int)numBytes;
    if(bytesWritten>0){
        block=localFile->read(qMin(bytesToWrite,loadSize));
        bytesToWrite-=(int)socket->write(block);
        block.resize(0);
    }else{
        localFile->close();
    }
    if(bytesWritten==totalBytes){
        localFile->close();
        qDebug()<<"OK";
        delete localFile;
        sendFile=false;
    }
}

void TCPComHandler::UpdateServerProgress()
{
    if(!readFile) return;
    QDataStream	in(socket);
    in.setVersion(QDataStream::Qt_5_7);
    qDebug()<<"received"<<bytesReceived;
    qDebug()<<"available"<<socket->bytesAvailable();
    if(bytesReceived<=sizeof(qint64)*2){
        if(socket->bytesAvailable()>=sizeof(qint64)*2 && fileNameSize==0){
            in>>totalBytes>>fileNameSize;
            qDebug()<<totalBytes<<fileNameSize;
            bytesReceived+=sizeof(qint64)*2;
        }
        if(socket->bytesAvailable()>=fileNameSize && fileNameSize!=0){
            in>>fileName;
            bytesReceived+=fileNameSize;
            qDebug()<<"name"<<fileName;
            QString fdpath="/home/daniel/Qt/projects/TStogetherServer/upload/"+cnostr;
            QDir folder(fdpath);
            if(!folder.exists()){
                if(!folder.mkdir(fdpath)){
                    this->updateFileErrorHandler();
                    qDebug()<<"cannot create folder";
                }
            }
            filepath=fdpath+"/"+fileName;
            localFile=new QFile(filepath);
            if(!localFile->open(QFile::WriteOnly|QIODevice::Text)){
                qDebug()<<"open file error!";
                this->updateFileErrorHandler();
            }
        }else return;
    }
    if(bytesReceived<totalBytes){
        qDebug()<<"receiving"<<bytesReceived;
        bytesReceived+=socket->bytesAvailable();
        block=socket->readAll();
        localFile->write(block);
        block.resize(0);
    }
    if(bytesReceived==totalBytes){
        qDebug()<<"received finished";
        localFile->close();
        readFile=false;
        qDebug()<<"ok";

        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_7);
        int fno=Database::add_courseware(cnostr.toInt(),filepath);
        if(!fno) out<<tr("UploadFileResponseFD");
        else{
            out<<tr("UploadFileResponseOK");
            out<<fno;
        }
        socket->write(block);
    }
}

void TCPComHandler::SendMessageResponse(bool user,int uno, int cno, QString name, QString msg)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_7);
    bool flag;
    if(user) flag=Database::teacher_start_course(number,cno);
    else flag=Database::student_join_course(number,cno);
    if(!flag){
        if(this->user==user && number==uno) out<<tr("SendMessageResponseFD");
        else return;
    }else{
        out<<tr("SendMessageResponseOK");
        //qDebug()<<name<<cno<<msg;
        out<<name<<cno<<msg;
    }
    socket->write(block);
}

TCPComHandler::TCPComHandler(QTcpSocket *tcpsocket)
{
    localFile=nullptr;
    totalBytes=0;
    bytesReceived=0;
    fileNameSize=0;
    sendFile=false;
    readFile=false;
    socket=tcpsocket;
    connect(socket,SIGNAL(readyRead()),this,SLOT(handleData()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(UpdateServerProgress()));
    connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(UpdateClientProgress(qint64)));
}

void TCPComHandler::sendData(QString type)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_7);
    out<<type;
    socket->write(block);
}

void TCPComHandler::updateFileErrorHandler()
{
    if(localFile!=nullptr){
        localFile->close();
        delete localFile;
    }
    readFile=false;
    sendData("UploadFileResponseFD");
}
