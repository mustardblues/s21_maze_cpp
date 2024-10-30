// Copyright 2024 zekkoaem & stranger

#include "gtest_.hpp"

TEST(test_cave, data) {
  Data<DataType::Cave> data(50, 50);

  EXPECT_EQ(50, data.getHei());
  EXPECT_EQ(50, data.getWid());

  EXPECT_EQ(false, data(0, 0));
  EXPECT_EQ(true, data(100, 100));
}

TEST(test_cave, save_load) {
  Controller controller;

  {
    Data<DataType::Cave> data;

    data.cells_.resize(50, std::vector<bool>(50, false));

    controller.save<DataType::Cave>("tmp.txt", data);
  }

  {
    Data<DataType::Cave> data = controller.load<DataType::Cave>("tmp.txt");

    EXPECT_EQ(50, data.getHei());
    EXPECT_EQ(50, data.getWid());
  }
}

TEST(test_cave, cellular_automaton) {
  Controller controller;

  {
    CreateSettings settings{0, 30, 0, 0, 49, 4, 4};

    Data<DataType::Cave> data =
        controller.create<DataType::Cave, CreateAlgorithm::Cellular_automaton>(
            settings);

    for (unsigned int i = 0; i < settings.gen; ++i) {
      controller
          .updateData<DataType::Cave, CreateAlgorithm::Cellular_automaton>(
              settings, data);
    }

    EXPECT_EQ(0, data.getHei());
    EXPECT_EQ(0, data.getWid());
  }

  {
    CreateSettings settings{0, 30, 50, 50, 49, 4, 4};

    Data<DataType::Cave> data =
        controller.create<DataType::Cave, CreateAlgorithm::Cellular_automaton>(
            settings);

    for (unsigned int i = 0; i < settings.gen; ++i) {
      controller
          .updateData<DataType::Cave, CreateAlgorithm::Cellular_automaton>(
              settings, data);
    }

    EXPECT_EQ(50, data.getHei());
    EXPECT_EQ(50, data.getWid());
  }
}
