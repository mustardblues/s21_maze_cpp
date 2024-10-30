// Copyright 2024 zekkoaem & stranger

#include "./../../model.hpp"

namespace s21 {

[[nodiscard]] Data<DataType::Maze> Load<DataType::Maze>::load(
    const std::string& filename) {
  std::string content = getContent(filename);

  std::stringstream stream(content, std::ios::in);

  Data<DataType::Maze> data;

  readContent(stream, data);

  return data;
}

void Load<DataType::Maze>::readContent(std::stringstream& stream,
                                       Data<DataType::Maze>& data) {
  unsigned int hei{};
  unsigned int wid{};

  stream >> hei;
  stream >> wid;

  if (stream.fail()) {
    return;
  }

  data.resize(hei, wid);

  for (unsigned int i = 0; i < data.vertical_cells_.size(); ++i) {
    for (unsigned int j = 0; j < data.vertical_cells_[i].size(); ++j) {
      bool cell{};

      stream >> cell;

      if (!stream.fail()) {
        data.vertical_cells_[i][j] = cell;
      } else {
        data.clear();

        return;
      }
    }
  }

  for (unsigned int i = 0; i < data.horizontal_cells_.size(); ++i) {
    for (unsigned int j = 0; j < data.horizontal_cells_[i].size(); ++j) {
      bool cell{};

      stream >> cell;

      if (!stream.fail()) {
        data.horizontal_cells_[i][j] = cell;
      } else {
        data.clear();

        return;
      }
    }
  }
}

}  // namespace s21
