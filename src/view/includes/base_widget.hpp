// Copyright 2024 zekkoaem & stranger

#ifndef _A1_MAZE_CPP_VIEW_BASE_WIDGET_HPP_
#define _A1_MAZE_CPP_VIEW_BASE_WIDGET_HPP_

#include <QApplication>
#include <QDebug>
#include <QFileDialog>
#include <QFontDatabase>
#include <QMouseEvent>
#include <QMovie>
#include <QPainter>
#include <QTimer>
#include <QWheelEvent>
#include <QWidget>

#include "./../../controller/controller.hpp"

namespace s21::constants {

inline constexpr qreal scale_coeff{1.1};
inline constexpr qreal camera_speed{15.0};

}  // namespace s21::constants

namespace s21 {

class BaseWidget : public QWidget {
  Q_OBJECT

 public:
  explicit BaseWidget(QWidget* parent = nullptr);
  ~BaseWidget() override;

 protected:
  void wheelEvent(QWheelEvent* event) override;
  void keyPressEvent(QKeyEvent* event) override;

  QPointF mousePrevPos{0, 0};

  QPointF camera_{0, 0};
  qreal scale_{1.0};

  QTimer* timer_;

  Controller controller_;

 protected slots:
  virtual void dragHeightSlider() = 0;
  virtual void dragWidthSlider() = 0;

  virtual void clickedSettingsButton() = 0;
  virtual void clickedBackButton() = 0;

  virtual void clickedSaveButton() = 0;
  virtual void clickedLoadButton() = 0;
  virtual void clickedCreateButton() = 0;

  void clickedMenuButton();

 signals:
  void backToMenu();
};

}  // namespace s21

#endif  // _A1_MAZE_CPP_VIEW_BASE_WIDGET_HPP_
