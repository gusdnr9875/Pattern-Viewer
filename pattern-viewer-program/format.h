#ifndef FORMAT_H
#define FORMAT_H
#include "widget.h"
#include <QWidget>
#include <QVector>

class format : public QWidget
{
    Q_OBJECT
public:
    explicit format(QWidget *parent = 0);

    QByteArray get_file_arr(){return originalfile;} //get originalfile data
    void set_file_arr(QByteArray arr){originalfile = arr;} //set originalfile data


    void startformat(); //start format data


    //Format Header size: 688 Byte               //  Type | size  | size(Byte)
    QString read_FileHeaderDiscernmentCode(); //   u       1       4
    QByteArray read_FileHeaderSourceFileName();  //   c       36      36
    QByteArray read_FileHeaderCompileDate();     //   c       8       8


signals:

public slots:

private:
    QByteArray originalfile;
    QByteArray addformat;

    //start point, end point
    int started=0, ended =4;



};

#endif // FORMAT_H
