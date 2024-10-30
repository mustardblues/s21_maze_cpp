// Copyright 2024 zekkoaem & stranger

#include "./../../model.hpp"

namespace s21 {

[[nodiscard]] Data<DataType::Cave> Load<DataType::Cave>::load(
    const std::string& filename) {
  std::string content = getContent(filename);

  std::stringstream stream(content, std::ios::in);

  Data<DataType::Cave> data;

  readContent(stream, data);

  return data;
}

void Load<DataType::Cave>::readContent(std::stringstream& stream,
                                       Data<DataType::Cave>& data) {
  unsigned int hei{};
  unsigned int wid{};

  stream >> hei;
  stream >> wid;

  if (stream.fail()) {
    return;
  }

  data.cells_.resize(hei, std::vector<bool>(wid, false));

  for (unsigned int i = 0; i < data.cells_.size(); ++i) {
    for (unsigned int j = 0; j < data.cells_[i].size(); ++j) {
      bool cell{};

      stream >> cell;

      if (!stream.fail()) {
        data.cells_[i][j] = cell;
      } else {
        data.cells_.clear();

        return;
      }
    }
  }
}

}  // namespace s21
