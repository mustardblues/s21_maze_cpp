// Copyright 2024 stranger

#ifndef _A1_MAZE_CPP_MODEL_Q_LEARNING_HPP_
#define _A1_MAZE_CPP_MODEL_Q_LEARNING_HPP_

namespace s21::Direction {

inline constexpr unsigned int left = 0;
inline constexpr unsigned int right = 1;
inline constexpr unsigned int up = 2;
inline constexpr unsigned int down = 3;

}  // namespace s21::Direction

namespace s21 {

using QTable = std::vector<std::vector<double>>;

template <>
class Solve<DataType::Maze, SolveAlgorithm::Q_learning> final {
 public:
  using value_type = Data<DataType::Maze>;

  Solve() = default;
  Solve(const Solve& other) = delete;
  Solve(Solve&& other) = delete;
  ~Solve() = default;

  Solve& operator=(const Solve& other) = delete;

  [[nodiscard]] std::deque<Point> solve(const Point& from, const Point& to,
                                        const value_type& data);

 private:
  inline bool checkMaze(const Point& from, const Point& to,
                        const value_type& data);

  // choose action a for state s
  inline unsigned int getAction(const Point& current_state);

  // perform action a, new state s'
  inline Point getNextState(const unsigned int action,
                            const Point& current_action,
                            const value_type& data);

  // update table with Bellman equation
  inline void updateTable(const unsigned int action, const Point& to,
                          Point& current_state, Point& next_state);

  // measure reward
  inline double getReward(const Point& current_state, const Point& next_state,
                          const Point& to);

  unsigned int hei_;
  unsigned int wid_;

  unsigned int episodes_{1000};  // max number of episodes

  double alpha_{0.1};     // learning rate
  double gamma_{0.99};    // discounted factor
  double epsilon_{0.05};  // greedy factor

  QTable table_;
};

}  // namespace s21

#endif  // _A1_MAZE_CPP_MODEL_Q_LEARNING_HPP_
