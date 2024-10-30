// Copyright 2024 stranger

#include "./../../model.hpp"

namespace s21 {

[[nodiscard]] std::deque<Point>
Solve<DataType::Maze, SolveAlgorithm::BFS>::solve(
    const Point& from, const Point& to, const Data<DataType::Maze>& data) {
  std::deque<Point> path;

  hei_ = data.getHei();
  wid_ = data.getWid();

  if ((from.y > hei_ && from.x > wid_) || (to.y > hei_ && to.x > wid_)) {
    return path;
  }

  this->initCurrentState(from, to);

  bool detected_final{};

  while (!queue_.empty()) {
    detected_final = this->spreadWave(data);

    if (detected_final) {
      break;
    }
  }

  if (detected_final) {
    this->returnToStart(path, data);
  }

  return path;
}

void Solve<DataType::Maze, SolveAlgorithm::BFS>::initCurrentState(
    const Point& from, const Point& to) {
  current_step_ = 0;

  from_ = from;
  to_ = to;

  queue_.emplace(from_);

  wave_map_.resize(hei_, wid_);
  wave_map_(from_.y, from_.x) = 0;
}

bool Solve<DataType::Maze, SolveAlgorithm::BFS>::spreadWave(
    const Data<DataType::Maze>& data) {
  ++current_step_;

  const unsigned int size = queue_.size();

  for (unsigned int i = 0; i < size; ++i) {
    auto [row, col] = queue_.front();

    queue_.pop();

    for (auto [cell, y, x] :
         {CellInfo{checkWall(row, col - 1, data.vertical_cells_), row, col - 1},
          CellInfo{checkWall(row, col, data.vertical_cells_), row, col + 1},
          CellInfo{checkWall(row - 1, col, data.horizontal_cells_), row - 1,
                   col},
          CellInfo{checkWall(row, col, data.horizontal_cells_), row + 1,
                   col}}) {
      if (cell == false) {
        if (wave_map_(y, x) == -1) {
          wave_map_(y, x) = current_step_;

          queue_.emplace(Point{y, x});
        }

        if (y == to_.y && x == to_.x) {
          return true;
        }
      }
    }
  }

  return false;
}

void Solve<DataType::Maze, SolveAlgorithm::BFS>::returnToStart(
    std::deque<Point>& path, const Data<DataType::Maze>& data) {
  auto [y, x] = to_;

  path.emplace_back(Point{y, x});

  while (wave_map_(y, x) != 0) {
    if (wave_map_(y, x) == wave_map_(y, x - 1) + 1 &&
        !checkWall(y, x - 1, data.vertical_cells_)) {
      --x;
    } else if (wave_map_(y, x) == wave_map_(y, x + 1) + 1 &&
               !checkWall(y, x, data.vertical_cells_)) {
      ++x;
    } else if (wave_map_(y, x) == wave_map_(y - 1, x) + 1 &&
               !checkWall(y - 1, x, data.horizontal_cells_)) {
      --y;
    } else if (wave_map_(y, x) == wave_map_(y + 1, x) + 1 &&
               !checkWall(y, x, data.horizontal_cells_)) {
      ++y;
    }

    path.emplace_back(Point{y, x});
  }
}

}  // namespace s21
