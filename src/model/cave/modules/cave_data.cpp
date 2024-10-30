// Copyright 2024 stranger

#include "./../../model.hpp"

namespace s21 {

Data<DataType::Cave>::Data(const unsigned int hei, const unsigned int wid) {
  cells_.resize(hei, std::vector<bool>(wid, false));
}

unsigned int Data<DataType::Cave>::getHei() const { return cells_.size(); }

unsigned int Data<DataType::Cave>::getWid() const {
  const unsigned int hei = this->getHei();

  if (hei == 0) {
    return 0;
  }

  return cells_[hei - 1].size();
}

}  // namespace s21