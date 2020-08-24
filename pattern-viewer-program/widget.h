#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QString>
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QByteArray>
#include <QApplication>
#include <stdio.h>
#include <QTextDocument>
#include <QMessageBox>
#include <QTextCursor>
#include <QTextCharFormat>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    static QByteArray get_file_arr(); //get file data
    static void set_file_arr(QByteArray arr); // set file data

    QString get_search_keyword(){return search_keyword;} //get search_keyword
    void set_search_keyword(QString val){search_keyword=val;} // set search_keyword
    int get_cursor_position(){return cursor_position;}
    void set_cursor_position(int val){cursor_position = val;}
    int get_cursor_total(){return cursor_total;}
    void set_cursor_total(int val){cursor_total=val;}
    ~Widget();

private slots:
    void on_search_button1_clicked();

    void on_nextbutton1_clicked();

private:
    Ui::Widget *ui;
    static QByteArray file_arr; //file data
    //searching variables
    QString search_keyword;  // search keyword
    int cursor_position = 0; //current cursor
    int cursor_total =0; //total cursor count

    void file_read(); // file open and read
    void file_search(); // all keyword search
    void file_search_cursor();  //cursor find


};

#endif // WIDGET_H
