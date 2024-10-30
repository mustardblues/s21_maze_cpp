// Copyright 2024 zekkoaem & stranger

#ifndef _A1_MAZE_CPP_VIEW_CAVE_WIDGET_HPP_
#define _A1_MAZE_CPP_VIEW_CAVE_WIDGET_HPP_

#include "base_widget.hpp"

namespace Ui {

class CaveWidget;

}  // namespace Ui

namespace s21 {

class CaveWidget final : public BaseWidget {
  Q_OBJECT

 public:
  explicit CaveWidget(QWidget* parent = nullptr);
  ~CaveWidget() override;

 private:
  void paintEvent(QPaintEvent* event) override;

  bool load_flag_;

  Data<DataType::Cave> data_;
  CreateSettings settings_;

  Ui::CaveWidget* ui_;

 private slots:
  void resizeEvent(QResizeEvent* event) override;

  void dragHeightSlider() override;
  void dragWidthSlider() override;

  void dragGenerations();
  void dragLiveChance();
  void dragBirthLimit();
  void dragDeathLimit();
  void dragFrequency();

  void clickedSettingsButton() override;
  void clickedBackButton() override;

  void clickedSaveButton() override;
  void clickedLoadButton() override;
  void clickedCreateButton() override;

  void clickedClearButton();
  void cellularAutomatonDemo();
};

}  // namespace s21

#endif  // _A1_MAZE_CPP_VIEW_CAVE_WIDGET_HPP_
