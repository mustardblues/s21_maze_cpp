// Copyright 2024 stranger

#include "./../../model.hpp"

namespace s21 {

[[nodiscard]] Data<DataType::Maze>
Create<DataType::Maze, CreateAlgorithm::Eller>::create(const unsigned int hei,
                                                       const unsigned int wid) {
  Data<DataType::Maze> data(hei, wid);

  if (hei > constants::limit || hei == 0 || wid > constants::limit ||
      wid == 0) {
    return data;
  }

  hei_ = data.getHei();
  wid_ = data.getWid();

  sets_.resize(wid, 0);

  unique_set_counter_ = 1;

  this->addRows(data);

  this->addFinalRow(data);

  return data;
}

void Create<DataType::Maze, CreateAlgorithm::Eller>::addRows(
    Data<DataType::Maze>& data) {
  for (unsigned int i = 0; i < hei_ - 1; ++i) {
    this->addUniqueSets();

    this->addVerticalWalls(data.vertical_cells_[i]);
    this->addHorizontalWalls(data.horizontal_cells_[i]);
  }
}

void Create<DataType::Maze, CreateAlgorithm::Eller>::addUniqueSets() {
  for (unsigned int i = 0; i < wid_; ++i) {
    if (sets_[i] == 0) {
      sets_[i] = unique_set_counter_;

      ++unique_set_counter_;
    }
  }
}

void Create<DataType::Maze, CreateAlgorithm::Eller>::addVerticalWalls(
    std::vector<bool>& row) {
  for (unsigned int i = 0; i < wid_ - 1; ++i) {
    if (randomBool() || sets_[i] == sets_[i + 1]) {
      row[i] = true;
    } else {
      this->mergeSets(sets_[i + 1], sets_[i]);
    }
  }

  row[wid_ - 1] = true;
}

void Create<DataType::Maze, CreateAlgorithm::Eller>::mergeSets(
    const unsigned int element, const unsigned int basic) {
  for (unsigned int i = 0; i < wid_; ++i) {
    if (sets_[i] == element) {
      sets_[i] = basic;
    }
  }
}

void Create<DataType::Maze, CreateAlgorithm::Eller>::addHorizontalWalls(
    std::vector<bool>& row) {
  for (unsigned int i = 0; i < wid_; ++i) {
    unsigned int element_number = this->calculateSetElements(sets_[i]);

    if (randomBool() && element_number > 1) {
      row[i] = true;

      sets_[i] = 0;
    }
  }
}

unsigned int
Create<DataType::Maze, CreateAlgorithm::Eller>::calculateSetElements(
    const unsigned int element) {
  unsigned int counter = 0;

  for (unsigned int i = 0; i < wid_; ++i) {
    if (sets_[i] == element) {
      ++counter;
    }
  }

  return counter;
}

void Create<DataType::Maze, CreateAlgorithm::Eller>::addFinalRow(
    Data<DataType::Maze>& data) {
  this->addUniqueSets();

  this->addVerticalWalls(data.vertical_cells_[hei_ - 1]);

  for (unsigned int i = 0; i < wid_ - 1; ++i) {
    if (sets_[i] != sets_[i + 1]) {
      data.vertical_cells_[hei_ - 1][i] = false;

      this->mergeSets(sets_[i + 1], sets_[i]);
    }

    data.horizontal_cells_[hei_ - 1][i] = true;
  }

  data.horizontal_cells_[hei_ - 1][wid_ - 1] = true;
}

}  // namespace s21
