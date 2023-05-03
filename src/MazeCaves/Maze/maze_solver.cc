#include "maze_solver.h"

using namespace s21;

bool MazeSolver::CheckForwardWall(Location current, Location turn,
                                  Matrix matrix_) {
  bool wall_forward = false;
  if (turn.x == 1) {
    if (matrix_(current.y, current.x) == kRightWall ||
        matrix_(current.y, current.x) == kBothWalls) {
      wall_forward = true;
    }
  } else if (turn.x == -1) {
    if (current.x == 0) {
      wall_forward = true;
    } else {
      if (matrix_(current.y, current.x - 1) == kRightWall ||
          matrix_(current.y, current.x - 1) == kBothWalls) {
        wall_forward = true;
      }
    }
  } else if (turn.y == 1) {
    if (matrix_(current.y, current.x) >= kBottomWall) {
      wall_forward = true;
    }
  } else if (turn.y == -1) {
    if (current.y == 0) {
      wall_forward = true;
    } else {
      if (matrix_(current.y - 1, current.x) >= kBottomWall) {
        wall_forward = true;
      }
    }
  }
  return wall_forward;
}

std::vector<Location> MazeSolver::SolveMaze(Location begin, Location end,
                                            const Maze &maze_) {
  if (begin.x >= maze_.GetColumns() || begin.y >= maze_.GetRows() ||
      end.x >= maze_.GetColumns() || end.y >= maze_.GetRows()) {
    throw std::invalid_argument("Begin or End position is invalid");
  }
  std::vector<Location> locations;
  locations.clear();
  locations.push_back(begin);

  const Matrix& matrix_ = maze_.GetMatrix();

  Location current = begin;
  Location turn(0, 1);

  while (true) {
    if (turn.x != 0) {
      turn.y = turn.x;
      turn.x = 0;
    } else {
      turn.x = turn.y * -1;
      turn.y = 0;
    }

    if (CheckForwardWall(current, turn, matrix_)) {
      if (turn.x != 0) {
        turn.y = turn.x * -1;
        turn.x = 0;
      } else {
        turn.x = turn.y;
        turn.y = 0;
      }

      if (CheckForwardWall(current, turn, matrix_)) {
        if (turn.x != 0) {
          turn.y = turn.x * -1;
          turn.x = 0;
        } else {
          turn.x = turn.y;
          turn.y = 0;
        }
      } else {
        current.x += turn.x;
        current.y += turn.y;

        while (std::count(locations.begin(), locations.end(), current)) {
          locations.pop_back();
        }
        locations.push_back(current);
      }
    } else {
      current.x += turn.x;
      current.y += turn.y;

      while (std::count(locations.begin(), locations.end(), current)) {
        locations.pop_back();
      }
      locations.push_back(current);
    }

    if (current.x == end.x && current.y == end.y) {
      break;
    }
  }
  return locations;
}
