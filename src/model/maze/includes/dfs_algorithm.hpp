// Copyright 2024 zekkoaem & stranger

#ifndef _A1_MAZE_CPP_MODEL_DFS_ALGORITHM_HPP_
#define _A1_MAZE_CPP_MODEL_DFS_ALGORITHM_HPP_

namespace s21 {

template <>
class Solve<DataType::Maze, SolveAlgorithm::DFS> final {
 public:
  Solve() = default;
  Solve(const Solve& other) = delete;
  Solve(Solve&& other) = delete;
  ~Solve() = default;

  Solve& operator=(const Solve& other) = delete;

  [[nodiscard]] std::deque<Point> solve(const Point& from, const Point& to,
                                        const Data<DataType::Maze>& data);

 private:
  void initCurrentState(const Point& from, const Point& to);

  bool depthSearch(const Data<DataType::Maze>& data);

  unsigned int hei_;
  unsigned int wid_;

  Point from_;
  Point to_;

  std::stack<Point> stack_;

  Map depth_map_;
};

}  // namespace s21

#endif  // _A1_MAZE_CPP_MODEL_DFS_ALGORITHM_HPP_
