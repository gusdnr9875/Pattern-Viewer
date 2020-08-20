#include "widget.h"
#include "ui_widget.h"
#include "file.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    file_read(); // file open and read
    QByteArray arr = Widget::get_file_arr();

    QString temp_string_arr = arr.toHex();
    QString string_arr;
    int cnt = 1;
    for(int i=0;i<temp_string_arr.size();i++){
        if(i%2==0)
            string_arr.append(" ");
        if(i%32==0){
            string_arr.append("\n line "+QString::number(cnt)+":  ");
            cnt+=1;
        }
        string_arr.append(temp_string_arr[i]);

    }
    //qDebug()<<aar;
    //ui->textEdit->setTextColor(Qt::);
   //setAutoFillBackground(true);
    setPalette(Qt::gray);


    ui->textedit->setText(string_arr);
}

Widget::~Widget()
{
    delete ui;
}

QByteArray Widget::file_arr={};

QByteArray Widget::get_file_arr(){return file_arr; }//get file data
void Widget::set_file_arr(QByteArray arr){file_arr =arr;}// set file data


void Widget::file_read(){
    file* f = new file();
    f->file_read();
}

void Widget::on_search_button1_clicked()
{
    file_search();
}

void Widget::on_nextbutton1_clicked()
{
    file_search_cursor();
}
