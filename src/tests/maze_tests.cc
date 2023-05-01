#include <gtest/gtest.h>

#include "../MazeCaves/Maze/maze_solver.h"

TEST(Maze, check_on_perfect_maze) {
  s21::Maze maze;
  maze.LoadFromFile("tests/test.txt");
  EXPECT_TRUE(maze.IsValidMaze());
}

TEST(Maze,
     check_on_perfect_maze_false) {  // it is same files with one different
  s21::Maze maze;
  maze.LoadFromFile("tests/test.txt");
  EXPECT_ANY_THROW(maze.LoadFromFile("tests/test_copy_invalid.txt"));
  EXPECT_TRUE(maze.IsValidMaze());
}

TEST(Maze, parsing_file_no_exist) {
    s21::Maze maze;
    maze.LoadFromFile("tests/test.txt");
    EXPECT_ANY_THROW(maze.LoadFromFile("no_file.txt"));
    EXPECT_TRUE(maze.IsValidMaze());
}

TEST(Maze, invalid_data_parsing) {
    s21::Maze maze;
    maze.LoadFromFile("tests/test.txt");
    EXPECT_ANY_THROW(maze.LoadFromFile("tests/test_invalid_data.txt"));
    EXPECT_TRUE(maze.IsValidMaze());
}

TEST(Maze, invalid_data_parsing2) {
    s21::Maze maze;
    maze.LoadFromFile("tests/test.txt");
    EXPECT_ANY_THROW(maze.LoadFromFile("tests/test_invalid_data2.txt"));
    EXPECT_TRUE(maze.IsValidMaze());
}

TEST(Maze, invalid_data_parsing3) {
    s21::Maze maze;
    maze.LoadFromFile("tests/test.txt");
    EXPECT_ANY_THROW(maze.LoadFromFile("tests/test_invalid_data3.txt"));
    EXPECT_TRUE(maze.IsValidMaze());
}

TEST(Maze, save) {
    s21::Maze maze;
    maze.LoadFromFile("tests/test.txt");
    maze.SaveToFile("check_test_save.txt");
    s21::Maze copy;
    copy.LoadFromFile("check_test_save.txt");
    EXPECT_TRUE(copy.GetMatrix() == maze.GetMatrix());
}

TEST(Maze, check_on_perfect_maze_generate) {  // always random
  s21::Maze maze;
  maze.GenerateMaze(50, 50);
  EXPECT_TRUE(maze.IsValidMaze());
}

TEST(Maze, check_on_perfect_maze_generate2) {
  s21::Maze maze;
  maze.GenerateMaze(50, 50);
  EXPECT_TRUE(maze.IsValidMaze());
}

TEST(Maze, check_on_perfect_maze_generate3) {
  s21::Maze maze;
  maze.GenerateMaze(50, 50);
  EXPECT_TRUE(maze.IsValidMaze());
}

TEST(Maze, check_on_perfect_maze_generate4) {
  s21::Maze maze;
  maze.GenerateMaze(50, 50);
  EXPECT_TRUE(maze.IsValidMaze());
}

TEST(Maze, check_on_perfect_maze_generate5) {
  s21::Maze maze;
  maze.GenerateMaze(50, 50);
  EXPECT_TRUE(maze.IsValidMaze());
}

TEST(Maze, bad_generate) {  // always random
  s21::Maze maze;
  EXPECT_ANY_THROW(maze.GenerateMaze(52, 50));
}

TEST(MazeSolver, escape_from_maze) {
  std::vector<s21::Location> loc{
      {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8},
      {1, 8}, {1, 7}, {2, 7}, {2, 6}, {3, 6}, {3, 7}, {4, 7}, {4, 6}, {5, 6},
      {5, 5}, {5, 4}, {5, 3}, {6, 3}, {7, 3}, {7, 4}, {7, 5}, {7, 6}, {8, 6},
      {8, 5}, {9, 5}, {9, 6}, {9, 7}, {9, 8}, {9, 9}};
  s21::Maze maze;
  maze.LoadFromFile("tests/test.txt");
  s21::MazeSolver solver;
  solver.SolveMaze({0, 0}, {9, 9}, maze);
  EXPECT_TRUE(loc == solver.GetLocations());
}

TEST(MazeSolver, escape_from_maze_invalid) {
  s21::Maze maze;
  maze.GenerateMaze(10, 10);
  s21::MazeSolver solver;
  EXPECT_ANY_THROW(solver.SolveMaze({0, 0}, {9, 34}, maze));
}