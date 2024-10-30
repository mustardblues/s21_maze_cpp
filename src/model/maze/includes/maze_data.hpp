// Copyright 2024 stranger

#ifndef _A1_MAZE_CPP_MODEL_MAZE_DATA_HPP_
#define _A1_MAZE_CPP_MODEL_MAZE_DATA_HPP_

namespace s21 {

template <>
class Data<DataType::Maze> final {
 public:
  Data() = default;
  Data(const unsigned int hei, const unsigned int wid);
  Data(const Data& other) = default;
  Data(Data&& other) = default;
  ~Data() = default;

  Data& operator=(const Data& other) = default;

  unsigned int getHei() const;
  unsigned int getWid() const;

  void resize(const unsigned int hei, const unsigned int wid);
  void clear();

  BoolMatrix vertical_cells_;
  BoolMatrix horizontal_cells_;
};

}  // namespace s21

#endif  // _A1_MAZE_CPP_MODEL_MAZE_DATA_HPP_
