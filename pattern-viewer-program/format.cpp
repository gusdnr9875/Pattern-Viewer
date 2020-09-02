#include "format.h"

format::format(QWidget *parent) : QWidget(parent)
{

}

void format::startformat(){
    QByteArray arr = Widget::get_file_arr();;
    set_file_arr(arr);
    //qDebug()<< arr.toHex();


}

QString format::read_FileHeaderDiscernmentCode(){
    // u       1       4


    QString temp2;
    int cnt = 0;
    for(int i=started;i<ended;i++){
        if(cnt!=0)
            temp2.append(" ");
        if(cnt%32==0 && cnt!=0)
            temp2.append("\n");
        cnt++;
        QByteArray temp;
        temp.append(originalfile.at(i));
        temp2.append(temp.toHex());
    }
    return temp2;
}

QByteArray format::read_FileHeaderSourceFileName(){
    //   c       36      36
    started = ended;
    ended += 36;
    QByteArray temp;
    for(int i=started;i<ended;i++)
        temp.append(originalfile.at(i));
    return temp;

}

QByteArray format::read_FileHeaderCompileDate(){
    //   c       8       8
    started = ended;
    ended += 8;
    QByteArray temp;
    for(int i=started;i<ended;i++)
        temp.append(originalfile.at(i));
    return temp;
}
QByteArray format::read_FileHeaderCompileTime(){
    //   c       8       8
    started = ended;
    ended += 8;
    QByteArray temp;
    for(int i=started;i<ended;i++)
        temp.append(originalfile.at(i));
    return temp;
}
QByteArray format::read_FileHeaderCompilerVersion(){
    //   c       8       8
    started = ended;
    ended += 8;
    QByteArray temp;
    for(int i=started;i<ended;i++)
        temp.append(originalfile.at(i));
    return temp;
}


QString format::read_FileHeaderTheflagofCommon(){
    //   u       1       4
    started = ended;
    ended += 4;

    QString temp2;
    int cnt = 0;
    for(int i=started;i<ended;i++){
        if(cnt!=0)
            temp2.append(" ");
        if(cnt%32==0 && cnt!=0)
            temp2.append("\n");
        cnt++;
        QByteArray temp;
        temp.append(originalfile.at(i));
        temp2.append(temp.toHex());
    }
    return temp2;
}
QString format::read_FileHeaderThecountofBlock(){
    //   u       1       4
    started = ended;
    ended += 4;

    QString temp2;
    int cnt = 0;
    for(int i=started;i<ended;i++){
        if(cnt!=0)
            temp2.append(" ");
        if(cnt%32==0 && cnt!=0)
            temp2.append("\n");
        cnt++;
        QByteArray temp;
        temp.append(originalfile.at(i));
        temp2.append(temp.toHex());
    }
    return temp2;
}

QString format::read_FileHeaderTheOffsetsofCommon(){
    //   u       1       4
    started = ended;
    ended += 4;

    QString temp2;
    int cnt = 0;
    for(int i=started;i<ended;i++){
        if(cnt!=0)
            temp2.append(" ");
        if(cnt%32==0 && cnt!=0)
            temp2.append("\n");
        cnt++;
        QByteArray temp;
        temp.append(originalfile.at(i));
        temp2.append(temp.toHex());
    }
    return temp2;
}
QString format::read_FileHeaderTheOffsetsofBlocks(){
    //   u       64       256
    started = ended;
    ended += 256;

    QString temp2;
    int cnt = 0;
    for(int i=started;i<ended;i++){
        if(cnt!=0)
            temp2.append(" ");
        if(cnt%32==0 && cnt!=0)
            temp2.append("\n");
        cnt++;
        QByteArray temp;
        temp.append(originalfile.at(i));
        temp2.append(temp.toHex());
    }
    return temp2;
}
QString format::read_FileHeaderTheStartAddressArray(){
    //   u       64       256
    started = ended;
    ended += 256;

    QString temp2;
    int cnt = 0;
    for(int i=started;i<ended;i++){
        if(cnt!=0)
            temp2.append(" ");
        if(cnt%32==0 && cnt!=0)
            temp2.append("\n");
        cnt++;
        QByteArray temp;
        temp.append(originalfile.at(i));
        temp2.append(temp.toHex());
    }
    return temp2;
}
QString format::read_FileHeaderRemark(){
    //   c       80       80
    started = ended;
    ended += 80;
    QString temp2;
    int cnt = 0;
    for(int i=started;i<ended;i++){
        if(cnt!=0)
            temp2.append(" ");
        if(cnt%32==0 && cnt!=0)
            temp2.append("\n");
        cnt++;
        QByteArray temp;
        temp.append(originalfile.at(i));
        temp2.append(temp.toHex());
    }
    return temp2;
}
QString format::read_FileHeaderTheDataofIL(){
    //   c       80       80
    started = ended;
    ended += 4;
    QString temp2;
    int cnt = 0;
    for(int i=started;i<ended;i++){
        if(cnt!=0)
            temp2.append(" ");
        if(cnt%32==0 && cnt!=0)
            temp2.append("\n");
        cnt++;
        QByteArray temp;
        temp.append(originalfile.at(i));
        temp2.append(temp.toHex());
    }
    return temp2;
}
QString format::read_FileHeaderReserved(){
    //   c       80       80
    started = ended;
    ended += 16;
    QString temp2;
    int cnt = 0;
    for(int i=started;i<ended;i++){
        if(cnt!=0)
            temp2.append(" ");
        if(cnt%32==0 && cnt!=0)
            temp2.append("\n");
        cnt++;
        QByteArray temp;
        temp.append(originalfile.at(i));
        temp2.append(temp.toHex());
    }
    return temp2;
}

