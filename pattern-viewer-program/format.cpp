#include "format.h"

format::format(QWidget *parent) : QWidget(parent)
{

}

void format::startformat(){
    QByteArray arr = Widget::get_file_arr();;
    set_file_arr(arr);
    //qDebug()<< arr.toHex();

    division[0][0].push_back("File Header");division[0][1].push_back('u');division[0][2].push_back('u');


