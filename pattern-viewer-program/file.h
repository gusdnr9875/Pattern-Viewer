#ifndef FILE_H
#define FILE_H

#include "widget.h"

class file : public QWidget
{
    Q_OBJECT
public:
    explicit file(QWidget *parent = 0);

    ~file();
    void file_read();
signals:

public slots:
};

#endif // FILE_H
