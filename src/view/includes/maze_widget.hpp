// Copyright 2024 zekkoaem & stranger

#ifndef _A1_MAZE_CPP_VIEW_MAZE_WIDGET_HPP_
#define _A1_MAZE_CPP_VIEW_MAZE_WIDGET_HPP_

#include "base_widget.hpp"

namespace Ui {

class MazeWidget;

}  // namespace Ui

namespace s21 {

class machineLearningDemo final {
 private:
};

class MazeWidget final : public BaseWidget {
  Q_OBJECT

 public:
  explicit MazeWidget(QWidget* parent = nullptr);
  ~MazeWidget() override;

 private:
  void paintEvent(QPaintEvent* event) override;

  void mousePressEvent(QMouseEvent* event) override;

  bool paint_path_;
  bool paint_from_;
  bool paint_to_;

  Point from_;
  Point to_;

  Data<DataType::Maze> data_;

  std::deque<Point> path_;

  Ui::MazeWidget* ui_;

 private slots:
  void resizeEvent(QResizeEvent* event) override;

  void dragHeightSlider() override;
  void dragWidthSlider() override;

  void clickedSettingsButton() override;
  void clickedBackButton() override;

  void clickedSaveButton() override;
  void clickedLoadButton() override;
  void clickedCreateButton() override;

  void clickedFindPathButton();
};

}  // namespace s21

#endif  // _A1_MAZE_CPP_VIEW_MAZE_WIDGET_HPP_
