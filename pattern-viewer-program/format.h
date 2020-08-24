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
    void startformat();
signals:

public slots:

private:
    QByteArray originalfile;

   QVector <QString> division[7][4];{{"File Header",'u','1','4'}};
    //Format Header size: 688 Byte



};

#endif // FORMAT_H
