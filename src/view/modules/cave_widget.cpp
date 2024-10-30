// Copyright 2024 zekkoaem & stranger

#include "./../includes/cave_widget.hpp"

#include "./../uis/ui_cave_widget.h"

namespace s21 {

CaveWidget::CaveWidget(QWidget* parent)
    : BaseWidget(parent), ui_(new Ui::CaveWidget) {
  ui_->setupUi(this);

  ui_->current_gen_label->hide();

  this->connect(timer_, SIGNAL(timeout()), this, SLOT(cellularAutomatonDemo()));

  ui_->stackedWidget->setCurrentIndex(0);
  this->connect(ui_->menu_button, SIGNAL(clicked()), this,
                SLOT(clickedMenuButton()));

  this->connect(ui_->save_button, SIGNAL(clicked()), this,
                SLOT(clickedSaveButton()));
  this->connect(ui_->load_button, SIGNAL(clicked()), this,
                SLOT(clickedLoadButton()));
  this->connect(ui_->create_button, SIGNAL(clicked()), this,
                SLOT(clickedCreateButton()));
  this->connect(ui_->clear_button, SIGNAL(clicked()), this,
                SLOT(clickedClearButton()));

  this->connect(ui_->height_slider, SIGNAL(valueChanged(int)), this,
                SLOT(dragHeightSlider()));
  this->connect(ui_->width_slider, SIGNAL(valueChanged(int)), this,
                SLOT(dragWidthSlider()));
  this->connect(ui_->generations_slider, SIGNAL(valueChanged(int)), this,
                SLOT(dragGenerations()));
  this->connect(ui_->live_chance_slider, SIGNAL(valueChanged(int)), this,
                SLOT(dragLiveChance()));
  this->connect(ui_->birth_limit_slider, SIGNAL(valueChanged(int)), this,
                SLOT(dragBirthLimit()));
  this->connect(ui_->death_limit_slider, SIGNAL(valueChanged(int)), this,
                SLOT(dragDeathLimit()));
  this->connect(ui_->frequency_slider, SIGNAL(valueChanged(int)), this,
                SLOT(dragFrequency()));
}

CaveWidget::~CaveWidget() { delete ui_; }

void CaveWidget::resizeEvent(QResizeEvent* event) {
  Q_UNUSED(event);

  ui_->stackedWidget->move(QPoint{this->width() - 220, 0});
  ui_->stackedWidget->resize(QSize{this->width(), this->height()});
}

void CaveWidget::clickedSettingsButton() {}

void CaveWidget::clickedBackButton() {}

void CaveWidget::dragWidthSlider() {
  const int width = ui_->width_slider->value();

  ui_->width_label->setText("Width: " + QString::number(width));
}

void CaveWidget::dragHeightSlider() {
  const int height = ui_->height_slider->value();

  ui_->height_label->setText("Height: " + QString::number(height));
}

void CaveWidget::dragGenerations() {
  const int gen = ui_->generations_slider->value();

  ui_->generations_label->setText("Generations: " + QString::number(gen));
}

void CaveWidget::dragLiveChance() {
  const int live_chance = ui_->live_chance_slider->value();

  ui_->live_chance_label->setText(
      "Live chance: " + QString::number(live_chance) + "%");
}

void CaveWidget::dragBirthLimit() {
  const int birth_limit = ui_->birth_limit_slider->value();

  ui_->birth_limit_label->setText("Birth limit: " +
                                  QString::number(birth_limit));
}

void CaveWidget::dragDeathLimit() {
  const int death_limit = ui_->death_limit_slider->value();

  ui_->death_limit_label->setText("Death limit: " +
                                  QString::number(death_limit));
}

void CaveWidget::dragFrequency() {
  const int frequency = ui_->frequency_slider->value();

  ui_->frequency_label->setText("Frequency: " + QString::number(frequency) +
                                "ms");
}

void CaveWidget::clickedSaveButton() {
  timer_->stop();
  ui_->current_gen_label->hide();

  QString filename = QFileDialog::getSaveFileName(this, "Save file...", "/");

  if (filename.isEmpty()) {
    return;
  }

  controller_.save<DataType::Cave>(filename.toStdString(), data_);
}

void CaveWidget::clickedLoadButton() {
  timer_->stop();
  ui_->current_gen_label->hide();

  QString filename = QFileDialog::getOpenFileName(this, "Load file...", "/");

  if (filename.isEmpty()) {
    return;
  }

  data_ = controller_.load<DataType::Cave>(filename.toStdString());

  this->repaint();
}

void CaveWidget::clickedCreateButton() {
  timer_->stop();
  ui_->current_gen_label->hide();

  settings_ = CreateSettings{
      0,
      static_cast<unsigned int>(ui_->generations_slider->value()),

      static_cast<unsigned int>(ui_->height_slider->value()),
      static_cast<unsigned int>(ui_->width_slider->value()),

      static_cast<unsigned int>(ui_->live_chance_slider->value()),

      static_cast<unsigned int>(ui_->birth_limit_slider->value()),
      static_cast<unsigned int>(ui_->death_limit_slider->value())};

  if (data_.cells_.empty()) {
    data_ =
        controller_.create<DataType::Cave, CreateAlgorithm::Cellular_automaton>(
            settings_);
  }

  timer_->setInterval(ui_->frequency_slider->value());
  timer_->start();

  this->repaint();
}

void CaveWidget::clickedClearButton() {
  timer_->stop();
  ui_->current_gen_label->hide();

  data_.cells_.clear();

  this->repaint();
}

void CaveWidget::cellularAutomatonDemo() {
  ui_->current_gen_label->show();
  ui_->current_gen_label->setText(" Current generation: " +
                                  QString::number(settings_.current_gen));

  if (settings_.current_gen == settings_.gen) {
    timer_->stop();

    ui_->current_gen_label->hide();
  } else {
    controller_.updateData<DataType::Cave, CreateAlgorithm::Cellular_automaton>(
        settings_, data_);

    ++settings_.current_gen;
  }

  this->repaint();
}

void CaveWidget::paintEvent(QPaintEvent* event) {
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

  painter.setPen(pen);

  painter.translate(camera_);

  for (unsigned int i = 0; i < hei; ++i) {
    const qreal begin_y{i * cell_size};

    for (unsigned int j = 0; j < wid; ++j) {
      const qreal begin_x{j * cell_size};

      if (data_.cells_[i][j] == true) {
        painter.fillRect(begin_x, begin_y, cell_size, cell_size, Qt::gray);
      }
    }
  }
}

}  // namespace s21
