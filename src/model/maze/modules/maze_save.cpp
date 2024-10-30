// Copyright 2024 stranger

#include "./../../model.hpp"

namespace s21 {

void Save<DataType::Maze>::save(const std::string& filename,
                                const Data<DataType::Maze>& data) {
  std::fstream stream(filename.c_str(), std::ios::out);

  const unsigned int hei = data.getHei();
  const unsigned int wid = data.getWid();

  stream << hei << " " << wid << std::endl;

  for (unsigned int i = 0; i < hei; ++i) {
    for (unsigned int j = 0; j < wid; ++j) {
      stream << data.vertical_cells_[i][j] << " ";
    }

    stream << std::endl;
  }

  stream << std::endl;

  for (unsigned int i = 0; i < hei; ++i) {
    for (unsigned int j = 0; j < wid; ++j) {
      stream << data.horizontal_cells_[i][j] << " ";
    }

    stream << std::endl;
  }
}

}  // namespace s21