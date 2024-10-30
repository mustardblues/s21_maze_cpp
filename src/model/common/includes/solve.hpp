// Copyright 2024 strangers

#ifndef _A1_MAZE_CPP_MODEL_SOLVE_HPP_
#define _A1_MAZE_CPP_MODEL_SOLVE_HPP_

namespace s21 {

enum class SolveAlgorithm { DFS, BFS, Q_learning };

struct Point final {
  unsigned int y;
  unsigned int x;
};

struct CellInfo final {
  bool wall;
  unsigned int y;
  unsigned int x;
};

class Map final {
 public:
  Map() = default;
  Map(const Map& other) = delete;
  Map(Map&& other) = delete;
  ~Map() = default;

  Map& operator=(const Map& other) = delete;

  int& operator()(const unsigned int row, const unsigned int col) {
    if (row >= len_ || col >= wid_) {
      static int default_value{-1};

      return default_value;
    }

    return map_[row][col];
  }

  void resize(const unsigned int len, const unsigned int wid) {
    len_ = len;
    wid_ = wid;

    map_.resize(len_, std::vector<int>(wid_, -1));
  }

  unsigned int len_;
  unsigned int wid_;

 private:
  std::vector<std::vector<int>> map_;
};

template <DataType T, SolveAlgorithm A>
class Solve final {
 public:
  Solve() = delete;
  Solve(const Solve& other) = delete;
  Solve(Solve&& other) = delete;
  ~Solve() = delete;

  Solve& operator=(const Solve& other) = delete;
};

bool checkWall(const unsigned int row, const unsigned int col,
               const BoolMatrix& matrix);

int randomInt(const unsigned int from, const unsigned int to);

}  // namespace s21

#endif  // _A1_MAZE_CPP_MODEL_SOLVE_HPP_