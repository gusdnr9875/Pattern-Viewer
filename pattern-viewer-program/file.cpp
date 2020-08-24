#include "file.h"

file::file(QWidget *parent) : QWidget(parent)
{

}

file::~file() {}



void file::file_read(){

    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("select file"),"","PAT (*.pat)"); //선택한 파일 경로 반환
    qDebug()<<"filename:"<<fileName;


    QString ApplicationPath = QApplication::applicationDirPath();
    QFile File(fileName);


    //파일 읽기 테스트
    if(!File.open(QIODevice::ReadOnly)) // 읽기 전용, 텍스트로 파일 열기
    {
         if(!File.exists()) // 파일이 존재하지 않으면...
        {
             qDebug()<<"file is not exist";// 파일이 존재하지 않으면...여기에 동작 적용
        }
        else
        {
            qDebug()<<"file is not open";// 파일을 열수 없거나 파일 손상 등 여러 요인작용...
        }
    }
    QDataStream OpenFile(&File);
   // QString ConfigText;
    QByteArray blob = File.readAll();

    Widget::set_file_arr(blob);

    File.close(); // 파일닫기
    //qDebug() << blob.toHex();

    /*
    while(!OpenFile.atEnd())  // 파일 끝까지 읽어서
    {
         ConfigText=OpenFile.readLine(); // 한라인씩 읽어서 변수에 적용


         qDebug()<< ConfigText;
    }
    File.close(); // 파일닫기
    */


}
