#ifndef A1_MAZE_A_SRC_MAZE_CAVES_MAZE_MAZE_SOLVER_H_
#define A1_MAZE_A_SRC_MAZE_CAVES_MAZE_MAZE_SOLVER_H_

#include <queue>
#include <vector>

#include "maze.h"

namespace s21 {

struct Location {
  int x;
  int y;
  Location() : x(0), y(0) {}
  Location(int x_value, int y_value) : x(x_value), y(y_value) {}

  bool operator==(const Location &other) const {
    return x == other.x && y == other.y;
  }
};

class MazeSolver {
 public:
  MazeSolver() = delete;
  ~MazeSolver() = delete;
  static std::vector<Location> SolveMaze(Location begin, Location end,
                                  const Maze &maze_);
 private:
  static bool CheckForwardWall(Location current, Location turn, Matrix matrix_);
};

}  // namespace s21

#endif  // A1_MAZE_A_SRC_MAZE_CAVES_MAZE_MAZE_SOLVER_H_
