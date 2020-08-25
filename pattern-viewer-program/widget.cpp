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
        if(i%2==0)
            string_arr.append(" ");
        if(i%32==0){
            string_arr.append("\n line "+QString::number(cnt)+":  ");
            cnt+=1;
        }
        string_arr.append(temp_string_arr[i]);
    }

    format formatt ; //= new format();
    formatt.startformat();




    ui->textedit->setText(string_arr);


    ui->textedit2->setText("File Header\n");

    ui->textedit2->append("Discernment Code");
    ui->textedit2->append(formatt.read_FileHeaderDiscernmentCode());
    ui->textedit2->append("Source File Name");
    ui->textedit2->append(formatt.read_FileHeaderSourceFileName());
    ui->textedit2->append("Compile Date");
    ui->textedit2->append(formatt.read_FileHeaderCompileDate());
    ui->textedit2->append(string_arr);



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
