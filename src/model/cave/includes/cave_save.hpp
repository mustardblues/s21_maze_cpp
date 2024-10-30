// Copyright 2024 zekkoaem & stranger

#ifndef _A1_MAZE_CPP_MODEL_CAVE_SAVE_HPP_
#define _A1_MAZE_CPP_MODEL_CAVE_SAVE_HPP_

namespace s21 {

template <>
class Save<DataType::Cave> final {
 public:
  Save() = delete;
  Save(const Save& other) = delete;
  Save(Save&& other) = delete;
  ~Save() = delete;

  Save& operator=(const Save& other) = delete;

  static void save(const std::string& filename,
                   const Data<DataType::Cave>& data);
};

}  // namespace s21

#endif  // _A1_MAZE_CPP_MODEL_CAVE_SAVE_HPP_
