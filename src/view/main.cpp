// Copyright 2024 zekkoaem & stranger

#include "includes/menu_widget.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QFontDatabase::addApplicationFont(":/fonts/PIXY.ttf");

  s21::MenuWidget w;

  w.show();

  return app.exec();
}
