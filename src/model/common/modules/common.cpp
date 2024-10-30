// Copyright 2024 stranger

#include "./../../model.hpp"

namespace s21 {

std::string getContent(const std::string& filename) {
  std::string content;

  std::fstream stream(filename.c_str(), std::ios::in);

  if (stream.is_open()) {
    std::stringstream buff;

    buff << stream.rdbuf();

    stream.close();

    content = buff.str();
  }

  return content;
}

bool checkWall(const unsigned int row, const unsigned int col,
               const BoolMatrix& matrix) {
  bool cell{true};

  if (row < matrix.size() && col < matrix[0].size()) {
    cell = matrix[row][col];
  }

  return cell;
}

bool randomBool() {
  std::random_device rd;
  std::default_random_engine gen(rd());
  std::uniform_int_distribution<int> dist(0, 1);

  return static_cast<bool>(dist(gen));
}

int randomInt(const unsigned int from, const unsigned int to) {
  std::random_device rd;
  std::default_random_engine gen(rd());
  std::uniform_int_distribution<int> dist(from, to);

  return static_cast<int>(dist(gen));
}

}  // namespace s21
