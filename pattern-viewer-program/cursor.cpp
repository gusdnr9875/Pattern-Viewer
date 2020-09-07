#include "widget.h"
#include "ui_widget.h"
#include "file.h"
#include "format.h"


void Widget::get_r_s_p(){


    QByteArray filedata = get_file_arr(); //  get file data
    int started =0;
    int ended =0;


    int cr,cs;

    for(int i=0;i<=33;i++){

        if(i==2)
            ended = excelformat[i][4].toInt();
        else{
            started = ended;
            ended += excelformat[i][4].toInt();
        }
        if(excelformat[i][0]=="COMMON HEADER" && excelformat[i][1] == "The count of Opcode and Data Set (Data : 32bit) : r" ){

            QByteArray temp;

            temp.append(filedata.at(started));

            bool ok;

            commonbody_r =  temp.toHex().toInt(&ok,16);
            //  qDebug()<<commonbody_r;
            cr = commonbody_r;
            // qDebug()<<blockbody_r;
        }
        else if(excelformat[i][0]=="COMMON HEADER" && excelformat[i][1] == "The count of Opcode and Data Set (Data : 64bit) : s" ){


            QByteArray temp;

            temp.append(filedata.at(started));

            bool ok;

            commonbody_s =  temp.toHex().toInt(&ok,16);
            cs = commonbody_s;
            // qDebug()<<blockbody_s;

        }

        else if(excelformat[i][0]=="BLOCK1 HEADER" && excelformat[i][1] == "The count of Opcode and Data Set (Data : 32bit) : r" ){


            QByteArray temp;

            temp.append(filedata.at(started));

            bool ok;

            blockbody_r =  temp.toHex().toInt(&ok,16);

            // qDebug()<<blockbody_s;

        }

        else if(excelformat[i][0]=="BLOCK1 HEADER" && excelformat[i][1] == "The count of Opcode and Data Set (Data : 64bit) : s" ){


            QByteArray temp;

            temp.append(filedata.at(started));

            bool ok;

            blockbody_s =  temp.toHex().toInt(&ok,16);

            // qDebug()<<blockbody_s;

        }





        else if(excelformat[i][0]=="BLOCK1 HEADER" && excelformat[i][1] == "Micro Pattern Count : p" ){


            QString temp;

            for(int i= ended - 1; i>=started;i--){
                QByteArray temp2;
                temp2.append(filedata.at(i));
                temp += temp2.toHex();
            }





            bool ok;

            blockbody_p =  temp.toUInt(&ok,16);//.toHex().toInt(&ok,16);

            // qDebug()<<blockbody_p;

        }

        if(excelformat[i][0]=="COMMON BODY"&&excelformat[i][1]=="Register(32bit) DATA"&& (cr - 1) > 0){
            cr--;
            i-=2;


        }
        else if(excelformat[i][0]=="COMMON BODY"&&excelformat[i][1]=="Register(64bit) DATA"&& (cs - 1) > 0){
            cs--;
            i-=2;
        }




    }
    /*
    qDebug()<<commonbody_r;
    qDebug()<<commonbody_s;
    qDebug()<<blockbody_r;
    qDebug()<<blockbody_s;
    qDebug()<<blockbody_p;
    */



}



void Widget::set_startingarr(){




   int  started=0;
    int ended =0;

    //CommonHeader
    for(int i=0;i<=33;i++){
        if(excelformat[i][0] == "File Header"){
            started = ended;
            ended += excelformat[i][4].toInt();
        }
    }

    commonheader_startingarr = ended;

    //CommonBody
    for(int i=0;i<=33;i++){
        if(excelformat[i][0] == "COMMON HEADER"){
            started = ended;
            ended += excelformat[i][4].toInt();
        }

    }
    commonbody_startingarr = ended;

    //BlcokHeader
    int cr = commonbody_r;
    int cs = commonbody_s;
    int br = blockbody_r;
    int bs = blockbody_s;
    int bp = blockbody_p;



    for(int i=0;i<=33;i++){
         if(excelformat[i][0] == "COMMON BODY" || excelformat[i][0] == "START BLOCK"){
            started = ended;
            ended += excelformat[i][4].toInt();
         }

         if(excelformat[i][0]=="COMMON BODY" && excelformat[i][1]=="Register(32bit) DATA"&& (cr - 1) > 0){
             cr--;
             i-=2;
         }
         else if(excelformat[i][0]=="COMMON BODY" && excelformat[i][1]=="Register(64bit) DATA"&& (cs - 1) > 0){
             cs--;
             i-=2;
         }
    }


    blockheader_startingarr = ended;
    /*
    qDebug() << commonheader_startingarr;
    qDebug() << commonbody_startingarr;
    qDebug() << blockheader_startingarr;
    */

    for(int i=0;i<=33;i++){
         if(excelformat[i][0] == "BLOCK1 HEADER" ){
            started = ended;
            ended += excelformat[i][4].toInt();
         }


    }
    blockbody_startingarr =ended;

}


void Widget::on_radioButton1_1_clicked()
{
    QString keyword = "line ";
    keyword.append(QString::number( fileheader_startingarr/16 + 1 ));

    //qDebug()<<keyword;

    QTextDocument *document = ui->textedit ->document();


    bool found = false;

    // undo previous change (if any)
    document->undo();


    if(keyword.isEmpty()){
        QMessageBox::information(this, tr("Empty Search Feild"), tr("The search field is empty. "));
        ui->nextbutton1->setEnabled(false);
    }


    else{
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;

        // colorFormat.setForeground(Qt::red);
        //colorFormat.setBackground(Qt::black);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(keyword, highlightCursor,
                                             QTextDocument::FindWholeWords);
            //qDebug()<<"search";
            //  cursor_cnt++;
            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                ui->textedit->setTextCursor(highlightCursor);
                //highlightCursor.mergeCharFormat(colorFormat);
            }
        }

        cursor.endEditBlock();
        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }




    }





}






void Widget::on_radioButton1_2_clicked()
{
    QString keyword = "line ";
    keyword.append(QString::number( commonheader_startingarr/16 + 1 ));
    //qDebug()<<keyword;

    QTextDocument *document = ui->textedit ->document();


    bool found = false;

    // undo previous change (if any)
    document->undo();


    if(keyword.isEmpty()){
        QMessageBox::information(this, tr("Empty Search Feild"), tr("The search field is empty. "));
        ui->nextbutton1->setEnabled(false);
    }


    else{
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;

        // colorFormat.setForeground(Qt::red);
        //colorFormat.setBackground(Qt::black);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(keyword, highlightCursor,
                                             QTextDocument::FindWholeWords);
            //qDebug()<<"search";
            //  cursor_cnt++;
            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                ui->textedit->setTextCursor(highlightCursor);
                //highlightCursor.mergeCharFormat(colorFormat);
            }
        }

        cursor.endEditBlock();
        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }




    }



}





void Widget::on_radioButton1_3_clicked()
{
    QString keyword = "line ";
    keyword.append(QString::number( commonbody_startingarr/16 + 1 ));
    //qDebug()<<keyword;

    QTextDocument *document = ui->textedit ->document();


    bool found = false;

    // undo previous change (if any)
    document->undo();


    if(keyword.isEmpty()){
        QMessageBox::information(this, tr("Empty Search Feild"), tr("The search field is empty. "));
        ui->nextbutton1->setEnabled(false);
    }


    else{
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;

        // colorFormat.setForeground(Qt::red);
        //colorFormat.setBackground(Qt::black);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(keyword, highlightCursor,
                                             QTextDocument::FindWholeWords);
            //qDebug()<<"search";
            //  cursor_cnt++;
            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                ui->textedit->setTextCursor(highlightCursor);
                //highlightCursor.mergeCharFormat(colorFormat);
            }
        }

        cursor.endEditBlock();
        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }




    }

}


void Widget::on_radioButton1_4_clicked()
{
    QString keyword = "line ";
    keyword.append(QString::number( blockheader_startingarr/16 + 1 ));
    /*
    qDebug() << commonheader_startingarr;
    qDebug() << commonbody_startingarr;
    qDebug() << blockheader_startingarr;
    qDebug()<<keyword;
    */

    QTextDocument *document = ui->textedit ->document();


    bool found = false;

    // undo previous change (if any)
    document->undo();


    if(keyword.isEmpty()){
        QMessageBox::information(this, tr("Empty Search Feild"), tr("The search field is empty. "));
        ui->nextbutton1->setEnabled(false);
    }


    else{
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;

        // colorFormat.setForeground(Qt::red);
        //colorFormat.setBackground(Qt::black);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(keyword, highlightCursor,
                                             QTextDocument::FindWholeWords);
            //qDebug()<<"search";
            //  cursor_cnt++;
            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                ui->textedit->setTextCursor(highlightCursor);
                //highlightCursor.mergeCharFormat(colorFormat);
            }
        }

        cursor.endEditBlock();
        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }

    }

}






void Widget::on_radioButton1_5_clicked()
{
    QString keyword = "line ";
    keyword.append(QString::number( blockbody_startingarr/16 + 1 ));
    /*
    qDebug() << commonheader_startingarr;
    qDebug() << commonbody_startingarr;
    qDebug() << blockheader_startingarr;
    qDebug()<<keyword;
    */

    QTextDocument *document = ui->textedit ->document();


    bool found = false;

    // undo previous change (if any)
    document->undo();


    if(keyword.isEmpty()){
        QMessageBox::information(this, tr("Empty Search Feild"), tr("The search field is empty. "));
        ui->nextbutton1->setEnabled(false);
    }


    else{
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;

        // colorFormat.setForeground(Qt::red);
        //colorFormat.setBackground(Qt::black);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(keyword, highlightCursor,
                                             QTextDocument::FindWholeWords);
            //qDebug()<<"search";
            //  cursor_cnt++;
            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                ui->textedit->setTextCursor(highlightCursor);
                //highlightCursor.mergeCharFormat(colorFormat);
            }
        }

        cursor.endEditBlock();
        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }


    }


}


void Widget::on_radioButton2_1_clicked()
{
    QString keyword;
    for(int i=0;i<=33;i++){
        if(excelformat[i][0] == ui->radioButton2_1->text()){
            keyword = excelformat[i][1];
            break;
        }
    }
    qDebug()<< keyword;

    QTextDocument *document = ui->textedit2 ->document();


    bool found = false;

    // undo previous change (if any)
    document->undo();


    if(keyword.isEmpty()){
        QMessageBox::information(this, tr("Empty Search Feild"), tr("The search field is empty. "));
        ui->nextbutton2->setEnabled(false);
    }


    else{
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;

        // colorFormat.setForeground(Qt::red);
        //colorFormat.setBackground(Qt::black);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(keyword, highlightCursor,
                                             QTextDocument::FindWholeWords);
             ui->textedit2->setTextCursor(highlightCursor);
             break;

        }

        cursor.endEditBlock();





    }



}

void Widget::on_radioButton2_2_clicked()
{
    QString keyword;
    for(int i=0;i<=33;i++){
        if(excelformat[i][0] == "COMMON HEADER"){
            keyword = excelformat[i][1];
            break;
        }
    }
    qDebug()<< keyword;

    QTextDocument *document = ui->textedit2 ->document();


    bool found = false;

    // undo previous change (if any)
    document->undo();


    if(keyword.isEmpty()){
        QMessageBox::information(this, tr("Empty Search Feild"), tr("The search field is empty. "));
        ui->nextbutton2->setEnabled(false);
    }


    else{
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;

        // colorFormat.setForeground(Qt::red);
        //colorFormat.setBackground(Qt::black);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(keyword, highlightCursor,
                                             QTextDocument::FindWholeWords);
             ui->textedit2->setTextCursor(highlightCursor);
             break;

        }

        cursor.endEditBlock();





    }


}


void Widget::on_radioButton2_3_clicked()
{
    QString keyword;
    for(int i=0;i<=33;i++){
        if(excelformat[i][0] == "COMMON BODY"){
            keyword = excelformat[i][1];
            break;
        }
    }
  //  qDebug()<< keyword;

    QTextDocument *document = ui->textedit2 ->document();


    bool found = false;

    // undo previous change (if any)
    document->undo();


    if(keyword.isEmpty()){
        QMessageBox::information(this, tr("Empty Search Feild"), tr("The search field is empty. "));
        ui->nextbutton2->setEnabled(false);
    }


    else{
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;

        // colorFormat.setForeground(Qt::red);
        //colorFormat.setBackground(Qt::black);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(keyword, highlightCursor,
                                             QTextDocument::FindWholeWords);
             ui->textedit2->setTextCursor(highlightCursor);
             break;

        }

        cursor.endEditBlock();





    }


}

void Widget::on_radioButton2_4_clicked()
{
    QString keyword;
    for(int i=0;i<=33;i++){
        if(excelformat[i][0] == "BLOCK1 HEADER"){
            keyword = excelformat[i][1];
            break;
        }
    }
    //qDebug()<< keyword;

    QTextDocument *document = ui->textedit2 ->document();


    bool found = false;

    // undo previous change (if any)
    document->undo();


    if(keyword.isEmpty()){
        QMessageBox::information(this, tr("Empty Search Feild"), tr("The search field is empty. "));
        ui->nextbutton2->setEnabled(false);
    }


    else{
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;

        // colorFormat.setForeground(Qt::red);
        //colorFormat.setBackground(Qt::black);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(keyword, highlightCursor,
                                             QTextDocument::FindWholeWords);
             ui->textedit2->setTextCursor(highlightCursor);
             break;

        }

        cursor.endEditBlock();

        QByteArray a;


    }
}

void Widget::on_radioButton2_5_clicked()
{
    QString keyword;
    for(int i=0;i<=33;i++){
        if(excelformat[i][0] == "BLOCK1 BODY"){
            keyword = excelformat[i][1];
            break;
        }
    }
   // qDebug()<< keyword;

    QTextDocument *document = ui->textedit2 ->document();


    bool found = false;

    // undo previous change (if any)
    document->undo();


    if(keyword.isEmpty()){
        QMessageBox::information(this, tr("Empty Search Feild"), tr("The search field is empty. "));
        ui->nextbutton2->setEnabled(false);
    }


    else{
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;

        // colorFormat.setForeground(Qt::red);
        //colorFormat.setBackground(Qt::black);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(keyword, highlightCursor,
                                             QTextDocument::FindWholeWords);
             ui->textedit2->setTextCursor(highlightCursor);
             break;

        }

        cursor.endEditBlock();


    }
}


void Widget::on_clear_clicked()
{
    ui->radioButton1_1->setChecked(false);

    ui->radioButton1_2->setChecked(false);

    ui->radioButton1_3->setChecked(false);

    ui->radioButton1_4->setChecked(false);

    ui->radioButton1_5->setChecked(false);

    ui->nextbutton1->setEnabled(false);

    ui->keyword1->setText("");


    ui->textedit->setTextColor(Qt::black);

    ui->textedit->setTextBackgroundColor(Qt::white);

    ui->textedit->setText(string_arr);

    //ui->textedit->setCursor(0);

   // ui->filename->setText(get_filename());


}



void Widget::on_clear2_clicked()
{
    ui->radioButton2_1->setChecked(false);

    ui->radioButton2_2->setChecked(false);

    ui->radioButton2_3->setChecked(false);

    ui->radioButton2_4->setChecked(false);

    ui->radioButton2_5->setChecked(false);

    ui->nextbutton2->setEnabled(false);

    ui->keyword2->setText("");


    ui->textedit2->setTextColor(Qt::black);

    ui->textedit2->setTextBackgroundColor(Qt::white);

    ui->textedit2->setText(right_total());

    //ui->textedit->setCursor(0);

    //ui->filename->setText(get_filename());

}
