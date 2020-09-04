#include "widget.h"
#include "ui_widget.h"
#include "file.h"
#include "format.h"
void Widget::division_FileHeader(){
    QByteArray filedata = get_file_arr(); //  get file data
    int fileheadercnt =0;
    int started=0;
    int ended=0;

    for(int i=0;i<33;i++){
        if(excelformat[i][0] == "File Header")
            fileheadercnt++;
    }

    fileheadercnt++;
    ui->tablewidget->setRowCount(fileheadercnt);
    ui->tablewidget->setColumnCount(4);
    ui->tablewidget->setColumnWidth(3,1000);

    ui->tablewidget->setColumnWidth(0,150);



    for(int i=0;i<fileheadercnt;i++){
        for(int j=1;j<3;j++){
            QTableWidgetItem* item = ui->tablewidget->item(i,j - 1);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget->setItem(i,j - 1,item);
            }

            item->setText(excelformat[i+1][j]);

        }

        //size(byte)
        QTableWidgetItem* item = ui->tablewidget->item(i,2);
        if(!item){
            item = new QTableWidgetItem();
            ui->tablewidget->setItem(i,2,item);
        }

        item->setText(excelformat[i+1][4]);

        //contents
        if(i==0){
            QTableWidgetItem* item = ui->tablewidget->item(i,3);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget->setItem(i,3,item);
            }

            item->setText("content");

        }
        else{
            if(i==1)
                ended = excelformat[i + 1][4].toInt();
            else{
                started = ended;
                ended += excelformat[i + 1][4].toInt();
            }

            //excelformat[i+1][4]
            QString afterdata;
            if(excelformat[i + 1][2]=="unsigned int" || excelformat[i + 1][2]=="int"){
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
            else if(excelformat[i + 1][2]=="char"){
                for(int j=started;j<ended;j++)
                    afterdata.append(filedata.at(j));
            }


            QTableWidgetItem* item = ui->tablewidget->item(i,3);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget->setItem(i,3,item);
            }

            item->setText(afterdata);
            //qDebug()<<afterdata;

        }





    }

    ui->tablewidget->horizontalHeader()->sortIndicatorOrder();

}



void Widget::division_CommonHeader(){
    QByteArray filedata = get_file_arr(); //  get file data
    int fileheadercnt =0;
    int started=0;
    int ended=0;


    for(int i=0;i<33;i++){
        if(excelformat[i][0] == "COMMON HEADER")
            fileheadercnt++;
    }
    //qDebug()<<fileheadercnt;
    ui->tablewidget2->setRowCount(fileheadercnt);
    ui->tablewidget2->setColumnCount(4);
    ui->tablewidget2->setColumnWidth(3,1000);
    ui->tablewidget2->setColumnWidth(0,350);


    int current_pos=0;
    for(int i=0;i<33;i++){
        started = ended;
        ended += excelformat[i][4].toInt();

        if(excelformat[i][0] == "COMMON HEADER"){

            for(int j=1;j<3;j++){
                QTableWidgetItem* item = ui->tablewidget2->item(current_pos,j - 1);
                if(!item){
                    item = new QTableWidgetItem();
                    ui->tablewidget2->setItem(current_pos,j - 1,item);
                }

                item->setText(excelformat[i][j]);

            }

            //size(byte)
            QTableWidgetItem* item = ui->tablewidget2->item(current_pos,2);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget2->setItem(current_pos,2,item);
            }

            item->setText(excelformat[i][4]);

            //contents
            if(i==0){
                QTableWidgetItem* item = ui->tablewidget2->item(current_pos,3);
                if(!item){
                    item = new QTableWidgetItem();
                    ui->tablewidget2->setItem(current_pos,3,item);
                }

                item->setText("content");

            }
            else{/* error */


                //excelformat[i+1][4]
                QString afterdata;
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


                QTableWidgetItem* item = ui->tablewidget2->item(current_pos,3);
                if(!item){
                    item = new QTableWidgetItem();
                    ui->tablewidget2->setItem(current_pos++,3,item);
                }

                item->setText(afterdata);
                //qDebug()<<afterdata;

            }


        }




    }

    ui->tablewidget2->horizontalHeader()->sortIndicatorOrder();

}





void Widget::division_CommonBody(){
    QByteArray filedata = get_file_arr(); //  get file data
    int fileheadercnt =0;
    int started=0;
    int ended=0;
    int common_r, common_s;

    for(int i=0;i<33;i++){


        started = ended;
        ended += excelformat[i][4].toInt();

        if(excelformat[i][0] == "COMMON HEADER" && excelformat[i][1] == "The count of Opcode and Data Set (Data : 32bit) : r"){
            QByteArray temp;

            temp.append(filedata.at(started));

            bool ok;

            common_r = temp.toHex().toInt(&ok,16);
            //qDebug()<<common_r;
        }
        else if(excelformat[i][0] == "COMMON HEADER" && excelformat[i][1] == "The count of Opcode and Data Set (Data : 64bit) : s" ){
            QByteArray temp;

            temp.append(filedata.at(started));
            // qDebug()<<common_s;
            // qDebug()<<temp;
            bool ok;

            common_s = temp.toHex().toInt(&ok,16);
            //qDebug()<<common_s;
        }


    }
    fileheadercnt = common_r*2 + common_s*2;
    commonbody_r = common_r, commonbody_s = common_s;
    //qDebug()<<fileheadercnt;
    ui->tablewidget3->setRowCount(fileheadercnt);
    ui->tablewidget3->setColumnCount(4);
    ui->tablewidget3->setColumnWidth(3,1000);
    ui->tablewidget3->setColumnWidth(0,180);


    int current_pos=0;
    fileheadercnt =0;
    started=0,ended=0;
    for(int i=0;i<33;i++){

        started = ended;
        ended += excelformat[i][4].toInt();


        if(excelformat[i][0] == "COMMON BODY"){
            for(int j=1;j<3;j++){
                QTableWidgetItem* item = ui->tablewidget3->item(current_pos,j - 1);
                if(!item){
                    item = new QTableWidgetItem();
                    ui->tablewidget3->setItem(current_pos,j - 1,item);
                }

                item->setText(excelformat[i][j]);

            }

            //size(byte)
            QTableWidgetItem* item = ui->tablewidget3->item(current_pos,2);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget3->setItem(current_pos,2,item);
            }

            item->setText(excelformat[i][4]);

            //contents
            if(i==0){
                QTableWidgetItem* item = ui->tablewidget3->item(current_pos,3);
                if(!item){
                    item = new QTableWidgetItem();
                    ui->tablewidget3->setItem(current_pos,3,item);
                }

                item->setText("content");

            }
            else{



                QString afterdata;
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


                QTableWidgetItem* item = ui->tablewidget3->item(current_pos,3);
                if(!item){
                    item = new QTableWidgetItem();
                    ui->tablewidget3->setItem(current_pos++,3,item);
                }

                item->setText(afterdata);
                //qDebug()<<afterdata;

            }


        }


        ui->tablewidget3->horizontalHeader()->sortIndicatorOrder();


        if(excelformat[i][0]=="COMMON BODY"&&excelformat[i][1]=="Register(32bit) DATA"&& (common_r - 1) > 0){
            common_r--;
            i-=2;


        }
        else if(excelformat[i][0]=="COMMON BODY"&&excelformat[i][1]=="Register(64bit) DATA"&& (common_s - 1) > 0){
            common_s--;
            i-=2;
        }


    }




}




void Widget::division_blockHeader(){


    QByteArray filedata = get_file_arr(); //  get file data
    int fileheadercnt =0;
    int started=0;
    int ended=0;


    for(int i=0;i<33;i++){
        if(excelformat[i][0] == "BLOCK1 HEADER"){
            fileheadercnt++;
        }
    }
    //qDebug()<<fileheadercnt;
    ui->tablewidget4->setRowCount(fileheadercnt);
    ui->tablewidget4->setColumnCount(4);
    ui->tablewidget4->setColumnWidth(3,1000);
    ui->tablewidget4->setColumnWidth(0,350);

    int current_pos=0;
    int common_r = commonbody_r;
    int common_s = commonbody_s;
    for(int i=0;i<33;i++){
        started = ended;
        ended += excelformat[i][4].toInt();

        if(excelformat[i][0]=="COMMON BODY"&&excelformat[i][1]=="Register(32bit) DATA" && (common_r - 1) > 0){
            common_r--;
            i-=2;
        }
        else if(excelformat[i][0]=="COMMON BODY"&&excelformat[i][1]=="Register(64bit) DATA" && (common_s - 1) > 0){
            common_s--;
            i-=2;
        }

        if(excelformat[i][0] == "BLOCK1 HEADER"){



            if(excelformat[i][1] == "Reserved" ){
               blockheader_startingarr = ended;
             //  qDebug()<<ended;
            }
            else if(excelformat[i][1] == "The count of Opcode and Data Set (Data : 32bit) : r" ){

                QByteArray temp;

                temp.append(filedata.at(started));

                bool ok;

                blockbody_r =  temp.toHex().toInt(&ok,16);

               // qDebug()<<blockbody_r;
            }
            else if(excelformat[i][1] == "The count of Opcode and Data Set (Data : 64bit) : s" ){


                QByteArray temp;

                temp.append(filedata.at(started));

                bool ok;

                blockbody_s =  temp.toHex().toInt(&ok,16);

               // qDebug()<<blockbody_s;

             }

            for(int j=1;j<3;j++){
                QTableWidgetItem* item = ui->tablewidget4->item(current_pos,j - 1);
                if(!item){
                    item = new QTableWidgetItem();
                    ui->tablewidget4->setItem(current_pos,j - 1,item);
                }

                item->setText(excelformat[i][j]);

            }

            //size(byte)
            QTableWidgetItem* item = ui->tablewidget4->item(current_pos,2);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget4->setItem(current_pos,2,item);
            }

            item->setText(excelformat[i][4]);

            //contents
            if(i==0){
                QTableWidgetItem* item = ui->tablewidget4->item(current_pos,3);
                if(!item){
                    item = new QTableWidgetItem();
                    ui->tablewidget4->setItem(current_pos,3,item);
                }

                item->setText("content");

            }
            else{


                //excelformat[i+1][4]
                QString afterdata;
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


                QTableWidgetItem* item = ui->tablewidget4->item(current_pos,3);
                if(!item){
                    item = new QTableWidgetItem();
                    ui->tablewidget4->setItem(current_pos++,3,item);
                }

                item->setText(afterdata);
                //qDebug()<<afterdata;

            }


        }


    }

    ui->tablewidget4->horizontalHeader()->sortIndicatorOrder();



}


void Widget::division_blockBody(){

    QByteArray filedata = get_file_arr(); //  get file data
    int fileheadercnt =0;
    int started=0;
    int ended=0;

    for(int i=0;i<33;i++){

        if(excelformat[i][0] == "BLOCK1 BODY")
            fileheadercnt++;

    }

    fileheadercnt++;
    ui->tablewidget5->setRowCount(fileheadercnt+ blockbody_r*2 + blockbody_s*2 + blockbody_p - 5);
   // qDebug()<<fileheadercnt+ blockbody_r + blockbody_s - 2;
    ui->tablewidget5->setColumnCount(4);
    ui->tablewidget5->setColumnWidth(3,1000);
    ui->tablewidget5->setColumnWidth(0,180);


    int br = blockbody_r;
    int bs = blockbody_s;
    int bp = blockbody_p;

    int current_pos =0;
    started=blockheader_startingarr;
    ended= blockheader_startingarr;
    for(int i=0;i<=33;i++){

        if(excelformat[i][0] == "BLOCK1 BODY"){


            if(current_pos == 0){
                ended += excelformat[i][4].toInt();
            }
            else{
                started = ended;
                ended += excelformat[i][4].toInt();
            }





            for(int j=1;j<3;j++){

                QTableWidgetItem* item = ui->tablewidget5->item(current_pos,j - 1);
                if(!item){
                    item = new QTableWidgetItem();
                    ui->tablewidget5->setItem(current_pos,j - 1,item);
                }

                item->setText(excelformat[i][j]);

            }

            //size(byte)
            QTableWidgetItem* item = ui->tablewidget5->item(current_pos,2);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget5->setItem(current_pos,2,item);
            }

            item->setText(excelformat[i][4]);




            // add data

            QString afterdata;
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


            item = ui->tablewidget5->item(current_pos,3);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget5->setItem(current_pos++,3,item);
            }

            item->setText(afterdata);


            if(excelformat[i][0]=="BLOCK1 BODY"&&excelformat[i][1]=="Register(32bit) DATA" && (br - 1) > 0){
                br--;
                i-=2;
            }
            else if(excelformat[i][0]=="BLOCK1 BODY"&&excelformat[i][1]=="Register(64bit) DATA" && (bs - 1) > 0){
                bs--;
                i-=2;
            }
            else if(excelformat[i][0]=="BLOCK1 BODY"&&excelformat[i][1]=="Micro Pattern"&& (bp -1)  > 0){
                bp--;
                i-=1;
            }


        }





    }


}




