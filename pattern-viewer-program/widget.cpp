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





   ui->filename->setText(get_filename());
   // ui->filename->setText( QString::number( temp_number++));
    ui->textedit->setFontPointSize(15);
    ui->textedit->setText(string_arr);

    printheader_left();


    /*
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->selectAll();

    ui->textEdit->setTextCursor( cursor );
    */
    ui->tablewidget->setRowCount(10);
    ui->tablewidget->setColumnCount(10);


    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            QTableWidgetItem* item = ui->tablewidget->item(i,j);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget->setItem(i,j,item);
            }
            QByteArray hexDataOne;
            hexDataOne.append("a");
            item->setText(hexDataOne.toHex());
        }



    }
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

void Widget::on_nextbutton1_clicked()
{
    file_search_cursor();
}

void Widget::on_close_clicked()
{
    this->close();
}

void Widget::printheader_left()
{

    format formatt ; //= new format();
    formatt.startformat();

    ui->textedit2->setText("File Header\n");

    ui->textedit2->append("Discernment Code");
    ui->textedit2->append(formatt.read_FileHeaderDiscernmentCode());
    ui->textedit2->append("Source File Name");
    ui->textedit2->append(formatt.read_FileHeaderSourceFileName());
    ui->textedit2->append("Compile Date");
    ui->textedit2->append(formatt.read_FileHeaderCompileDate());
    ui->textedit2->append("Compile Time");
    ui->textedit2->append(formatt.read_FileHeaderCompileTime());
    ui->textedit2->append("Compiler Version");
    ui->textedit2->append(formatt.read_FileHeaderCompilerVersion());
    ui->textedit2->append("The flag of Common");
    ui->textedit2->append(formatt.read_FileHeaderTheflagofCommon());
    ui->textedit2->append("The count of Block");
    ui->textedit2->append(formatt.read_FileHeaderThecountofBlock());
    ui->textedit2->append("The Offsets of Common");
    ui->textedit2->append(formatt.read_FileHeaderTheOffsetsofCommon());

    ui->textedit2->append("The Offsets of Blocks");
    ui->textedit2->append(formatt.read_FileHeaderTheOffsetsofBlocks());
    ui->textedit2->append("The Start Address Array");
    ui->textedit2->append(formatt.read_FileHeaderTheStartAddressArray());
    ui->textedit2->append("Remark");
    ui->textedit2->append(formatt.read_FileHeaderRemark());
    ui->textedit2->append("The Data of IL-MODE");
    ui->textedit2->append(formatt.read_FileHeaderTheDataofIL());
    ui->textedit2->append("Reserved");
    ui->textedit2->append(formatt.read_FileHeaderReserved());

    ui->textedit2->append("\n\n");
   //ui->textedit2->append(string_arr);
test_func();
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





    ui->filename->setText(get_filename());
    //ui->filename->setText( QString::number( temp_number++));

    ui->textedit->setText(string_arr);

    printheader_left();


}

void Widget::test_func(){
    Document xlsxR("/home/hyunwook/pattern-viwer/Pattern-Viewer/configuration.xlsx");
    if (xlsxR.load()) // load excel file
        {
            qDebug() << "load open";
            int row = 1; int col = 1;
            Cell* cell = xlsxR.cellAt(row, col); // get cell pointer.
            if ( cell != NULL )
            {
                QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
                qDebug() << var; // display value. it is 'Hello Qt!'.
            }
        }




}
