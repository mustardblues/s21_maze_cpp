// Copyright 2024 zekkoaem & stranger

#include "./../../model.hpp"

namespace s21 {

[[nodiscard]] std::deque<Point>
Solve<DataType::Maze, SolveAlgorithm::DFS>::solve(
    const Point& from, const Point& to, const Data<DataType::Maze>& data) {
  std::deque<Point> path;

  hei_ = data.getHei();
  wid_ = data.getWid();

  if ((from.y > hei_ && from.x > wid_) || (to.y > hei_ && to.x > wid_)) {
    return path;
  }

  this->initCurrentState(from, to);

  if (this->depthSearch(data)) {
    while (!stack_.empty()) {
      path.emplace_back(stack_.top());

      stack_.pop();
    }
  }

  return path;
}

void Solve<DataType::Maze, SolveAlgorithm::DFS>::initCurrentState(
    const Point& from, const Point& to) {
  from_ = from;
  to_ = to;

  stack_.emplace(from_);

  depth_map_.resize(hei_, wid_);
  depth_map_(from_.y, from_.x) = 0;
}

bool Solve<DataType::Maze, SolveAlgorithm::DFS>::depthSearch(
    const Data<DataType::Maze>& data) {
  while (!stack_.empty()) {
    auto [row, col] = stack_.top();

    if (row == to_.y && col == to_.x) {
      return true;
    }

    if (!checkWall(row, col - 1, data.vertical_cells_) &&
        depth_map_(row, col - 1) == -1) {
      depth_map_(row, col - 1) = depth_map_(row, col) + 1;

      stack_.emplace(Point{row, col - 1});
    } else if (!checkWall(row, col, data.vertical_cells_) &&
               depth_map_(row, col + 1) == -1) {
      depth_map_(row, col + 1) = depth_map_(row, col) + 1;

      stack_.emplace(Point{row, col + 1});
    } else if (!checkWall(row - 1, col, data.horizontal_cells_) &&
               depth_map_(row - 1, col) == -1) {
      depth_map_(row - 1, col) = depth_map_(row, col) + 1;

      stack_.emplace(Point{row - 1, col});
    } else if (!checkWall(row, col, data.horizontal_cells_) &&
               depth_map_(row + 1, col) == -1) {
      depth_map_(row + 1, col) = depth_map_(row, col) + 1;

      stack_.emplace(Point{row + 1, col});
    } else {
      stack_.pop();
    }
  }

  return false;
}

}  // namespace s21