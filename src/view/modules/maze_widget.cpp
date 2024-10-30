// Copyright 2024 zekkoaem & stranger

#include "../includes/maze_widget.hpp"

#include "../uis/ui_maze_widget.h"

namespace s21 {

MazeWidget::MazeWidget(QWidget* parent)
    : BaseWidget(parent), ui_(new Ui::MazeWidget) {
  ui_->setupUi(this);

  ui_->step_label->hide();

  ui_->stackedWidget->setCurrentIndex(0);
  this->connect(ui_->menu_button, SIGNAL(clicked()), this,
                SLOT(clickedMenuButton()));

  this->connect(ui_->settings_button, SIGNAL(clicked()), this,
                SLOT(clickedSettingsButton()));
  this->connect(ui_->back_button, SIGNAL(clicked()), this,
                SLOT(clickedBackButton()));

  this->connect(ui_->load_button, SIGNAL(clicked()), this,
                SLOT(clickedLoadButton()));
  this->connect(ui_->save_button, SIGNAL(clicked()), this,
                SLOT(clickedSaveButton()));
  this->connect(ui_->create_button, SIGNAL(clicked()), this,
                SLOT(clickedCreateButton()));
  this->connect(ui_->find_path_button, SIGNAL(clicked()), this,
                SLOT(clickedFindPathButton()));

  this->connect(ui_->height_slider, SIGNAL(valueChanged(int)), this,
                SLOT(dragHeightSlider()));
  this->connect(ui_->width_slider, SIGNAL(valueChanged(int)), this,
                SLOT(dragWidthSlider()));
}

MazeWidget::~MazeWidget() { delete ui_; }

void MazeWidget::resizeEvent(QResizeEvent* event) {
  Q_UNUSED(event);

  ui_->stackedWidget->move(QPoint{this->width() - 220, 0});
  ui_->stackedWidget->resize(QSize{this->width(), this->height()});
}

void MazeWidget::clickedSettingsButton() {
  ui_->stackedWidget->setCurrentIndex(1);
}

void MazeWidget::clickedBackButton() { ui_->stackedWidget->setCurrentIndex(0); }

void MazeWidget::dragHeightSlider() {
  const int height = ui_->height_slider->value();

  ui_->height_value_label->setText(QString{"Width: "} +
                                   QString::number(height));
}

void MazeWidget::dragWidthSlider() {
  const int width = ui_->width_slider->value();

  ui_->width_value_label->setText(QString{"Width: "} + QString::number(width));
}

void MazeWidget::clickedSaveButton() {
  QString filename = QFileDialog::getSaveFileName(this, "Save file...", "/");

  if (filename.isEmpty()) {
    return;
  }

  controller_.save<DataType::Maze>(filename.toStdString(), data_);
}

void MazeWidget::clickedLoadButton() {
  QString filename = QFileDialog::getOpenFileName(this, "Load file...", "/");

  if (filename.isEmpty()) {
    return;
  }

  data_ = std::move(controller_.load<DataType::Maze>(filename.toStdString()));

  ui_->step_label->hide();

  paint_path_ = false;
  paint_from_ = false;
  paint_to_ = false;

  this->repaint();
}

void MazeWidget::clickedCreateButton() {
  const int height = ui_->height_slider->value();
  const int width = ui_->width_slider->value();

  if (ui_->create_algorithm_box->currentIndex() == 0) {
    data_ =
        std::move(controller_.create<DataType::Maze, CreateAlgorithm::Eller>(
            height, width));
  }

  ui_->step_label->hide();

  paint_path_ = false;
  paint_from_ = false;
  paint_to_ = false;

  this->repaint();
}

void MazeWidget::clickedFindPathButton() {
  if (paint_from_ == false || paint_to_ == false) {
    return;
  }

  ui_->step_label->show();
  ui_->step_label->setText(" Waiting...");

  paint_path_ = false;

  this->repaint();

  if (ui_->solve_algorithm_box->currentIndex() == 0) {
    path_ = std::move(controller_.solve<DataType::Maze, SolveAlgorithm::DFS>(
        from_, to_, data_));

  } else if (ui_->solve_algorithm_box->currentIndex() == 1) {
    path_ = std::move(controller_.solve<DataType::Maze, SolveAlgorithm::BFS>(
        from_, to_, data_));

  } else if (ui_->solve_algorithm_box->currentIndex() == 2) {
    path_ =
        std::move(controller_.solve<DataType::Maze, SolveAlgorithm::Q_learning>(
            from_, to_, data_));
  }

  if (!path_.empty()) {
    paint_path_ = true;

    ui_->step_label->show();
    ui_->step_label->setText(" " + QString{QString::number(path_.size())} +
                             " steps");
  } else {
    ui_->step_label->hide();
  }

  this->repaint();
}

void MazeWidget::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event);

  const unsigned int hei = data_.getHei();
  const unsigned int wid = data_.getWid();

  if (hei == 0 || wid == 0) {
    return;
  }

  QPainter painter(this);

  const qreal cell_size =
      std::min(this->height() / hei, this->width() / wid) / scale_;

  QPen pen;
  pen.setWidthF(2.0 / scale_);
  pen.setColor(Qt::black);

  painter.setPen(pen);

  painter.translate(camera_);

  for (unsigned int i = 0; i < hei; ++i) {
    const qreal begin_y{i * cell_size};
    const qreal end_y{(i + 1) * cell_size};

    painter.drawLine(0, begin_y, 0, end_y);

    for (unsigned int j = 0; j < wid; ++j) {
      const qreal begin_x{j * cell_size};
      const qreal end_x{(j + 1) * cell_size};

      painter.drawLine(begin_x, 0, end_x, 0);

      if (data_.vertical_cells_[i][j]) {
        painter.drawLine(end_x, begin_y, end_x, end_y);
      }

      if (data_.horizontal_cells_[i][j]) {
        painter.drawLine(begin_x, end_y, end_x, end_y);
      }
    }
  }

  if (paint_path_ == true) {
    pen.setColor(Qt::red);
    painter.setPen(pen);

    for (unsigned int i = 1; i < path_.size(); ++i) {
      auto [y1, x1] = path_[i - 1];
      auto [y2, x2] = path_[i];

      const qreal offset{cell_size / 2};

      const qreal begin_x{x1 * cell_size + offset};
      const qreal begin_y{y1 * cell_size + offset};

      const qreal end_x{x2 * cell_size + offset};
      const qreal end_y{y2 * cell_size + offset};

      painter.drawLine(begin_x, begin_y, end_x, end_y);
    }
  }

  if (paint_from_ == true) {
    painter.setPen(Qt::NoPen);  // without borders
    painter.setBrush(QBrush(Qt::green));

    const qreal offset{cell_size / 4};

    const qreal x{from_.x * cell_size + offset};
    const qreal y{from_.y * cell_size + offset};
    const qreal size{cell_size / 2};

    painter.drawEllipse(x, y, size, size);
  }

  if (paint_to_ == true) {
    painter.setPen(Qt::NoPen);  // without borders
    painter.setBrush(QBrush(Qt::blue));

    const qreal offset{cell_size / 4};

    const qreal x{to_.x * cell_size + offset};
    const qreal y{to_.y * cell_size + offset};
    const qreal size{cell_size / 2};

    painter.drawEllipse(x, y, size, size);
  }
}

void MazeWidget::mousePressEvent(QMouseEvent* event) {
  const unsigned int hei = data_.getHei();
  const unsigned int wid = data_.getWid();

  if (hei == 0 || wid == 0) {
    return;
  }

  const qreal cell_size =
      std::min(this->height() / hei, this->width() / wid) / scale_;

  const unsigned int y = (event->pos().y() - camera_.y()) / cell_size;
  const unsigned int x = (event->pos().x() - camera_.x()) / cell_size;

  if (y >= hei || x >= wid) {
    return;
  }

  if (event->button() == Qt::LeftButton) {
    from_ = {y, x};

    paint_from_ = true;
    paint_path_ = false;

    this->repaint();
  } else if (event->button() == Qt::RightButton) {
    to_ = {y, x};

    paint_to_ = true;
    paint_path_ = false;

    this->repaint();
  }
}

}  // namespace s21
