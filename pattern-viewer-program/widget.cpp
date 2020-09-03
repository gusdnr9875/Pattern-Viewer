#include "widget.h"
#include "ui_widget.h"
#include "file.h"
#include "format.h"

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
        if(i%2==0 && i!=0)
            string_arr.append(" ");
        if(i%32==0){
            string_arr.append("\n line "+QString::number(cnt)+":  ");
            cnt+=1;
        }
        string_arr.append(temp_string_arr[i]);
    }


    excel_read();
    get_r_s_p();
    set_startingarr();


    ui->filename->setText(get_filename());
    ui->textedit->setFontPointSize(15);
    ui->textedit->setText(string_arr);


    ui->textedit2->setText(right_total());



    division_FileHeader();
    division_CommonHeader();
    division_CommonBody();
    division_blockHeader();
   // division_blockBody();



}

Widget::~Widget()
{
    delete ui;
}

QByteArray Widget::file_arr={};
QString Widget::filename={};
QByteArray Widget::get_file_arr(){return file_arr; }//get file data
void Widget::set_file_arr(QByteArray arr){file_arr =arr;}// set file data
QString Widget::get_filename(){return filename;}        // get filename
void Widget::set_filename(QString name){filename = name;} // set filename

void Widget::file_read(){
    file* f = new file();

    f->file_read();
}

void Widget::on_search_button1_clicked()
{
    file_search();
}
void Widget::on_search_button2_clicked()
{
    file_search_right();
}


void Widget::on_nextbutton1_clicked()
{
    file_search_cursor();
}

void Widget::on_nextbutton2_clicked()
{
    file_search_cursor_right();
}


void Widget::on_close_clicked()
{
    this->close();
}



void Widget::on_fileSelect_clicked()
{


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



    ui->textedit->setTextColor(Qt::black);
    ui->textedit2->setTextColor(Qt::black);
    ui->textedit->setTextBackgroundColor(Qt::white);
    ui->textedit2->setTextBackgroundColor(Qt::white);
    ui->filename->setText(get_filename());

    ui->textedit->setText(string_arr);
    ui->textedit2->setText(right_total());




}









