// Copyright 2024 stranger

#ifndef _A1_MAZE_CPP_MODEL_BFS_ALGORITHM_HPP_
#define _A1_MAZE_CPP_MODEL_BFS_ALGORITHM_HPP_

namespace s21 {

template <>
class Solve<DataType::Maze, SolveAlgorithm::BFS> final {
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

  bool spreadWave(const Data<DataType::Maze>& data);

  void returnToStart(std::deque<Point>& path, const Data<DataType::Maze>& data);

  unsigned int hei_;
  unsigned int wid_;

  unsigned int current_step_;

  Point from_;
  Point to_;

  std::queue<Point> queue_;

  Map wave_map_;
};

}  // namespace s21

#endif  // _A1_MAZE_CPP_MODEL_BFS_ALGORITHM_HPP_
