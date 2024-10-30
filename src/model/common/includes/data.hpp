// Copyright 2024 stranger

#ifndef _A1_MAZE_CPP_MODEL_DATA_HPP_
#define _A1_MAZE_CPP_MODEL_DATA_HPP_

namespace s21 {

using BoolMatrix = std::vector<std::vector<bool>>;

enum class DataType { Maze, Cave };

template <DataType T>
class Data final {
 public:
  Data() = delete;
  Data(const Data& other) = delete;
  Data(Data&& other) = delete;
  ~Data() = delete;

  Data& operator=(const Data& other) = delete;
};

}  // namespace s21

namespace s21::constants {

inline constexpr unsigned int limit = 500;

}  // namespace s21::constants

#endif  // _A1_MAZE_CPP_MODEL_DATA_HPP_
