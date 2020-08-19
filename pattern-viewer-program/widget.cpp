#include "widget.h"
#include "ui_widget.h"
#include "file.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    file* f = new file();
    f->file_read();

    QByteArray arr = Widget::get_file_arr();
   // qDebug()<<arr.toHex();
    ui->textEdit->setText(arr.toHex());
}

Widget::~Widget()
{
    delete ui;
}

QByteArray Widget::file_arr={};

QByteArray Widget::get_file_arr(){return file_arr; }
void Widget::set_file_arr(QByteArray arr){file_arr =arr;}


