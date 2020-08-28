#include "widget.h"

#define ROW 1;
#define COL 2;

 //QString excelformat[100][10]; //divisiton (4,2)~

void Widget::excel_read(){
    Document xlsxR("/home/hyunwook/pattern-viwer/Pattern-Viewer/configuration.xlsx");
    if (xlsxR.load()) // load excel file
        {      
            //Division Item Type Size Size(Byte) (2,0) ~ (32,4)


            for(int i=1;i<=32;i++){
                // Division
                int row = i; int col = 1;
                Cell* cell = xlsxR.cellAt(row, col); // get cell pointer.
                if ( cell != NULL )
                {
                    QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
                    //qDebug() << var; // display value. it is 'Hello Qt!'.
                    excelformat[i][col - 1] = var.toString();
                   // qDebug()<<excelformat[i][0];
                }

                // Item
                col = 2;
                cell = xlsxR.cellAt(row, col); // get cell pointer.
                if ( cell != NULL )
                {
                    QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
                   // qDebug() << var; // display value. it is 'Hello Qt!'.
                    excelformat[i][col - 1] = var.toString();
                   // qDebug()<<excelformat[i][1];
                }



                // Type
                col = 3;
                cell = xlsxR.cellAt(row, col); // get cell pointer.
                if ( cell != NULL )
                {
                    QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
                   // qDebug() << var; // display value. it is 'Hello Qt!'.
                    excelformat[i][col - 1] = var.toString();
                   // qDebug()<<excelformat[i][1];
                }


                // Size
                col = 4;
                cell = xlsxR.cellAt(row, col); // get cell pointer.
                if ( cell != NULL )
                {
                    QVariant var = cell->readValue(); // 1read cell value (number(double), QDateTime, QString ...)
                    //qDebug() << var; // display value. it is 'Hello Qt!'.
                    excelformat[i][col - 1] = var.toString();
                   // qDebug()<<excelformat[i][1];
                }


                // Size(Byte)
                col = 5;
                cell = xlsxR.cellAt(row, col); // get cell pointer.
                if ( cell != NULL )
                {
                    QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
                    //qDebug() << var; // display value. it is 'Hello Qt!'.
                    excelformat[i][col - 1] = var.toString();
                   // qDebug()<<excelformat[i][1];
                }


           }
     }

    /*
    for(int i=1;i<=32;i++){
        for(int j=0;j< 5;j++){
             qDebug()<<excelformat[i][j];
        }
    }
*/

}

QString Widget::right_total(){

   QByteArray filedata = get_file_arr(); //  get file data
   int started=0;
   int ended=0;
   QString afterdata;

   int common_r,common_s,block_r,block_s;

    for(int i=2;i<=32;i++){

        if(i==2)
            ended = excelformat[i][4].toInt();
        else{
            started = ended;
            ended += excelformat[i][4].toInt();
        }
       // qDebug()<< afterdata;

       afterdata.append(excelformat[i][1]);
       afterdata.append("\n");


        if(excelformat[i][2]=="unsigned int" || excelformat[i][2]=="int"){
            int cnt = 0;
            for(int j=started;j<ended;j++){
               if(cnt!=0)
                   afterdata.append(" ");
                if(cnt%32==0 && cnt!=0)
                    afterdata.append("\n");
                cnt++;
                QByteArray temp;
                temp.append(filedata.at(j));
                afterdata.append(temp.toHex());
             }
        }
        else if(excelformat[i][2]=="char"){
            for(int j=started;j<ended;j++)
                afterdata.append(filedata.at(j));
        }
        afterdata.append("\n");






        /*
            1. common header  find
            2. until count loop
            3. block header is same!
        */
        //1.
        if(excelformat[i][0] == "COMMON HEADER" && excelformat[i][1] == "The count of Opcode and Data Set (Data : 32bit) : r"){
           QByteArray temp;

           temp.append(filedata.at(started));

           bool ok;

           common_r = temp.toHex().toInt(&ok,16);
        }
        else if(excelformat[i][0] == "COMMON HEADER" && excelformat[i][1] == "The count of Opcode and Data Set (Data : 64bit) : s" ){
            QByteArray temp;

            temp.append(filedata.at(started));

            bool ok;

            common_s = temp.toHex().toInt(&ok,16);
        }
        else if(excelformat[i][0] == "BLOCK1 HEADER" && excelformat[i][1] == "The count of Opcode and Data Set (Data : 32bit) : r"){
            QByteArray temp;

            temp.append(filedata.at(started));

            bool ok;

            block_r = temp.toHex().toInt(&ok,16);
        }
        else if(excelformat[i][0] == "BLOCK1 HEADER" && excelformat[i][1] == "The count of Opcode and Data Set (Data : 64bit) : s"){
            QByteArray temp;

            temp.append(filedata.at(started));

            bool ok;

            block_s = temp.toHex().toInt(&ok,16);
        }

        //2.
        if(excelformat[i][0]=="COMMON BODY"&&excelformat[i][1]=="Register(32bit) DATA"&& (common_r - 1) > 0){
            common_r--;
            i-=2;
        }
        else if(excelformat[i][0]=="COMMON BODY"&&excelformat[i][1]=="Register(64bit) DATA"&& (common_s - 1) > 0){
            common_s--;
            i-=2;
        }
        else if(excelformat[i][0]=="BLOCK1 BODY"&&excelformat[i][1]=="Register(32bit) DATA"&& (block_r - 1) > 0){
            block_r--;
            i-=2;
        }
        else if(excelformat[i][0]=="BLOCK1 BODY"&&excelformat[i][1]=="Register(32bit) DATA"&& (block_s - 1) > 0){
            block_s--;
            i-=2;
        }

    }
    qDebug()<<common_r;
    qDebug()<<common_s;
    qDebug()<<block_r;
    qDebug()<<block_s;

    //qDebug()<< afterdata;


    return afterdata;

}





