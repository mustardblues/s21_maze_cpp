// Copyright 2024 zekkoaem & stranger

#ifndef A1_MAZE_CPP_MODEL_CAVE_DATA_HPP_
#define A1_MAZE_CPP_MODEL_CAVE_DATA_HPP_

namespace s21 {

template <>
class Data<DataType::Cave> final {
 public:
  Data() = default;
  Data(const unsigned int len, const unsigned int wid);
  Data(const Data& other) = default;
  Data(Data&& other) = default;
  ~Data() = default;

  Data& operator=(const Data& other) = default;

  bool operator()(const unsigned int row, const unsigned int col) const {
    if (row >= this->getHei() || col >= this->getWid()) {
      return true;
    }

    return cells_[row][col];
  }

  unsigned int getHei() const;
  unsigned int getWid() const;

  BoolMatrix cells_;
};

}  // namespace s21

#endif  // A1_MAZE_CPP_MODEL_CAVE_DATA_HPP_
