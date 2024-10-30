// Copyright 2024 zekkoaem & stranger

#include "gtest_.hpp"

TEST(test_maze, data) {
  {
    Data<DataType::Maze> data;

    data.vertical_cells_.resize(50, std::vector<bool>(50, false));
    data.horizontal_cells_.resize(50, std::vector<bool>(50, false));

    EXPECT_EQ(50, data.getHei());
    EXPECT_EQ(50, data.getWid());
  }

  {
    Data<DataType::Maze> data;

    data.resize(50, 50);

    EXPECT_EQ(50, data.getHei());
    EXPECT_EQ(50, data.getWid());
  }

  {
    Data<DataType::Maze> data;

    data.vertical_cells_.resize(50, std::vector<bool>(50, false));

    EXPECT_EQ(0, data.getHei());
    EXPECT_EQ(0, data.getWid());
  }

  {
    Data<DataType::Maze> data;

    data.vertical_cells_.resize(50, std::vector<bool>(50, false));
    data.horizontal_cells_.resize(50, std::vector<bool>(50, false));

    data.clear();

    EXPECT_EQ(0, data.getHei());
    EXPECT_EQ(0, data.getWid());

    EXPECT_EQ(0, data.vertical_cells_.size());
    EXPECT_EQ(0, data.horizontal_cells_.size());
  }
}

TEST(test_maze, save_load) {
  Controller controller;

  {
    Data<DataType::Maze> data;

    data.vertical_cells_.resize(50, std::vector<bool>(50, false));
    data.horizontal_cells_.resize(50, std::vector<bool>(50, false));

    controller.save<DataType::Maze>("tmp.txt", data);
  }

  {
    Data<DataType::Maze> data = controller.load<DataType::Maze>("tmp.txt");

    EXPECT_EQ(50, data.getHei());
    EXPECT_EQ(50, data.getWid());
  }
}

TEST(test_maze, eller_algorithm) {
  Controller controller;

  {
    Data<DataType::Maze> data =
        controller.create<DataType::Maze, CreateAlgorithm::Eller>(0, 0);

    EXPECT_EQ(0, data.getHei());
    EXPECT_EQ(0, data.getWid());
  }

  {
    Data<DataType::Maze> data =
        controller.create<DataType::Maze, CreateAlgorithm::Eller>(50, 50);

    EXPECT_EQ(50, data.getHei());
    EXPECT_EQ(50, data.getWid());
  }
}

TEST(test_maze, dfs_algorithm) {
  Controller controller;

  {
    Data<DataType::Maze> data;

    Point from{0, 0};
    Point to{49, 49};

    std::deque<Point> path =
        controller.solve<DataType::Maze, SolveAlgorithm::DFS>(from, to, data);

    EXPECT_EQ(0, path.size());
  }

  {
    Data<DataType::Maze> data =
        controller.create<DataType::Maze, CreateAlgorithm::Eller>(50, 50);

    Point from{0, 0};
    Point to{49, 49};

    std::deque<Point> path =
        controller.solve<DataType::Maze, SolveAlgorithm::DFS>(from, to, data);

    EXPECT_FALSE(path.empty());
  }
}

TEST(test_maze, bfs_algorithm) {
  Controller controller;

  {
    Data<DataType::Maze> data;

    Point from{0, 0};
    Point to{49, 49};

    std::deque<Point> path =
        controller.solve<DataType::Maze, SolveAlgorithm::BFS>(from, to, data);

    EXPECT_EQ(0, path.size());
  }

  {
    Data<DataType::Maze> data =
        controller.create<DataType::Maze, CreateAlgorithm::Eller>(50, 50);

    Point from{0, 0};
    Point to{49, 49};

    std::deque<Point> path =
        controller.solve<DataType::Maze, SolveAlgorithm::BFS>(from, to, data);

    EXPECT_FALSE(path.empty());
  }
}

TEST(test_maze, q_learning) {
  Controller controller;

  {
    Data<DataType::Maze> data;

    Point from{0, 0};
    Point to{49, 49};

    std::deque<Point> path =
        controller.solve<DataType::Maze, SolveAlgorithm::Q_learning>(from, to,
                                                                     data);

    EXPECT_EQ(0, path.size());
  }

  {
    Data<DataType::Maze> data =
        controller.create<DataType::Maze, CreateAlgorithm::Eller>(4, 4);

    Point from{0, 0};
    Point to{3, 3};

    std::deque<Point> path =
        controller.solve<DataType::Maze, SolveAlgorithm::Q_learning>(from, to,
                                                                     data);

    EXPECT_FALSE(path.empty());
  }
}