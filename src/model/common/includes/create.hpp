// Copyright 2024 stranger

#ifndef _A1_MAZE_CPP_MODEL_CREATE_HPP_
#define _A1_MAZE_CPP_MODEL_CREATE_HPP_

namespace s21 {

enum class CreateAlgorithm { Eller, Cellular_automaton };

template <DataType T, CreateAlgorithm A>
class Create final {
  Create() = delete;
  Create(const Create& other) = delete;
  Create(Create&& other) = delete;
  ~Create() = delete;

  Create& operator=(const Create& other) = delete;
};

bool randomBool();

}  // namespace s21

#endif  // _A1_MAZE_CPP_MODEL_CREATE_HPP_
