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

    ui->tablewidget->setRowCount(fileheadercnt);
    ui->tablewidget->setColumnCount(5);
    ui->tablewidget->setColumnWidth(4,1400);


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
                qDebug()<<afterdata;

        }





    }

    ui->tablewidget->horizontalHeader()->sortIndicatorOrder();

}
