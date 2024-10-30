/********************************************************************************
** Form generated from reading UI file 'cave_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAVE_WIDGET_H
#define UI_CAVE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CaveWidget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *main_page;
    QPushButton *clear_button;
    QPushButton *create_button;
    QPushButton *load_button;
    QPushButton *save_button;
    QLabel *width_label;
    QSlider *width_slider;
    QLabel *height_label;
    QSlider *height_slider;
    QLabel *generations_label;
    QSlider *generations_slider;
    QLabel *live_chance_label;
    QSlider *live_chance_slider;
    QLabel *birth_limit_label;
    QSlider *birth_limit_slider;
    QLabel *death_limit_label;
    QSlider *death_limit_slider;
    QLabel *frequency_label;
    QSlider *frequency_slider;
    QPushButton *menu_button;
    QLabel *current_gen_label;

    void setupUi(QWidget *CaveWidget)
    {
        if (CaveWidget->objectName().isEmpty())
            CaveWidget->setObjectName(QString::fromUtf8("CaveWidget"));
        CaveWidget->resize(1280, 720);
        stackedWidget = new QStackedWidget(CaveWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(1060, 0, 220, 720));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 5);"));
        main_page = new QWidget();
        main_page->setObjectName(QString::fromUtf8("main_page"));
        clear_button = new QPushButton(main_page);
        clear_button->setObjectName(QString::fromUtf8("clear_button"));
        clear_button->setGeometry(QRect(10, 455, 200, 20));
        clear_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: solid;\n"
"\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"	color: white;\n"
"	text-align: left;\n"
"\n"
"	font: 14px \"PIXY\";\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	color: black;\n"
"    background-color:  rgba(200, 200, 200, 100);\n"
"}"));
        create_button = new QPushButton(main_page);
        create_button->setObjectName(QString::fromUtf8("create_button"));
        create_button->setGeometry(QRect(10, 430, 200, 20));
        create_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: solid;\n"
"\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"	color: white;\n"
"	text-align: left;\n"
"\n"
"	font: 14px \"PIXY\";\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	color: black;\n"
"    background-color:  rgba(200, 200, 200, 100);\n"
"}"));
        load_button = new QPushButton(main_page);
        load_button->setObjectName(QString::fromUtf8("load_button"));
        load_button->setGeometry(QRect(190, 58, 15, 15));
        load_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: solid;\n"
"\n"
"	background-color: rgba(0,  0, 0, 0);\n"
"\n"
"	image: url(:/images/load.png);\n"
"}"));
        save_button = new QPushButton(main_page);
        save_button->setObjectName(QString::fromUtf8("save_button"));
        save_button->setGeometry(QRect(170, 58, 15, 15));
        save_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: solid;\n"
"\n"
"	background-color: rgba(0,  0, 0, 0);\n"
"\n"
"	image: url(:/images/save.png);\n"
"}"));
        width_label = new QLabel(main_page);
        width_label->setObjectName(QString::fromUtf8("width_label"));
        width_label->setGeometry(QRect(10, 80, 200, 20));
        width_label->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(0,  0, 0, 0);\n"
"\n"
"color: black;\n"
"text-align: left;"));
        width_slider = new QSlider(main_page);
        width_slider->setObjectName(QString::fromUtf8("width_slider"));
        width_slider->setGeometry(QRect(10, 105, 200, 20));
        width_slider->setStyleSheet(QString::fromUtf8("QSlider::groove::horizontal{\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::handle::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::add-page::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgb(180, 180, 180);\n"
"\n"
"}"));
        width_slider->setMaximum(500);
        width_slider->setOrientation(Qt::Horizontal);
        height_label = new QLabel(main_page);
        height_label->setObjectName(QString::fromUtf8("height_label"));
        height_label->setGeometry(QRect(10, 130, 200, 20));
        height_label->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(0,  0, 0, 0);\n"
"\n"
"color: black;\n"
"text-align: left;"));
        height_slider = new QSlider(main_page);
        height_slider->setObjectName(QString::fromUtf8("height_slider"));
        height_slider->setGeometry(QRect(10, 155, 200, 20));
        height_slider->setStyleSheet(QString::fromUtf8("QSlider::groove::horizontal{\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::handle::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::add-page::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgb(180, 180, 180);\n"
"\n"
"}"));
        height_slider->setMaximum(500);
        height_slider->setOrientation(Qt::Horizontal);
        generations_label = new QLabel(main_page);
        generations_label->setObjectName(QString::fromUtf8("generations_label"));
        generations_label->setGeometry(QRect(10, 180, 200, 20));
        generations_label->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(0,  0, 0, 0);\n"
"\n"
"color: black;\n"
"text-align: left;"));
        generations_slider = new QSlider(main_page);
        generations_slider->setObjectName(QString::fromUtf8("generations_slider"));
        generations_slider->setGeometry(QRect(10, 205, 200, 20));
        generations_slider->setStyleSheet(QString::fromUtf8("QSlider::groove::horizontal{\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::handle::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::add-page::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgb(180, 180, 180);\n"
"\n"
"}"));
        generations_slider->setMaximum(100);
        generations_slider->setOrientation(Qt::Horizontal);
        live_chance_label = new QLabel(main_page);
        live_chance_label->setObjectName(QString::fromUtf8("live_chance_label"));
        live_chance_label->setGeometry(QRect(10, 230, 200, 20));
        live_chance_label->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(0,  0, 0, 0);\n"
"\n"
"color: black;\n"
"text-align: left;"));
        live_chance_slider = new QSlider(main_page);
        live_chance_slider->setObjectName(QString::fromUtf8("live_chance_slider"));
        live_chance_slider->setGeometry(QRect(10, 255, 200, 20));
        live_chance_slider->setStyleSheet(QString::fromUtf8("QSlider::groove::horizontal{\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::handle::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::add-page::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgb(180, 180, 180);\n"
"\n"
"}"));
        live_chance_slider->setMaximum(100);
        live_chance_slider->setOrientation(Qt::Horizontal);
        birth_limit_label = new QLabel(main_page);
        birth_limit_label->setObjectName(QString::fromUtf8("birth_limit_label"));
        birth_limit_label->setGeometry(QRect(10, 280, 200, 20));
        birth_limit_label->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(0,  0, 0, 0);\n"
"\n"
"color: black;\n"
"text-align: left;"));
        birth_limit_slider = new QSlider(main_page);
        birth_limit_slider->setObjectName(QString::fromUtf8("birth_limit_slider"));
        birth_limit_slider->setGeometry(QRect(10, 305, 200, 20));
        birth_limit_slider->setStyleSheet(QString::fromUtf8("QSlider::groove::horizontal{\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::handle::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::add-page::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgb(180, 180, 180);\n"
"\n"
"}"));
        birth_limit_slider->setMaximum(7);
        birth_limit_slider->setOrientation(Qt::Horizontal);
        death_limit_label = new QLabel(main_page);
        death_limit_label->setObjectName(QString::fromUtf8("death_limit_label"));
        death_limit_label->setGeometry(QRect(10, 330, 200, 20));
        death_limit_label->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(0,  0, 0, 0);\n"
"\n"
"color: black;\n"
"text-align: left;"));
        death_limit_slider = new QSlider(main_page);
        death_limit_slider->setObjectName(QString::fromUtf8("death_limit_slider"));
        death_limit_slider->setGeometry(QRect(10, 355, 200, 20));
        death_limit_slider->setStyleSheet(QString::fromUtf8("QSlider::groove::horizontal{\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::handle::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::add-page::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgb(180, 180, 180);\n"
"\n"
"}"));
        death_limit_slider->setMaximum(7);
        death_limit_slider->setOrientation(Qt::Horizontal);
        frequency_label = new QLabel(main_page);
        frequency_label->setObjectName(QString::fromUtf8("frequency_label"));
        frequency_label->setGeometry(QRect(10, 380, 200, 20));
        frequency_label->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(0,  0, 0, 0);\n"
"\n"
"color: black;\n"
"text-align: left;"));
        frequency_slider = new QSlider(main_page);
        frequency_slider->setObjectName(QString::fromUtf8("frequency_slider"));
        frequency_slider->setGeometry(QRect(10, 405, 200, 20));
        frequency_slider->setStyleSheet(QString::fromUtf8("QSlider::groove::horizontal{\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::handle::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"}\n"
"\n"
"QSlider::add-page::horizontal{\n"
"	height: 30px;\n"
"	width: 10px;\n"
"\n"
"	background-color: rgb(180, 180, 180);\n"
"\n"
"}"));
        frequency_slider->setMaximum(10000);
        frequency_slider->setOrientation(Qt::Horizontal);
        menu_button = new QPushButton(main_page);
        menu_button->setObjectName(QString::fromUtf8("menu_button"));
        menu_button->setGeometry(QRect(10, 480, 200, 20));
        menu_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: solid;\n"
"\n"
"	background-color: rgba(27,  27, 27, 255);\n"
"\n"
"	color: white;\n"
"	text-align: left;\n"
"\n"
"	font: 14px \"PIXY\";\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	color: black;\n"
"    background-color:  rgba(200, 200, 200, 100);\n"
"}"));
        current_gen_label = new QLabel(main_page);
        current_gen_label->setObjectName(QString::fromUtf8("current_gen_label"));
        current_gen_label->setGeometry(QRect(10, 690, 200, 20));
        current_gen_label->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(255,  0, 0, 255);\n"
"\n"
"color: white;\n"
"text-align: left;"));
        stackedWidget->addWidget(main_page);

        retranslateUi(CaveWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CaveWidget);
    } // setupUi

    void retranslateUi(QWidget *CaveWidget)
    {
        CaveWidget->setWindowTitle(QCoreApplication::translate("CaveWidget", "Form", nullptr));
        clear_button->setText(QCoreApplication::translate("CaveWidget", " Clear", nullptr));
        create_button->setText(QCoreApplication::translate("CaveWidget", " Create", nullptr));
        load_button->setText(QString());
        save_button->setText(QString());
        width_label->setText(QCoreApplication::translate("CaveWidget", "Width: 0", nullptr));
        height_label->setText(QCoreApplication::translate("CaveWidget", "Height: 0", nullptr));
        generations_label->setText(QCoreApplication::translate("CaveWidget", "Generations: 0", nullptr));
        live_chance_label->setText(QCoreApplication::translate("CaveWidget", "Live chance: 0%", nullptr));
        birth_limit_label->setText(QCoreApplication::translate("CaveWidget", "Birth limit: 0", nullptr));
        death_limit_label->setText(QCoreApplication::translate("CaveWidget", "Death limit: 0", nullptr));
        frequency_label->setText(QCoreApplication::translate("CaveWidget", "Frequency: 0ms", nullptr));
        menu_button->setText(QCoreApplication::translate("CaveWidget", " Menu", nullptr));
        current_gen_label->setText(QCoreApplication::translate("CaveWidget", " Current gen: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CaveWidget: public Ui_CaveWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAVE_WIDGET_H
