// Copyright 2024 zekkoaem & stranger

#ifndef _A1_MAZE_CPP_MODEL_CELLULAR_AUTOMATON_HPP_
#define _A1_MAZE_CPP_MODEL_CELLULAR_AUTOMATON_HPP_

namespace s21 {

struct CreateSettings final {
  unsigned int current_gen;
  unsigned int gen;

  unsigned int hei;
  unsigned int wid;

  unsigned int live_chance;

  unsigned int lim_birth;
  unsigned int lim_death;
};

template <>
class Create<DataType::Cave, CreateAlgorithm::Cellular_automaton> {
 public:
  using value_type = Data<DataType::Cave>;

  Create() = default;
  Create(const Create& other) = delete;
  Create(Create&& other) = delete;
  ~Create() = default;

  Create& operator=(const Create& other) = delete;

  [[nodiscard]] static Data<DataType::Cave> create(
      const CreateSettings& settings);

  static void updateData(const CreateSettings& settings, value_type& data);

  static unsigned int calculateNearestCells(const unsigned int y,
                                            const unsigned int x,
                                            const value_type& data);
};

}  // namespace s21

#endif  // _A1_MAZE_CPP_MODEL_CELLULAR_AUTOMATON_HPP_
