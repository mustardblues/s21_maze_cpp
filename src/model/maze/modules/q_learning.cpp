// Copyright 2024 zekkoaem & stranger

#include "./../../model.hpp"

namespace s21 {

[[nodiscard]] std::deque<Point>
Solve<DataType::Maze, SolveAlgorithm::Q_learning>::solve(
    const Point& from, const Point& to, const value_type& data) {
  std::deque<Point> path;

  hei_ = data.getHei();
  wid_ = data.getWid();

  if (this->checkMaze(from, to, data)) {
    return path;
  }

  // initialize Q-values
  table_.resize(hei_ * wid_, std::vector<double>(4, 0.0));

  for (unsigned int i = 0; i < episodes_; ++i) {
    Point current_state = from;

    while (current_state.y != to.y || current_state.x != to.x) {
      unsigned int action = this->getAction(current_state);

      Point next_state = this->getNextState(action, current_state, data);

      this->updateTable(action, to, current_state, next_state);

      current_state = next_state;
    }
  }

  Point current_state = from;
  path.emplace_back(from);

  while (current_state.y != to.y || current_state.x != to.x) {
    auto [y, x] = current_state;

    unsigned int action = std::max_element(table_[wid_ * y + x].begin(),
                                           table_[wid_ * y + x].end()) -
                          table_[wid_ * y + x].begin();

    current_state = this->getNextState(action, current_state, data);

    path.emplace_back(current_state);
  }

  return path;
}

bool Solve<DataType::Maze, SolveAlgorithm::Q_learning>::checkMaze(
    const Point& from, const Point& to, const value_type& data) {
  if ((from.y > hei_ && from.x > wid_) || (to.y > hei_ && to.x > wid_)) {
    return true;
  }

  Solve<DataType::Maze, SolveAlgorithm::BFS> check;

  return check.solve(from, to, data).empty();
}

unsigned int Solve<DataType::Maze, SolveAlgorithm::Q_learning>::getAction(
    const Point& current_state) {
  unsigned int action{};

  auto [y, x] = current_state;

  if ((randomInt(0, 100) / 100) < epsilon_) {
    action = randomInt(0, 3);
  } else {
    action = std::max_element(table_[wid_ * y + x].begin(),
                              table_[wid_ * y + x].end()) -
             table_[wid_ * y + x].begin();
  }

  return action;
}

Point Solve<DataType::Maze, SolveAlgorithm::Q_learning>::getNextState(
    const unsigned int action, const Point& current_action,
    const value_type& data) {
  Point point(current_action);

  auto [y, x] = current_action;

  switch (action) {
    case Direction::left:
      point.x -= checkWall(y, x - 1, data.vertical_cells_) ? 0 : 1;
      break;
    case Direction::right:
      point.x += checkWall(y, x, data.vertical_cells_) ? 0 : 1;
      break;
    case Direction::up:
      point.y -= checkWall(y - 1, x, data.horizontal_cells_) ? 0 : 1;
      break;
    case Direction::down:
      point.y += checkWall(y, x, data.horizontal_cells_) ? 0 : 1;
      break;
    default:;
      break;
  }

  if (point.y >= hei_ || point.x >= wid_) {
    point = current_action;
  }

  return point;
}

void Solve<DataType::Maze, SolveAlgorithm::Q_learning>::updateTable(
    const unsigned int action, const Point& to, Point& current_state,
    Point& next_state) {
  auto [cy, cx] = current_state;
  auto [ny, nx] = next_state;

  double reward = this->getReward(current_state, next_state, to);

  double future_value = *std::max_element(table_[wid_ * ny + nx].begin(),
                                          table_[wid_ * ny + nx].end());
  double target = reward + gamma_ * future_value;
  double temp_difference = target - table_[wid_ * cy + cx][action];

  table_[wid_ * cy + cx][action] += alpha_ * temp_difference;
}

double Solve<DataType::Maze, SolveAlgorithm::Q_learning>::getReward(
    const Point& current_state, const Point& next_state, const Point& to) {
  double reward{};

  if (next_state.y == to.y && next_state.x == to.x) {
    reward = 1;
  } else if (next_state.y != current_state.y &&
             next_state.x != current_state.x) {
    reward = 0;
  } else {
    reward = -1;
  }

  return reward;
}

}  // namespace s21
