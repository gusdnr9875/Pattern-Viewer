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
    QString read_FileHeaderDiscernmentCode();    //   u       1       4
    QByteArray read_FileHeaderSourceFileName();  //   c       36      36
    QByteArray read_FileHeaderCompileDate();     //   c       8       8
    QByteArray read_FileHeaderCompileTime();     //   c       8       8
    QByteArray read_FileHeaderCompilerVersion(); //   c       8       8
    QString read_FileHeaderTheflagofCommon();    //   u       1       4
    QString read_FileHeaderThecountofBlock();    //   u       1       4
    QString read_FileHeaderTheOffsetsofCommon(); //   u       1       4

    QString read_FileHeaderTheOffsetsofBlocks();  //   u       64      256
    QString read_FileHeaderTheStartAddressArray();//   u       64      256
    QString read_FileHeaderRemark();              //   c       80      80
    QString read_FileHeaderTheDataofIL();         //   u       1       4
    QString read_FileHeaderReserved();            //   i       4       16



signals:

public slots:

private:
    QByteArray originalfile;
    QByteArray addformat;

    //start point, end point
    int started=0, ended =4;



};

#endif // FORMAT_H
