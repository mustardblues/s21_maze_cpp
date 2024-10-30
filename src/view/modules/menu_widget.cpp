// Copyright 2024 zekkoaem & stranger

#include "./../includes/menu_widget.hpp"

#include "./../uis/ui_menu_widget.h"

namespace s21 {

MenuWidget::MenuWidget(QWidget* parent)
    : QWidget(parent), ui_(new Ui::MenuWidget) {
  ui_->setupUi(this);

  this->connect(ui_->cave_button, SIGNAL(clicked()), this,
                SLOT(clickedCaveButton()));
  this->connect(ui_->maze_button, SIGNAL(clicked()), this,
                SLOT(clickedMazeButton()));
  this->connect(ui_->exit_button, SIGNAL(clicked()), this,
                SLOT(clickedExitButton()));

  gif = new QMovie(":/images/alice.gif");
  ui_->gif_label->setMovie(gif);
  gif->start();
}

MenuWidget::~MenuWidget() {
  delete gif;

  delete ui_;
}

void MenuWidget::resizeEvent(QResizeEvent* event) {
  Q_UNUSED(event);

  ui_->stackedWidget->resize(QSize{this->width(), this->height()});

  ui_->gif_label->move(QPoint{this->width() / 2 - ui_->gif_label->x() / 2, 50});

  ui_->name_label->move(
      QPoint{this->width() / 2 - ui_->name_label->x() / 2, 330});
  ui_->cave_button->move(
      QPoint{this->width() / 2 - ui_->cave_button->x() / 2, 470});
  ui_->maze_button->move(
      QPoint{this->width() / 2 - ui_->maze_button->x() / 2, 495});
  ui_->exit_button->move(
      QPoint{this->width() / 2 - ui_->exit_button->x() / 2, 545});
}

void MenuWidget::clickedCaveButton() {
  BaseWidget* widget = new CaveWidget;

  ui_->stackedWidget->addWidget(widget);

  this->connect(widget, SIGNAL(backToMenu()), this, SLOT(setMenuWidget()));

  ui_->stackedWidget->setCurrentIndex(1);
}

void MenuWidget::clickedMazeButton() {
  BaseWidget* widget = new MazeWidget;

  ui_->stackedWidget->addWidget(widget);

  this->connect(widget, SIGNAL(backToMenu()), this, SLOT(setMenuWidget()));

  ui_->stackedWidget->setCurrentIndex(1);
}

void MenuWidget::clickedExitButton() { this->close(); }

void MenuWidget::setMenuWidget() {
  auto pointer = ui_->stackedWidget->currentWidget();

  ui_->stackedWidget->removeWidget(pointer);
  delete pointer;

  ui_->stackedWidget->setCurrentIndex(0);
}

}  // namespace s21
