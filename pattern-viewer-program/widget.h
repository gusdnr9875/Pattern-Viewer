#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    QByteArray blob;
    ~Widget();

private:
    Ui::Widget *ui;

    //파일 오픈 테스트 함수
    void test_fileopen();

};

#endif // WIDGET_H
