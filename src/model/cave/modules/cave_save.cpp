// Copyright 2024 zekkoaem & stranger

#include "./../../model.hpp"

namespace s21 {

void Save<DataType::Cave>::save(const std::string& filename,
                                const Data<DataType::Cave>& data) {
  std::fstream stream(filename.c_str(), std::ios::out);

  unsigned int hei = data.getHei();
  unsigned int wid = data.getWid();

  stream << hei << " " << wid << std::endl;

  for (unsigned int i = 0; i < hei; ++i) {
    for (unsigned int j = 0; j < wid; ++j) {
      stream << data.cells_[i][j] << " ";
    }

    stream << std::endl;
  }
}

}  // namespace s21
