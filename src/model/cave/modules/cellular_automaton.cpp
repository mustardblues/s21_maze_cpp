// Copyright 2024 zekkoaem & stranger

#include "./../../model.hpp"

namespace s21 {

[[nodiscard]] Data<DataType::Cave>
Create<DataType::Cave, CreateAlgorithm::Cellular_automaton>::create(
    const CreateSettings& settings) {
  Data<DataType::Cave> data;

  data.cells_.resize(settings.hei, std::vector<bool>(settings.wid, false));

  for (unsigned int i = 0; i < settings.hei; ++i) {
    for (unsigned int j = 0; j < settings.wid; ++j) {
      data.cells_[i][j] =
          settings.live_chance > static_cast<unsigned int>(randomInt(0, 100))
              ? 1
              : 0;
    }
  }

  return data;
}

void Create<DataType::Cave, CreateAlgorithm::Cellular_automaton>::updateData(
    const CreateSettings& settings, value_type& data) {
  for (unsigned int i = 0; i < data.cells_.size(); ++i) {
    for (unsigned int j = 0; j < data.cells_[i].size(); ++j) {
      const unsigned int live_cells = calculateNearestCells(i, j, data);

      if (data.cells_[i][j] == true && live_cells < settings.lim_death) {
        data.cells_[i][j] = false;
      } else if (live_cells > settings.lim_birth) {
        data.cells_[i][j] = true;
      }
    }
  }
}

unsigned int Create<DataType::Cave, CreateAlgorithm::Cellular_automaton>::
    calculateNearestCells(const unsigned int y, const unsigned int x,
                          const value_type& data) {
  unsigned int count{};

  for (auto cell : {data(y, x - 1), data(y, x + 1), data(y - 1, x),
                    data(y + 1, x), data(y - 1, x - 1), data(y - 1, x + 1),
                    data(y + 1, x - 1), data(y + 1, x + 1)}) {
    if (cell == true) {
      ++count;
    }
  }

  return count;
}

}  // namespace s21
