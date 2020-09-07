/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *textedit;
    QLabel *label;
    QLabel *label_1;
    QLineEdit *keyword1;
    QPushButton *search_button1;
    QPushButton *nextbutton1;
    QLabel *label_2;
    QLineEdit *keyword2;
    QPushButton *search_button2;
    QPushButton *nextbutton2;
    QLabel *label_3;
    QPushButton *fileSelect;
    QLabel *filename;
    QPushButton *close;
    QTabWidget *tabwidget;
    QWidget *tab;
    QTextEdit *textedit2;
    QWidget *tab_2;
    QTableWidget *tablewidget;
    QWidget *tab_3;
    QTableWidget *tablewidget2;
    QWidget *tab_4;
    QTableWidget *tablewidget3;
    QWidget *tab_5;
    QTableWidget *tablewidget4;
    QWidget *tab_6;
    QTableWidget *tablewidget5;
    QWidget *tab_7;
    QGroupBox *groupBox;
    QRadioButton *radioButton1_1;
    QRadioButton *radioButton1_2;
    QRadioButton *radioButton1_3;
    QRadioButton *radioButton1_4;
    QRadioButton *radioButton1_5;
    QGroupBox *groupBox2;
    QRadioButton *radioButton2_1;
    QRadioButton *radioButton2_2;
    QRadioButton *radioButton2_3;
    QRadioButton *radioButton2_4;
    QRadioButton *radioButton2_5;
    QPushButton *clear;
    QPushButton *clear2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1502, 879);
        textedit = new QTextEdit(Widget);
        textedit->setObjectName(QStringLiteral("textedit"));
        textedit->setGeometry(QRect(20, 70, 651, 671));
        textedit->setUndoRedoEnabled(true);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 231, 41));
        label->setBaseSize(QSize(3, 4));
        QFont font;
        font.setFamily(QStringLiteral("Carlito"));
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label_1 = new QLabel(Widget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(30, 750, 61, 31));
        label_1->setBaseSize(QSize(3, 4));
        label_1->setFont(font);
        keyword1 = new QLineEdit(Widget);
        keyword1->setObjectName(QStringLiteral("keyword1"));
        keyword1->setEnabled(true);
        keyword1->setGeometry(QRect(100, 750, 321, 28));
        search_button1 = new QPushButton(Widget);
        search_button1->setObjectName(QStringLiteral("search_button1"));
        search_button1->setGeometry(QRect(470, 750, 84, 28));
        nextbutton1 = new QPushButton(Widget);
        nextbutton1->setObjectName(QStringLiteral("nextbutton1"));
        nextbutton1->setEnabled(false);
        nextbutton1->setGeometry(QRect(470, 790, 84, 28));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(710, 750, 61, 31));
        label_2->setBaseSize(QSize(3, 4));
        label_2->setFont(font);
        keyword2 = new QLineEdit(Widget);
        keyword2->setObjectName(QStringLiteral("keyword2"));
        keyword2->setEnabled(true);
        keyword2->setGeometry(QRect(780, 750, 321, 28));
        search_button2 = new QPushButton(Widget);
        search_button2->setObjectName(QStringLiteral("search_button2"));
        search_button2->setGeometry(QRect(1140, 750, 84, 28));
        nextbutton2 = new QPushButton(Widget);
        nextbutton2->setObjectName(QStringLiteral("nextbutton2"));
        nextbutton2->setEnabled(false);
        nextbutton2->setGeometry(QRect(1140, 790, 84, 28));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1270, 860, 231, 20));
        fileSelect = new QPushButton(Widget);
        fileSelect->setObjectName(QStringLiteral("fileSelect"));
        fileSelect->setGeometry(QRect(1330, 770, 151, 28));
        filename = new QLabel(Widget);
        filename->setObjectName(QStringLiteral("filename"));
        filename->setGeometry(QRect(0, 860, 1031, 20));
        close = new QPushButton(Widget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(1330, 810, 151, 28));
        tabwidget = new QTabWidget(Widget);
        tabwidget->setObjectName(QStringLiteral("tabwidget"));
        tabwidget->setGeometry(QRect(700, 10, 771, 731));
        tabwidget->setTabPosition(QTabWidget::North);
        tabwidget->setTabShape(QTabWidget::Rounded);
        tabwidget->setTabsClosable(false);
        tabwidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        textedit2 = new QTextEdit(tab);
        textedit2->setObjectName(QStringLiteral("textedit2"));
        textedit2->setGeometry(QRect(10, 10, 751, 681));
        textedit2->setUndoRedoEnabled(true);
        tabwidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tablewidget = new QTableWidget(tab_2);
        tablewidget->setObjectName(QStringLiteral("tablewidget"));
        tablewidget->setGeometry(QRect(10, 10, 751, 681));
        tablewidget->setSortingEnabled(true);
        tabwidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tablewidget2 = new QTableWidget(tab_3);
        tablewidget2->setObjectName(QStringLiteral("tablewidget2"));
        tablewidget2->setGeometry(QRect(10, 10, 751, 681));
        tabwidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tablewidget3 = new QTableWidget(tab_4);
        tablewidget3->setObjectName(QStringLiteral("tablewidget3"));
        tablewidget3->setGeometry(QRect(10, 10, 751, 681));
        tablewidget3->setMouseTracking(false);
        tablewidget3->setFocusPolicy(Qt::StrongFocus);
        tabwidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tablewidget4 = new QTableWidget(tab_5);
        tablewidget4->setObjectName(QStringLiteral("tablewidget4"));
        tablewidget4->setGeometry(QRect(10, 10, 751, 681));
        tabwidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tablewidget5 = new QTableWidget(tab_6);
        tablewidget5->setObjectName(QStringLiteral("tablewidget5"));
        tablewidget5->setGeometry(QRect(10, 10, 751, 681));
        tabwidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tabwidget->addTab(tab_7, QString());
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 760, 401, 81));
        radioButton1_1 = new QRadioButton(groupBox);
        radioButton1_1->setObjectName(QStringLiteral("radioButton1_1"));
        radioButton1_1->setGeometry(QRect(10, 30, 121, 26));
        radioButton1_2 = new QRadioButton(groupBox);
        radioButton1_2->setObjectName(QStringLiteral("radioButton1_2"));
        radioButton1_2->setGeometry(QRect(140, 30, 131, 26));
        radioButton1_3 = new QRadioButton(groupBox);
        radioButton1_3->setObjectName(QStringLiteral("radioButton1_3"));
        radioButton1_3->setGeometry(QRect(10, 50, 121, 26));
        radioButton1_4 = new QRadioButton(groupBox);
        radioButton1_4->setObjectName(QStringLiteral("radioButton1_4"));
        radioButton1_4->setGeometry(QRect(140, 50, 121, 26));
        radioButton1_5 = new QRadioButton(groupBox);
        radioButton1_5->setObjectName(QStringLiteral("radioButton1_5"));
        radioButton1_5->setGeometry(QRect(280, 50, 106, 26));
        groupBox2 = new QGroupBox(Widget);
        groupBox2->setObjectName(QStringLiteral("groupBox2"));
        groupBox2->setGeometry(QRect(700, 760, 401, 81));
        radioButton2_1 = new QRadioButton(groupBox2);
        radioButton2_1->setObjectName(QStringLiteral("radioButton2_1"));
        radioButton2_1->setGeometry(QRect(10, 30, 121, 26));
        radioButton2_2 = new QRadioButton(groupBox2);
        radioButton2_2->setObjectName(QStringLiteral("radioButton2_2"));
        radioButton2_2->setGeometry(QRect(140, 30, 131, 26));
        radioButton2_3 = new QRadioButton(groupBox2);
        radioButton2_3->setObjectName(QStringLiteral("radioButton2_3"));
        radioButton2_3->setGeometry(QRect(10, 50, 121, 26));
        radioButton2_4 = new QRadioButton(groupBox2);
        radioButton2_4->setObjectName(QStringLiteral("radioButton2_4"));
        radioButton2_4->setGeometry(QRect(140, 50, 121, 26));
        radioButton2_5 = new QRadioButton(groupBox2);
        radioButton2_5->setObjectName(QStringLiteral("radioButton2_5"));
        radioButton2_5->setGeometry(QRect(280, 50, 106, 26));
        clear = new QPushButton(Widget);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(470, 830, 84, 28));
        clear2 = new QPushButton(Widget);
        clear2->setObjectName(QStringLiteral("clear2"));
        clear2->setGeometry(QRect(1140, 830, 84, 28));
        textedit->raise();
        label->raise();
        label_1->raise();
        search_button1->raise();
        nextbutton1->raise();
        label_2->raise();
        search_button2->raise();
        nextbutton2->raise();
        label_3->raise();
        fileSelect->raise();
        filename->raise();
        close->raise();
        tabwidget->raise();
        groupBox2->raise();
        clear->raise();
        clear2->raise();
        groupBox->raise();
        keyword1->raise();
        keyword2->raise();

        retranslateUi(Widget);

        tabwidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "  Pattern Viewer Program", Q_NULLPTR));
        label_1->setText(QApplication::translate("Widget", "Keyword:", Q_NULLPTR));
        search_button1->setText(QApplication::translate("Widget", "Find", Q_NULLPTR));
        nextbutton1->setText(QApplication::translate("Widget", "Next", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "Keyword:", Q_NULLPTR));
        search_button2->setText(QApplication::translate("Widget", "Find", Q_NULLPTR));
        nextbutton2->setText(QApplication::translate("Widget", "Next", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "Copyright \302\251UNITEST Corporation", Q_NULLPTR));
        fileSelect->setText(QApplication::translate("Widget", "File Select", Q_NULLPTR));
        filename->setText(QApplication::translate("Widget", "dfdsadasdasdasdasd", Q_NULLPTR));
        close->setText(QApplication::translate("Widget", "Close", Q_NULLPTR));
        tabwidget->setTabText(tabwidget->indexOf(tab), QApplication::translate("Widget", "TOTAL", Q_NULLPTR));
        tabwidget->setTabText(tabwidget->indexOf(tab_2), QApplication::translate("Widget", "FILE HEADER", Q_NULLPTR));
        tabwidget->setTabText(tabwidget->indexOf(tab_3), QApplication::translate("Widget", "COMMON HEADER", Q_NULLPTR));
        tabwidget->setTabText(tabwidget->indexOf(tab_4), QApplication::translate("Widget", "COMMON BODY", Q_NULLPTR));
        tabwidget->setTabText(tabwidget->indexOf(tab_5), QApplication::translate("Widget", "BLOCK1 HEADER", Q_NULLPTR));
        tabwidget->setTabText(tabwidget->indexOf(tab_6), QApplication::translate("Widget", "BLOCK1 BODY", Q_NULLPTR));
        tabwidget->setTabText(tabwidget->indexOf(tab_7), QApplication::translate("Widget", "Micro Pattern", Q_NULLPTR));
        groupBox->setTitle(QString());
        radioButton1_1->setText(QApplication::translate("Widget", "File Header", Q_NULLPTR));
        radioButton1_2->setText(QApplication::translate("Widget", "Common Header", Q_NULLPTR));
        radioButton1_3->setText(QApplication::translate("Widget", "Common Body", Q_NULLPTR));
        radioButton1_4->setText(QApplication::translate("Widget", "Block Header", Q_NULLPTR));
        radioButton1_5->setText(QApplication::translate("Widget", "Block Body", Q_NULLPTR));
        groupBox2->setTitle(QString());
        radioButton2_1->setText(QApplication::translate("Widget", "File Header", Q_NULLPTR));
        radioButton2_2->setText(QApplication::translate("Widget", "Common Header", Q_NULLPTR));
        radioButton2_3->setText(QApplication::translate("Widget", "Common Body", Q_NULLPTR));
        radioButton2_4->setText(QApplication::translate("Widget", "Block Header", Q_NULLPTR));
        radioButton2_5->setText(QApplication::translate("Widget", "Block Body", Q_NULLPTR));
        clear->setText(QApplication::translate("Widget", "Clear", Q_NULLPTR));
        clear2->setText(QApplication::translate("Widget", "Clear", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
