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


    ~Widget();

private:
    Ui::Widget *ui;
    static QByteArray file_arr; //file data
    void file_read();


};

#endif // WIDGET_H
