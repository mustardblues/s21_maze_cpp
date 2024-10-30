// Copyright 2024 zekkoaem & stranger

#include "./../includes/base_widget.hpp"

namespace s21 {

BaseWidget::BaseWidget(QWidget* parent) : QWidget(parent) {
  timer_ = new QTimer;
}

BaseWidget::~BaseWidget() { delete timer_; }

void BaseWidget::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_A:
      camera_.rx() += constants::camera_speed;
      break;
    case Qt::Key_D:
      camera_.rx() -= constants::camera_speed;
      break;
    case Qt::Key_W:
      camera_.ry() += constants::camera_speed;
      break;
    case Qt::Key_S:
      camera_.ry() -= constants::camera_speed;
      break;
    case Qt::Key_Z:
      scale_ = 1.0;
      camera_ = QPointF{0, 0};
      break;
    default:
      break;
  }

  this->repaint();
}

void BaseWidget::wheelEvent(QWheelEvent* event) {
  qreal new_scale = event->angleDelta().y() < 0
                        ? scale_ * constants::scale_coeff
                        : scale_ / constants::scale_coeff;

  camera_ += QPointF(event->position()) * (1.0 / scale_ - 1.0 / new_scale);

  scale_ = new_scale;

  this->repaint();
}

void BaseWidget::clickedMenuButton() { emit backToMenu(); }

}  // namespace s21
