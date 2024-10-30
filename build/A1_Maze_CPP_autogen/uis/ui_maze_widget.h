/********************************************************************************
** Form generated from reading UI file 'maze_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAZE_WIDGET_H
#define UI_MAZE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MazeWidget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *main_page;
    QPushButton *settings_button;
    QPushButton *menu_button;
    QPushButton *create_button;
    QPushButton *load_button;
    QPushButton *save_button;
    QPushButton *find_path_button;
    QLabel *width_value_label;
    QSlider *width_slider;
    QLabel *height_value_label;
    QSlider *height_slider;
    QLabel *step_label;
    QWidget *settings_page;
    QComboBox *solve_algorithm_box;
    QLabel *solve_algorithm_label;
    QPushButton *back_button;
    QLabel *create_algorithm_label;
    QComboBox *create_algorithm_box;

    void setupUi(QWidget *MazeWidget)
    {
        if (MazeWidget->objectName().isEmpty())
            MazeWidget->setObjectName(QString::fromUtf8("MazeWidget"));
        MazeWidget->resize(1280, 720);
        stackedWidget = new QStackedWidget(MazeWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(1060, 0, 220, 720));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 5);"));
        main_page = new QWidget();
        main_page->setObjectName(QString::fromUtf8("main_page"));
        settings_button = new QPushButton(main_page);
        settings_button->setObjectName(QString::fromUtf8("settings_button"));
        settings_button->setGeometry(QRect(150, 58, 15, 15));
        settings_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: solid;\n"
"\n"
"	background-color: rgba(0,  0, 0, 0);\n"
"\n"
"	image: url(:/images/gear.png);\n"
"}"));
        menu_button = new QPushButton(main_page);
        menu_button->setObjectName(QString::fromUtf8("menu_button"));
        menu_button->setGeometry(QRect(10, 230, 200, 20));
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
        create_button = new QPushButton(main_page);
        create_button->setObjectName(QString::fromUtf8("create_button"));
        create_button->setGeometry(QRect(10, 180, 200, 20));
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
        find_path_button = new QPushButton(main_page);
        find_path_button->setObjectName(QString::fromUtf8("find_path_button"));
        find_path_button->setGeometry(QRect(10, 205, 200, 20));
        find_path_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        width_value_label = new QLabel(main_page);
        width_value_label->setObjectName(QString::fromUtf8("width_value_label"));
        width_value_label->setGeometry(QRect(10, 80, 200, 20));
        width_value_label->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
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
        width_slider->setMaximum(100);
        width_slider->setOrientation(Qt::Horizontal);
        height_value_label = new QLabel(main_page);
        height_value_label->setObjectName(QString::fromUtf8("height_value_label"));
        height_value_label->setGeometry(QRect(10, 130, 200, 20));
        height_value_label->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
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
        height_slider->setMaximum(100);
        height_slider->setOrientation(Qt::Horizontal);
        step_label = new QLabel(main_page);
        step_label->setObjectName(QString::fromUtf8("step_label"));
        step_label->setGeometry(QRect(10, 690, 200, 20));
        step_label->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(255,  0, 0, 255);\n"
"\n"
"color: white;\n"
"text-align: left;"));
        stackedWidget->addWidget(main_page);
        settings_page = new QWidget();
        settings_page->setObjectName(QString::fromUtf8("settings_page"));
        solve_algorithm_box = new QComboBox(settings_page);
        solve_algorithm_box->addItem(QString());
        solve_algorithm_box->addItem(QString());
        solve_algorithm_box->addItem(QString());
        solve_algorithm_box->setObjectName(QString::fromUtf8("solve_algorithm_box"));
        solve_algorithm_box->setGeometry(QRect(10, 130, 200, 20));
        solve_algorithm_box->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(27,  27, 27, 255);\n"
"\n"
"color: white;\n"
"text-align: left;"));
        solve_algorithm_label = new QLabel(settings_page);
        solve_algorithm_label->setObjectName(QString::fromUtf8("solve_algorithm_label"));
        solve_algorithm_label->setGeometry(QRect(10, 105, 200, 20));
        solve_algorithm_label->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(0,  0, 0, 0);\n"
"\n"
"color: black;\n"
"text-align: left;"));
        back_button = new QPushButton(settings_page);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setGeometry(QRect(10, 155, 200, 20));
        back_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        create_algorithm_label = new QLabel(settings_page);
        create_algorithm_label->setObjectName(QString::fromUtf8("create_algorithm_label"));
        create_algorithm_label->setGeometry(QRect(10, 55, 200, 20));
        create_algorithm_label->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(0,  0, 0, 0);\n"
"\n"
"color: black;\n"
"text-align: left;"));
        create_algorithm_box = new QComboBox(settings_page);
        create_algorithm_box->addItem(QString());
        create_algorithm_box->setObjectName(QString::fromUtf8("create_algorithm_box"));
        create_algorithm_box->setGeometry(QRect(10, 80, 200, 20));
        create_algorithm_box->setStyleSheet(QString::fromUtf8("font: 14px \"PIXY\";\n"
"\n"
"border: solid;\n"
"\n"
"background-color: rgba(27,  27, 27, 255);\n"
"\n"
"color: white;\n"
"text-align: left;"));
        stackedWidget->addWidget(settings_page);

        retranslateUi(MazeWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MazeWidget);
    } // setupUi

    void retranslateUi(QWidget *MazeWidget)
    {
        MazeWidget->setWindowTitle(QCoreApplication::translate("MazeWidget", "Form", nullptr));
        settings_button->setText(QString());
        menu_button->setText(QCoreApplication::translate("MazeWidget", " Menu", nullptr));
        create_button->setText(QCoreApplication::translate("MazeWidget", " Create", nullptr));
        load_button->setText(QString());
        save_button->setText(QString());
        find_path_button->setText(QCoreApplication::translate("MazeWidget", " Find path", nullptr));
        width_value_label->setText(QCoreApplication::translate("MazeWidget", "Width: 0", nullptr));
        height_value_label->setText(QCoreApplication::translate("MazeWidget", "Height: 0", nullptr));
        step_label->setText(QCoreApplication::translate("MazeWidget", " Waiting...", nullptr));
        solve_algorithm_box->setItemText(0, QCoreApplication::translate("MazeWidget", "DFS", nullptr));
        solve_algorithm_box->setItemText(1, QCoreApplication::translate("MazeWidget", "BFS", nullptr));
        solve_algorithm_box->setItemText(2, QCoreApplication::translate("MazeWidget", "Q_learning", nullptr));

        solve_algorithm_label->setText(QCoreApplication::translate("MazeWidget", " Find path algorithm", nullptr));
        back_button->setText(QCoreApplication::translate("MazeWidget", " Back", nullptr));
        create_algorithm_label->setText(QCoreApplication::translate("MazeWidget", " Create algorithm", nullptr));
        create_algorithm_box->setItemText(0, QCoreApplication::translate("MazeWidget", "Eller", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MazeWidget: public Ui_MazeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAZE_WIDGET_H
