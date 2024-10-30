// Copyright 2024 stranger

#ifndef _A1_MAZE_CPP_MODEL_MAZE_LOAD_HPP_
#define _A1_MAZE_CPP_MODEL_MAZE_LOAD_HPP_

namespace s21 {

template <>
class Load<DataType::Maze> final {
 public:
  Load() = delete;
  Load(const Load& other) = delete;
  Load(Load&& other) = delete;
  ~Load() = delete;

  Load& operator=(const Load& other) = delete;

  [[nodiscard]] static Data<DataType::Maze> load(const std::string& filename);

 private:
  static void readContent(std::stringstream& stream,
                          Data<DataType::Maze>& data);
};

}  // namespace s21

#endif  // _A1_MAZE_CPP_MODEL_MAZE_LOAD_HPP_