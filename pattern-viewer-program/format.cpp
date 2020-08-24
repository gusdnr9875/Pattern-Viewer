#include "format.h"

format::format(QWidget *parent) : QWidget(parent)
{

}

void format::startformat(){
    QByteArray arr = Widget::get_file_arr();;
    set_file_arr(arr);
    //qDebug()<< arr.toHex();


 }

QByteArray format::read_FileHeaderDiscernmentCode(){
    // u       1       4

     QByteArray temp;
     for(int i=started;i<ended;i++){
         if(i%2==0)
            temp.append();
         temp.append(originalfile.at(i));
      }
     return temp;
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
