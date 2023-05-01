#include <gtest/gtest.h>

#include "../MazeCaves/Maze/maze_solver.h"

TEST(Maze, check_on_perfect_maze) {
    s21::Maze maze;
    maze.LoadFromFile("test.txt");
    EXPECT_TRUE(maze.IsValidMaze());
}

TEST(Maze, check_on_perfect_maze_false) { // it is same files with one different
    s21::Maze maze;
    maze.LoadFromFile("test.txt");
    EXPECT_ANY_THROW(maze.LoadFromFile("test_copy_invalid.txt"));
    EXPECT_TRUE(maze.IsValidMaze());
}

TEST(Maze, check_on_perfect_maze_generate) { // always random
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

TEST(Maze, escape_from_maze) {
    std::vector<s21::Location> loc{{0, 0}, {0, 1}, {0, 2},
                                   {0, 3}, {0, 4}, {0, 5},
                                   {0, 6}, {0, 7}, {0, 8},
                                   {1, 8}, {1, 7}, {2, 7},
                                   {2, 6}, {3, 6}, {3, 7},
                                   {4, 7}, {4, 6}, {5, 6},
                                   {5, 5}, {5, 4}, {5, 3},
                                   {6, 3}, {7, 3}, {7, 4},
                                   {7, 5}, {7, 6}, {8, 6},
                                   {8, 5}, {9, 5}, {9, 6},
                                   {9, 7}, {9, 8}, {9, 9}};
    s21::Maze maze;
    maze.LoadFromFile("test.txt");
    s21::MazeSolver solver;
    solver.SolveMaze({0, 0}, {9, 9}, maze);

    EXPECT_TRUE(loc == solver.GetLocations());
}
