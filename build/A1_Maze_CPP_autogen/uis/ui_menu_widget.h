/********************************************************************************
** Form generated from reading UI file 'menu_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_WIDGET_H
#define UI_MENU_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWidget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *gif_label;
    QLabel *name_label;
    QPushButton *maze_button;
    QPushButton *cave_button;
    QPushButton *exit_button;

    void setupUi(QWidget *MenuWidget)
    {
        if (MenuWidget->objectName().isEmpty())
            MenuWidget->setObjectName(QString::fromUtf8("MenuWidget"));
        MenuWidget->resize(1280, 720);
        MenuWidget->setMinimumSize(QSize(1280, 720));
        MenuWidget->setMaximumSize(QSize(1920, 1080));
        stackedWidget = new QStackedWidget(MenuWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1280, 720));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 5);"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gif_label = new QLabel(page);
        gif_label->setObjectName(QString::fromUtf8("gif_label"));
        gif_label->setGeometry(QRect(430, 100, 420, 278));
        gif_label->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        name_label = new QLabel(page);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setGeometry(QRect(430, 330, 420, 131));
        name_label->setStyleSheet(QString::fromUtf8("font: 28px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(0,  0, 0, 0);\n"
"\n"
"color: black;\n"
"text-align: left;"));
        name_label->setAlignment(Qt::AlignCenter);
        maze_button = new QPushButton(page);
        maze_button->setObjectName(QString::fromUtf8("maze_button"));
        maze_button->setGeometry(QRect(430, 495, 420, 20));
        maze_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: solid;\n"
"\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"	color: white;\n"
"	text-align: center;\n"
"\n"
"	font: 14px \"PIXY\";\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	color: black;\n"
"    background-color:  rgba(200, 200, 200, 100);\n"
"}"));
        cave_button = new QPushButton(page);
        cave_button->setObjectName(QString::fromUtf8("cave_button"));
        cave_button->setGeometry(QRect(430, 470, 420, 20));
        cave_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: solid;\n"
"\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"	color: white;\n"
"	text-align: center;\n"
"\n"
"	font: 14px \"PIXY\";\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	color: black;\n"
"    background-color:  rgba(200, 200, 200, 100);\n"
"}"));
        exit_button = new QPushButton(page);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));
        exit_button->setGeometry(QRect(430, 545, 420, 20));
        exit_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: solid;\n"
"\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"	color: white;\n"
"	text-align: center;\n"
"\n"
"	font: 14px \"PIXY\";\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	color: black;\n"
"    background-color:  rgba(200, 200, 200, 100);\n"
"}"));
        stackedWidget->addWidget(page);

        retranslateUi(MenuWidget);

        QMetaObject::connectSlotsByName(MenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MenuWidget)
    {
        MenuWidget->setWindowTitle(QCoreApplication::translate("MenuWidget", "Form", nullptr));
        gif_label->setText(QString());
        name_label->setText(QCoreApplication::translate("MenuWidget", "A1_MAZE_CPP\n"
"\n"
"Created by\n"
"zekkoaem & stranger", nullptr));
        maze_button->setText(QCoreApplication::translate("MenuWidget", "Maze", nullptr));
        cave_button->setText(QCoreApplication::translate("MenuWidget", "Cave", nullptr));
        exit_button->setText(QCoreApplication::translate("MenuWidget", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWidget: public Ui_MenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_WIDGET_H
