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

/* UNNECESSARY PART OF CODE
bool MazeSolver::CanMove(Location current, Location turn, Matrix matrix_) {
    int next_x = current.x + turn.x;
    int next_y = current.y + turn.y;
    if (next_x < 0 || next_x >= matrix_.GetColumns() ||
        next_y < 0 || next_y >= matrix_.GetRows()) {
        return false;
    }
    if (CheckForwardWall(current, turn, matrix_)) {
        return false;
    }
    return true;
}
*/

std::vector<Location> MazeSolver::SolveMaze(Location begin, Location end,
                                            const Maze &maze_) {
  if (begin.x >= maze_.GetColumns() || begin.y >= maze_.GetRows() ||
      end.x >= maze_.GetColumns() || end.y >= maze_.GetRows()) {
    throw std::invalid_argument("Begin or End position is invalid");
  }
  locations_.clear();
  locations_.push_back(begin);

  Matrix matrix_ = maze_.GetMatrix();

  Location current = begin;
  Location turn(0, 1);

  // В начале работы надо найти стену. Двигаемся вниз пока в стену не упремся
  //    while (current.y + turn.y < matrix_.GetRows() &&
  //           matrix_(current.y, current.x) < kBottomWall) {
  //        current.y++;
  //    }

  while (true) {
    // Поворачиваем направо
    if (turn.x != 0) {
      turn.y = turn.x;
      turn.x = 0;
    } else {
      turn.x = turn.y * -1;
      turn.y = 0;
    }

    // Проверяем стену впереди
    if (CheckForwardWall(current, turn, matrix_)) {
      // Если впереди стена - поворачиваем налево
      if (turn.x != 0) {
        turn.y = turn.x * -1;
        turn.x = 0;
      } else {
        turn.x = turn.y;
        turn.y = 0;
      }

      // Проверяем стену впереди
      if (CheckForwardWall(current, turn, matrix_)) {
        // Если стена впереди - поворачиваем налево
        if (turn.x != 0) {
          turn.y = turn.x * -1;
          turn.x = 0;
        } else {
          turn.x = turn.y;
          turn.y = 0;
        }
      } else {
        // Если же стены нет, то идем вперед
        // На выход за пределы лабиринта можно не проверять,
        // так как в проверке на стену впереди все сделано
        current.x += turn.x;
        current.y += turn.y;

        while (std::count(locations_.begin(), locations_.end(), current)) {
          locations_.pop_back();
        }
        locations_.push_back(current);

        // Проверяем на выход
        if (current.x == end.x && current.y == end.y) {
          break;
        }
      }
    } else {
      // Если же стены нет, то идем вперед
      // На выход за пределы лабиринта можно не проверять,
      // так как в проверке на стену впереди все сделано
      current.x += turn.x;
      current.y += turn.y;

      while (std::count(locations_.begin(), locations_.end(), current)) {
        locations_.pop_back();
      }
      locations_.push_back(current);

      // Проверяем на выход
      if (current.x == end.x && current.y == end.y) {
        break;
      }
    }
  }

  /* UNNECESSARY PART OF CODE
  const Location directions[4] {
      Location(0, -1), // вверх
      Location(1, 0),  // вправо
      Location(0, 1),  // вниз
      Location(-1, 0)  // влево
  };

  // Используем алгоритм поиска в ширину (BFS) для того, чтобы
  // убрать все тупики и неиспользуемые клетки в пути
  std::queue<std::vector<Location>> q;
  q.push(locations_);

  while (!q.empty()) {
      auto path = q.front();
      q.pop();
      auto last = path.back();

      if (last.x == end.x && last.y == end.y) {
          locations_ = path;
          break;
      }

      for (auto dir : directions) {
          Location next;
          next.x = last.x + dir.x;
          next.y = last.y + dir.y;
          if (!CanMove(last, next, matrix_)) {
              continue;
          }

          if (std::find(path.begin(), path.end(), next) != path.end()) {
              continue;
          }

          std::vector<Location> new_path = path;
          new_path.push_back(next);
          q.push(new_path);
      }
  }
  */
  return locations_;
}

// void MazeSolver::PrintSolution() {
//     for (auto pos : locations_) {
//         std::cout << "{" << pos.x << ", " << pos.y << "}" << std::endl;
//     }
// }

std::vector<Location> &MazeSolver::GetLocations() { return locations_; }
