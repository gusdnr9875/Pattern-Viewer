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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1305, 735);
        textedit = new QTextEdit(Widget);
        textedit->setObjectName(QStringLiteral("textedit"));
        textedit->setGeometry(QRect(20, 70, 501, 451));
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
        label_1->setGeometry(QRect(20, 550, 61, 31));
        label_1->setBaseSize(QSize(3, 4));
        label_1->setFont(font);
        keyword1 = new QLineEdit(Widget);
        keyword1->setObjectName(QStringLiteral("keyword1"));
        keyword1->setEnabled(true);
        keyword1->setGeometry(QRect(90, 550, 321, 28));
        search_button1 = new QPushButton(Widget);
        search_button1->setObjectName(QStringLiteral("search_button1"));
        search_button1->setGeometry(QRect(430, 550, 84, 28));
        nextbutton1 = new QPushButton(Widget);
        nextbutton1->setObjectName(QStringLiteral("nextbutton1"));
        nextbutton1->setEnabled(false);
        nextbutton1->setGeometry(QRect(430, 590, 84, 28));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "  Pattern Viewer Program", Q_NULLPTR));
        label_1->setText(QApplication::translate("Widget", "Keyword:", Q_NULLPTR));
        search_button1->setText(QApplication::translate("Widget", "Find", Q_NULLPTR));
        nextbutton1->setText(QApplication::translate("Widget", "Next", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
