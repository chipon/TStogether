#include "tcpcomhandler.h"

void TcpComHandler::readData()
{
    qDebug()<<sendFile<<readFile;
    if(readFile) return;
    QString type;
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_7);
    in>>type;
    qDebug()<<"receive"<<type;
    if(type=="LoginOK") {
        emit LoginOK();
    }else if(type=="LoginFailed"){
        emit LoginFailed();
    }else if(type=="GetStudentInfoFailed"){
        emit GetStudentInfoFailed();
    }else if(type=="GetStudentInfoOK"){
        Student *stu=new Student();
        in>>stu->sno>>stu->snickname>>stu->spwd>>stu->sname>>stu->sgrade>>stu->sdept>>stu->smajor>>stu->ssignature;
        //qDebug()<<stu->snickname<<stu->spwd;
        emit GetStudentInfoOK(stu);
    }else if(type=="GetTeacherInfoOK"){
        Teacher *t=new Teacher();
        in>>t->tdept>>t->temail>>t->tname>>t->tno>>t->tpwd;
        emit GetTeacherInfoOK(t);
    }else if(type=="GetTeacherInfoFailed"){
        emit GetTeacherInfoFailed();
    }else if(type=="UpdateStudentInfoOK"){
        emit UpdateStudentInfoOK();
    }else if(type=="UpdateStudentInfoFailed"){
        emit UpdateStudentInfoFailed();
    }else if(type=="UpdateTeacherInfoOK"){
        emit UpdateTeacherInfoOK();
    }else if(type=="UpdateTeacherInfoFailed"){
        emit UpdateTeacherInfoFailed();
    }else if(type=="GetDeptInfoOK"){
        Dept dept;
        QString major;
        int size,msize;
        QList<Dept> *list=new QList<Dept>();
        in>>size;
        for(int i=0;i<size;++i){
            in>>dept.dname;
            in>>msize;
            dept.majors.clear();
            for(int j=0;j<msize;++j){
                in>>major;
                dept.majors.append(major);
            }
            list->append(dept);
        }
        emit GetDeptInfoOK(list);
    }else if(type=="GetDeptInfoFailed"){
        emit GetDeptInfoFailed();
    }else if(type=="FindTeacherByTnoOK"){
        QString tname;
        in>>tname;
        qDebug()<<tname;
        emit FindTeacherByTnoResponseOK(tname);
    }else if(type=="FindTeacherByTnoFailed"){
        emit FindTeacherByTnoResponseFD();
    }else if(type=="CreateCourseResponseOK"){
        int cno;
        in>>cno;
        emit CreateCourseResponseOK(cno);
    }else if(type=="CreateCourseResponseFD"){
        emit CreateCourseResponseFD();
    }else if(type=="GetTeacherCourseResponseOK"){
        int size;
        QString tmp;
        QList<QString> *list=new QList<QString>();
        in>>size;
        for(int i=0;i<size;++i){
            in>>tmp;
            list->append(tmp);
        }
        emit GetTeacherCourseResponseOK(list);
    }else if(type=="GetTeacherCourseResponseFD"){
        emit GetTeacherCourseResponseFD();
    }else if(type=="GetCourseInfoResponseOK"){
        Course *c=new Course();
        //qDebug()<<c;
        int size,tno;
        QString tname;
        in>>c->cdept>>c->cintro>>c->cmajor>>c->cname>>c->cno>>c->cnotice;
        //qDebug()<<"name:"<<c->cname;
        in>>size;
        for(int i=0;i<size;++i){
            in>>tname;
            c->tnamelist.append(tname);
        }
        in>>size;
        for(int i=0;i<size;++i){
            in>>tno;
            c->tnolist.append(tno);
        }
        emit GetCourseInfoResponseOK(c);
    }else if(type=="GetCourseInfoResponseFD"){
        emit GetCourseInfoResponseFD();
    }else if(type=="SearchCourseResponseOK"){
        int size,tsize;
        QString tname;
        in>>size;
        //qDebug()<<"size"<<size;
        QList<Course> *result=new QList<Course>();
        for(int i=0;i<size;++i){
            Course c;
            in>>c.cname>>c.cno>>c.ctime;
            //qDebug()<<c.cname<<c.cno<<c.ctime;
            in>>tsize;
            for(int j=0;j<tsize;++j){
                in>>tname;
                c.tnamelist.append(tname);
            }
            result->append(c);
        }
        emit SearchCourseResponseOK(result);
    }else if(type=="SearchCourseResponseFD"){
        emit SearchCourseResponseFD();
    }else if(type=="AddCourseResponseOK"){
        emit AddCourseResponseOK();
    }else if(type=="AddCourseResponseFD"){
        emit AddCourseResponseFD();
    }else if(type=="GetStudentCourseResponseOK"){
        int size;
        QString str;
        QList<QString> *list=new QList<QString>();
        in>>size;
        for(int i=0;i<size;++i){
            in>>str;
            list->append(str);
        }
        emit GetStudentCourseResponseOK(list);
    }else if(type=="GetStudentCourseResponseFD"){
        emit GetStudentCourseResponseFD();
    }else if(type=="SendMessageResponseOK"){
        int cno;
        QString name,msg;
        in>>name>>cno>>msg;
        qDebug()<<"receive"<<name<<cno<<msg;
        emit SendMessageResponseOK(name,cno,msg);
        Utils::sleep(0.1);
    }else if(type=="SendMessageResponseFD"){
        emit SendMessageResponseFD();
    }else if(type=="GetRecentMessageResponseOK"){
        int cno,size;
        Message m;
        QList<Message> *list=new QList<Message>();
        in>>cno;
        in>>size;
        //qDebug()<<"size"<<size;
        for(int i=0;i<size;++i){
            in>>m.msg>>m.name>>m.time;
            list->append(m);
        }
        emit GetRecentMessageResponseOK(cno,list);
        Utils::sleep(0.1);
    }else if(type=="GetRecentMessageResponseFD"){
        emit GetRecentMessageResponseFD();
    }else if(type=="UploadFileResponseOK"){
        int fno;
        in>>fno;
        fpd.accept();
        emit UploadFileResponseOK(fno);
    }else if(type=="UploadFileResponseFD"){
        emit UploadFileResponseFD();
        fpd.reject();
    }else if(type=="DownloadFileResponseOK"){
        //in>>cnostr;
        //in.commitTransaction();
        qDebug()<<"cno"<<cnostr;
        totalBytes=0;
        bytesReceived=0;
        fileNameSize=0;
        readFile=true;
        //fpd.exec();
    }else if(type=="DownloadFileResponseFD"){
        emit DownloadFileResponseFD();
    }else if(type=="GetCoursewareResponseOK"){
        int size;
        in>>size;
        Courseware cw;
        QList<Courseware> *list=new QList<Courseware>();
        for(int i=0;i<size;++i){
            in>>cw.cwname>>cw.cwno;
            list->append(cw);
        }
        emit GetCoursewareResponseOK(list);
    }else if(type=="GetCoursewareResponseFD"){
        emit GetCoursewareResponseFD();
    }
}

void TcpComHandler::UploadFileRequest(QString path,QList<QString> *list)
{
    //this->sendData("UploadFileRequest");
    this->sendData("UploadFileRequest",list);
    //Utils::sleep(0.05);
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_7);    //要设置版本, 版本号要和接受端读取版本号一致

    localFile=new QFile(path);
    if(!localFile->open(QFile::ReadOnly)){
        qDebug()<<"open	file error!";
        return;
    }

    sendFile=true;
    totalBytes=localFile->size();
    bytesWritten=0;
    loadSize=4*1024;
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
    fpd.setMaxValue(totalBytes);
    fpd.exec();
}

void TcpComHandler::UpdateClientProgress(qint64 numBytes)
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
    fpd.updateValue(bytesWritten);
    if(bytesWritten==totalBytes){
        localFile->close();
        fpd.accept();
        qDebug()<<"OK";
        delete localFile;
        sendFile=false;
    }
}
void TcpComHandler::UpdateServerProgress()
{
    //qDebug()<<"ok";
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
            filepath=folder+"/"+fileName;
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
    //fpd.setMaxValue(totalBytes);
    //fpd.updateValue(bytesReceived);
    if(bytesReceived==totalBytes){
        qDebug()<<"received finished";
        localFile->close();
        readFile=false;
        qDebug()<<"ok";
        emit DownloadFileResponseOK(cnostr.toInt());
        //fpd.accept();
    }
}

void TcpComHandler::updateFileErrorHandler()
{
    if(localFile!=nullptr){
        localFile->close();
        delete localFile;
    }
    readFile=false;
    emit DownloadFileResponseFD();
}

void TcpComHandler::DownloadFileRequest(QString type, QList<QString> *list)
{
    folder=list->at(1);
    list->removeAt(1);
    cnostr=list->at(1);
    list->removeAt(1);
    this->sendData(type,list);
    //list->remo
}

TcpComHandler::TcpComHandler()
{
    localFile=nullptr;
    totalBytes=0;
    bytesReceived=0;
    fileNameSize=0;

    readFile=false;
    sendFile=false;
    socket=new QTcpSocket(this);
    socket->abort();
    socket->connectToHost(QHostAddress::LocalHost, 6666);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(UpdateServerProgress()));
    connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(UpdateClientProgress(qint64)));
}

void TcpComHandler::sendData(QString type, QList<QString> *list)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_7);    //要设置版本, 版本号要和接受端读取版本号一致
    out<<type;
    qDebug()<<"client send"<<type;
    qDebug()<<"content:";
    if(list!=nullptr){
        foreach (QString tmp, *list) {
            out<<tmp;
            qDebug()<<tmp;
        }
    }
    qDebug()<<"";
    socket->write(block);
    delete list;
}

void TcpComHandler::sendData(QString type)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_7);    //要设置版本, 版本号要和接受端读取版本号一致
    out<<type;
    socket->write(block);
    qDebug()<<"client send"<<type;
}

