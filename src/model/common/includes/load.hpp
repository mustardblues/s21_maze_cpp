// Copyright 2024 stranger

#ifndef _A1_MAZE_CPP_MODEL_LOAD_HPP_
#define _A1_MAZE_CPP_MODEL_LOAD_HPP_

namespace s21 {

template <DataType T>
class Load final {
 public:
  Load() = delete;
  Load(const Load& other) = delete;
  Load(Load&& other) = delete;
  ~Load() = delete;

  Load& operator=(const Load& other) = delete;
};

std::string getContent(const std::string& filename);

}  // namespace s21

#endif  // _A1_MAZE_CPP_MODEL_LOAD_HPP_
