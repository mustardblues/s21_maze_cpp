// Copyright 2024 zekkoaem & stranger

#ifndef _A1_MAZE_CPP_VIEW_MENU_HPP_
#define _A1_MAZE_CPP_VIEW_MENU_HPP_

#include "cave_widget.hpp"
#include "maze_widget.hpp"

namespace Ui {

class MenuWidget;

}  // namespace Ui

namespace s21 {

class MenuWidget final : public QWidget {
  Q_OBJECT

 public:
  explicit MenuWidget(QWidget* parent = nullptr);
  ~MenuWidget() override;

 private:
  Ui::MenuWidget* ui_;

  QMovie* gif;

 private slots:
  void resizeEvent(QResizeEvent* event) override;

  void clickedCaveButton();
  void clickedMazeButton();
  void clickedExitButton();

  void setMenuWidget();
};

}  // namespace s21

#endif  // _A1_MAZE_CPP_VIEW_MENU_HPP_
