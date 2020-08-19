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
    QString keyword = ui->keyword1->text();
    QTextDocument *document = ui->textedit ->document();

    bool found = false;

    // undo previous change (if any)
    document->undo();

    if(keyword.isEmpty()){
        QMessageBox::information(this, tr("Empty Search Feild"), tr("The search field is empty. "));
    }
    else{
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;

        colorFormat.setForeground(Qt::red);
        colorFormat.setBackground(Qt::black);
        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
                    highlightCursor = document->find(keyword, highlightCursor,
                                                     QTextDocument::FindWholeWords);

                if (!highlightCursor.isNull()) {
                        found = true;
                        highlightCursor.movePosition(QTextCursor::WordRight,
                                                     QTextCursor::KeepAnchor);
                        highlightCursor.mergeCharFormat(colorFormat);
                }
        }

        cursor.endEditBlock();
        if (found == false) {
                   QMessageBox::information(this, tr("Word Not Found"),
                                            tr("Sorry, the word cannot be found."));
        }

    }
}
