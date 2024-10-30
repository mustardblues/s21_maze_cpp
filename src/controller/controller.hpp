// Copyright 2024 zekkoaem & stranger

#ifndef _A1_MAZE_CPP_CONTROLLER_HPP_
#define _A1_MAZE_CPP_CONTROLLER_HPP_

#include "./../model/model.hpp"

namespace s21 {

class Controller final {
 public:
  Controller() = default;
  Controller(const Controller& other) = delete;
  Controller(Controller&& other) = delete;
  ~Controller() = default;

  Controller& operator=(const Controller& other) = delete;

  template <DataType T>
  [[nodiscard]] Data<T> load(const std::string& filename) {
    return Load<T>::load(filename);
  }

  template <DataType T>
  void save(const std::string& filename, const Data<T>& data) {
    Save<T>::save(filename, data);
  }

  template <DataType T, CreateAlgorithm A>
  [[nodiscard]] Data<T> create(const unsigned int len, const unsigned int wid) {
    Create<T, A> creator;

    return creator.create(len, wid);
  }

  template <DataType T, CreateAlgorithm A>
  [[nodiscard]] Data<T> create(const CreateSettings& settings) {
    return Create<T, A>::create(settings);
  }

  template <DataType T, CreateAlgorithm A>
  void updateData(const CreateSettings& settings, Data<T>& data) {
    Create<T, A>::updateData(settings, data);
  }

  template <DataType T, SolveAlgorithm A>
  [[nodiscard]] std::deque<Point> solve(const Point& from, const Point& to,
                                        const Data<T>& data) {
    Solve<T, A> solver;

    return solver.solve(from, to, data);
  }
};

}  // namespace s21

#endif  // _A1_MAZE_CPP_CONTROLLER_HPP_
