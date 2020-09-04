#include "widget.h"
#include "ui_widget.h"

void Widget::file_search(){


    QString keyword = ui->keyword1->text();
    QTextDocument *document = ui->textedit ->document();

    bool found = false;

    // undo previous change (if any)
    document->undo();

    int cursor_cnt = 0;



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

        colorFormat.setForeground(Qt::red);
        //colorFormat.setBackground(Qt::black);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(keyword, highlightCursor,
                                             QTextDocument::FindWholeWords);
            //qDebug()<<"search";
            cursor_cnt++;
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


        ui->nextbutton1->setEnabled(true);

    }

    set_search_keyword(keyword);
    set_cursor_position(0);
    set_cursor_total(cursor_cnt);

}

void Widget::file_search_cursor(){

    QString keyword = get_search_keyword();

    QTextDocument *document = ui->textedit ->document();

    bool found = false;

    // undo previous change (if any)
    document->undo();


    QTextCursor highlightCursor(document);
    QTextCursor cursor(document);

    cursor.beginEditBlock();

    QTextCharFormat plainFormat(highlightCursor.charFormat());
    QTextCharFormat colorFormat = plainFormat;
    QTextCharFormat backcolorFormat = plainFormat;

    colorFormat.setForeground(Qt::red);

    backcolorFormat.setForeground(Qt::red);
    backcolorFormat.setBackground(Qt::yellow);


    int cnt =0;
    int cursor_point = get_cursor_position();
    if(keyword.size()>0)
        keyword.remove(keyword.size(),1);
    if(cursor_point == (get_cursor_total() - 1))
        cursor_point =0;
    while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
        //qDebug()<<cnt++;

        highlightCursor = document->find(keyword, highlightCursor,
                                         QTextDocument::FindWholeWords);

        if (!highlightCursor.isNull()) {
            found = true;
            highlightCursor.movePosition(QTextCursor::WordRight,
                                         QTextCursor::KeepAnchor);

            if(cnt == cursor_point){
                highlightCursor.mergeCharFormat(backcolorFormat);
               // qDebug()<<cursor_point;
                set_cursor_position(cursor_point + 1);
                highlightCursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, 0);
                ui->textedit->setTextCursor(highlightCursor);

            }

            else
                highlightCursor.mergeCharFormat(colorFormat);

            cnt++;
        }
    }

    cursor.endEditBlock();
    if (found == false) {
        QMessageBox::information(this, tr("Word Not Found"),
                                 tr("Sorry, the word cannot be found."));

    }








}






// right view!

void Widget::file_search_right(){


    QString keyword = ui->keyword2->text();
    QTextDocument *document = ui->textedit2 ->document();

    bool found = false;

    // undo previous change (if any)
    document->undo();

    int cursor_cnt = 0;



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

        colorFormat.setForeground(Qt::red);
        //colorFormat.setBackground(Qt::black);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(keyword, highlightCursor,
                                             QTextDocument::FindWholeWords);
            //qDebug()<<"search";
            cursor_cnt++;
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


        ui->nextbutton2->setEnabled(true);

    }

    set_search_keyword_right(keyword);
    set_cursor_position_right(0);
    set_cursor_total_right(cursor_cnt);

}

void Widget::file_search_cursor_right(){

    QString keyword = get_search_keyword_right();

    QTextDocument *document = ui->textedit2 ->document();

    bool found = false;

    // undo previous change (if any)
    document->undo();


    QTextCursor highlightCursor(document);
    QTextCursor cursor(document);

    cursor.beginEditBlock();

    QTextCharFormat plainFormat(highlightCursor.charFormat());
    QTextCharFormat colorFormat = plainFormat;
    QTextCharFormat backcolorFormat = plainFormat;

    colorFormat.setForeground(Qt::red);

    backcolorFormat.setForeground(Qt::red);
    backcolorFormat.setBackground(Qt::yellow);


    int cnt =0;
    int cursor_point = get_cursor_position_right();
    if(keyword.size()>0)
        keyword.remove(keyword.size(),1);
    if(cursor_point == (get_cursor_total_right() - 1))
        cursor_point =0;
    while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
        //qDebug()<<cnt++;

        highlightCursor = document->find(keyword, highlightCursor,
                                         QTextDocument::FindWholeWords);

        if (!highlightCursor.isNull()) {
            found = true;
            highlightCursor.movePosition(QTextCursor::WordRight,
                                         QTextCursor::KeepAnchor);

            if(cnt == cursor_point){
                highlightCursor.mergeCharFormat(backcolorFormat);
              //  qDebug()<<cursor_point;
                set_cursor_position_right(cursor_point + 1);
                highlightCursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, 0);
                ui->textedit2->setTextCursor(highlightCursor);

            }

            else
                highlightCursor.mergeCharFormat(colorFormat);

            cnt++;
        }
    }

    cursor.endEditBlock();
    if (found == false) {
        QMessageBox::information(this, tr("Word Not Found"),
                                 tr("Sorry, the word cannot be found."));

    }








}

