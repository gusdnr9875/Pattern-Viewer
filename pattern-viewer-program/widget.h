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
#include <string>
#include <cstring>
#include <QTextDocument>
#include <QMessageBox>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QTableWidgetItem>

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;




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
    static QString get_filename(); //get filename
    static void set_filename(QString name); // set filename

    QString get_search_keyword(){return search_keyword;} //get search_keyword
    void set_search_keyword(QString val){search_keyword=val;} // set search_keyword
    QString get_search_keyword_right(){return search_keyword_right;} //get search_keyword
    void set_search_keyword_right(QString val){search_keyword_right=val;} // set search_keyword

    int get_cursor_position(){return cursor_position;}
    void set_cursor_position(int val){cursor_position = val;}
    int get_cursor_position_right(){return cursor_position_right;}
    void set_cursor_position_right(int val){cursor_position_right = val;}
    int get_cursor_total(){return cursor_total;}
    void set_cursor_total(int val){cursor_total=val;}
    int get_cursor_total_right(){return cursor_total_right;}
    void set_cursor_total_right(int val){cursor_total_right=val;}
    ~Widget();

private slots:
    void on_search_button1_clicked();

    void on_nextbutton1_clicked();

    void on_close_clicked();

    void on_fileSelect_clicked();

    void on_search_button2_clicked();

    void on_nextbutton2_clicked();

private:
    Ui::Widget *ui;
    static QByteArray file_arr; //file data
    static QString filename; //file name

    //searching variables
    QString search_keyword;  // search keyword
    QString search_keyword_right;
    int cursor_position = 0; //current cursor
    int cursor_position_right =0;
    int cursor_total =0; //total cursor count
    int cursor_total_right =0;

    void file_read(); // file open and read
    void file_search(); // all keyword search
    void file_search_cursor();  //cursor find
    void file_search_right(); //right view
    void file_search_cursor_right();//right view


    void excel_read(); // excel read and store excelformat!

    QString right_total();

    QString excelformat[100][10];


    //format division view
    void division_FileHeader();
    void division_CommonHeader();
    void division_CommonBody();


};

#endif // WIDGET_H
