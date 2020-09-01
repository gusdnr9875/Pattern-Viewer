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
    ui->tablewidget->setColumnCount(5);
    ui->tablewidget->setColumnWidth(4,1000);




    for(int i=0;i<fileheadercnt;i++){
        for(int j=0;j<3;j++){
            QTableWidgetItem* item = ui->tablewidget->item(i,j);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget->setItem(i,j,item);
            }

             item->setText(excelformat[i+1][j]);

        }

        //size(byte)
        QTableWidgetItem* item = ui->tablewidget->item(i,3);
        if(!item){
            item = new QTableWidgetItem();
            ui->tablewidget->setItem(i,3,item);
        }

            item->setText(excelformat[i+1][4]);

        //contents
        if(i==0){
            QTableWidgetItem* item = ui->tablewidget->item(i,4);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget->setItem(i,4,item);
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


            QTableWidgetItem* item = ui->tablewidget->item(i,4);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget->setItem(i,4,item);
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
    ui->tablewidget2->setColumnCount(5);
    ui->tablewidget2->setColumnWidth(4,1000);

    int current_pos=0;
    for(int i=0;i<33;i++){
        started = ended;
        ended += excelformat[i][4].toInt();

        if(excelformat[i][0] == "COMMON HEADER"){

        for(int j=0;j<3;j++){
            QTableWidgetItem* item = ui->tablewidget2->item(current_pos,j);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget2->setItem(current_pos,j,item);
            }

             item->setText(excelformat[i][j]);

        }

        //size(byte)
        QTableWidgetItem* item = ui->tablewidget2->item(current_pos,3);
        if(!item){
            item = new QTableWidgetItem();
            ui->tablewidget2->setItem(current_pos,3,item);
        }

            item->setText(excelformat[i][4]);

        //contents
        if(i==0){
            QTableWidgetItem* item = ui->tablewidget2->item(current_pos,4);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget2->setItem(current_pos,4,item);
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


            QTableWidgetItem* item = ui->tablewidget2->item(current_pos,4);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget2->setItem(current_pos++,4,item);
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
            qDebug()<<common_s;
            qDebug()<<temp;
            bool ok;

            common_s = temp.toHex().toInt(&ok,16);
           //qDebug()<<common_s;
        }


    }
    fileheadercnt = common_r*2 + common_s*2;
    commonbody_r = common_r, commonbody_s = common_s;
    //qDebug()<<fileheadercnt;
    ui->tablewidget3->setRowCount(fileheadercnt);
    ui->tablewidget3->setColumnCount(5);
    ui->tablewidget3->setColumnWidth(4,1000);

    int current_pos=0;
    fileheadercnt =0;
    started=0,ended=0;
    for(int i=0;i<33;i++){

            started = ended;
            ended += excelformat[i][4].toInt();


        if(excelformat[i][0] == "COMMON BODY"){
        for(int j=0;j<3;j++){
            QTableWidgetItem* item = ui->tablewidget3->item(current_pos,j);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget3->setItem(current_pos,j,item);
            }

             item->setText(excelformat[i][j]);

        }

        //size(byte)
        QTableWidgetItem* item = ui->tablewidget3->item(current_pos,3);
        if(!item){
            item = new QTableWidgetItem();
            ui->tablewidget3->setItem(current_pos,3,item);
        }

            item->setText(excelformat[i][4]);

        //contents
        if(i==0){
            QTableWidgetItem* item = ui->tablewidget3->item(current_pos,4);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget3->setItem(current_pos,4,item);
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


            QTableWidgetItem* item = ui->tablewidget3->item(current_pos,4);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget3->setItem(current_pos++,4,item);
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
    ui->tablewidget4->setColumnCount(5);
    ui->tablewidget4->setColumnWidth(4,1000);

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

        for(int j=0;j<3;j++){
            QTableWidgetItem* item = ui->tablewidget4->item(current_pos,j);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget4->setItem(current_pos,j,item);
            }

             item->setText(excelformat[i][j]);

        }

        //size(byte)
        QTableWidgetItem* item = ui->tablewidget4->item(current_pos,3);
        if(!item){
            item = new QTableWidgetItem();
            ui->tablewidget4->setItem(current_pos,3,item);
        }

            item->setText(excelformat[i][4]);

        //contents
        if(i==0){
            QTableWidgetItem* item = ui->tablewidget4->item(current_pos,4);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget4->setItem(current_pos,4,item);
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


            QTableWidgetItem* item = ui->tablewidget4->item(current_pos,4);
            if(!item){
                item = new QTableWidgetItem();
                ui->tablewidget4->setItem(current_pos++,4,item);
            }

                item->setText(afterdata);
                //qDebug()<<afterdata;

        }


        }


    }

    ui->tablewidget4->horizontalHeader()->sortIndicatorOrder();




}
