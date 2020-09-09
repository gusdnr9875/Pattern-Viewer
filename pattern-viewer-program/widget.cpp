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
    division_blockBody();

    print_MicroPattern();

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
    division_blockBody();

    print_MicroPattern();

    ui->textedit->setTextColor(Qt::black);
    ui->textedit2->setTextColor(Qt::black);
    ui->textedit->setTextBackgroundColor(Qt::white);
    ui->textedit2->setTextBackgroundColor(Qt::white);





}










void Widget::on_tabwidget_tabBarClicked(int index)
{
    if(index == 0){
    ui->search_button2->setEnabled(true);
    ui->clear2->setEnabled(true);
    ui->radioButton2_1->setEnabled(true);
    ui->radioButton2_2->setEnabled(true);
    ui->radioButton2_3->setEnabled(true);
    ui->radioButton2_4->setEnabled(true);
    ui->radioButton2_5->setEnabled(true);
    }
    else{
        ui->search_button2->setEnabled(false);
        ui->nextbutton2->setEnabled(false);
        ui->clear2->setEnabled(false);
        ui->radioButton2_1->setEnabled(false);
        ui->radioButton2_2->setEnabled(false);
        ui->radioButton2_3->setEnabled(false);
        ui->radioButton2_4->setEnabled(false);
        ui->radioButton2_5->setEnabled(false);
    }
}














void Widget::on_downloadLine_clicked()
{


    QString ApplicationPath = QApplication::applicationDirPath();
    QFile File("./line.txt");




    //파일
    if(!File.open(QIODevice::WriteOnly)) // 텍스트로 파일 열기
    {
         if(!File.exists()) // 파일이 존재하지 않으면...
        {
             qDebug()<<"file is not exist";// 파일이 존재하지 않으면...여기에 동작 적용
             return;
        }
        else
        {
            qDebug()<<"file is not open";// 파일을 열수 없거나 파일 손상 등 여러 요인작용...
        }
    }
   // QDataStream OpenFile(&File);
   // QString ConfigText;
    File.write(string_arr.toUtf8());

    File.close(); // 파일닫기

    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.exec();

}

void Widget::on_downloadFormat_clicked()
{
    QString ApplicationPath = QApplication::applicationDirPath();
    QFile File("./format.txt");




    //파일
    if(!File.open(QIODevice::WriteOnly)) // 텍스트로 파일 열기
    {
         if(!File.exists()) // 파일이 존재하지 않으면...
        {
             qDebug()<<"file is not exist";// 파일이 존재하지 않으면...여기에 동작 적용
             return;
        }
        else
        {
            qDebug()<<"file is not open";// 파일을 열수 없거나 파일 손상 등 여러 요인작용...
        }
    }
   // QDataStream OpenFile(&File);
   // QString ConfigText;
    File.write(right_total().toUtf8());

    File.close(); // 파일닫기

    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.exec();

}

