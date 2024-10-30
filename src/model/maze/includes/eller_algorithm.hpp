// Copyright 2024 stranger

#ifndef _A1_MAZE_CPP_MODEL_ELLER_ALGORITHM_HPP_
#define _A1_MAZE_CPP_MODEL_ELLER_ALGORITHM_HPP_

namespace s21 {

template <>
class Create<DataType::Maze, CreateAlgorithm::Eller> final {
 public:
  Create() = default;
  Create(const Create& other) = delete;
  Create(Create&& other) = delete;
  ~Create() = default;

  Create& operator=(const Create& other) = delete;

  [[nodiscard]] Data<DataType::Maze> create(const unsigned int hei,
                                            const unsigned int wid);

 private:
  void addRows(Data<DataType::Maze>& data);

  void addUniqueSets();

  void addVerticalWalls(std::vector<bool>& row);

  void mergeSets(const unsigned int element, const unsigned int basic);

  void addHorizontalWalls(std::vector<bool>& row);

  unsigned int calculateSetElements(const unsigned int element);

  void addFinalRow(Data<DataType::Maze>& data);

  unsigned int hei_;
  unsigned int wid_;

  unsigned int unique_set_counter_;

  std::vector<unsigned int> sets_;
};

}  // namespace s21

#endif  // _A1_MAZE_CPP_MODEL_ELLER_ALGORITHM_HPP_
