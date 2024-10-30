// Copyright 2024 stranger

#include "./../../model.hpp"

namespace s21 {

Data<DataType::Maze>::Data(const unsigned int hei, const unsigned int wid) {
  this->resize(hei, wid);
}

unsigned int Data<DataType::Maze>::getHei() const {
  return std::min(vertical_cells_.size(), horizontal_cells_.size());
}

unsigned int Data<DataType::Maze>::getWid() const {
  const unsigned int hei = this->getHei();

  if (hei == 0) {
    return 0;
  }

  return std::min(vertical_cells_[hei - 1].size(),
                  horizontal_cells_[hei - 1].size());
}

void Data<DataType::Maze>::resize(const unsigned int hei,
                                  const unsigned int wid) {
  if (hei > constants::limit || wid > constants::limit) {
    return;
  }

  vertical_cells_.resize(hei, std::vector<bool>(wid, false));
  horizontal_cells_.resize(hei, std::vector<bool>(wid, false));
}

void Data<DataType::Maze>::clear() {
  vertical_cells_.clear();
  horizontal_cells_.clear();
}

}  // namespace s21
