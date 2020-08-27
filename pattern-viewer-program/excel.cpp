#include "widget.h"

#define ROW 1;
#define COL 2;

 //QString excelformat[100][10]; //divisiton (4,2)~

void Widget::excel_read(){
    Document xlsxR("/home/hyunwook/pattern-viwer/Pattern-Viewer/configuration.xlsx");
    if (xlsxR.load()) // load excel file
        {
            qDebug() << "load open";

            //division

            for(int i=4;i<70;i++){
            int row = i; int col = 4;
            Cell* cell = xlsxR.cellAt(row, col); // get cell pointer.
            if ( cell != NULL )
            {
                QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
                qDebug() << var; // display value. it is 'Hello Qt!'.
                excelformat[i][0] = var.toString();
                qDebug()<<excelformat[i][0];
            }


           col =8;
           cell = xlsxR.cellAt(row, col); // get cell pointer.
           if ( cell != NULL )
           {
               QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
               qDebug() << var; // display value. it is 'Hello Qt!'.
               excelformat[i][1] = var.toString();
               qDebug()<<excelformat[i][1];
           }

           col = 10;

           cell = xlsxR.cellAt(row, col); // get cell pointer.
           if ( cell != NULL )
           {
               QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
               qDebug() << var; // display value. it is 'Hello Qt!'.
               excelformat[i][2] = var.toString();
               qDebug()<<excelformat[i][2];
           }





            }
        }




}
