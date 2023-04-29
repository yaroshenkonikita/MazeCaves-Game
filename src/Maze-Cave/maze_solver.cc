#include "maze_solver.h"


#include <vector>

using namespace s21;

bool CheckForwardWall(Location current, Location turn, Matrix matrix_) {
    bool wall_forward = false;
    if (turn.x == 1) {
        if (matrix_(current.y, current.x) == kRigthWall ||
                matrix_(current.y, current.x) == kBothWalls) {
            wall_forward = true;
        }
    } else if (turn.x == -1) {
        if (current.x == 0) {
            wall_forward = true;
        } else {
            if (matrix_(current.y, current.x - 1) == kRigthWall ||
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

std::vector<Location> MazeSolver::SolveMaze(Location begin, Location end, Maze maze_) {
    this->maze_ = maze_;
    std::vector<Location> solution;
    solution.push_back(begin);

    Matrix matrix_ = maze_.GetMatrix();

    Location current = begin;
    Location turn(0, 1);
    // В начале работы надо найти стену. Двигаемся вниз пока в стену не упремся
    while (current.y + turn.y < matrix_.GetRows() &&
           matrix_(current.y, current.x) < kBottomWall) {
        current.y++;
    }

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
        bool wall_forward = CheckForwardWall(current, turn, matrix_);

        if (wall_forward) {
            // Если впереди стена - поворачиваем налево
            if (turn.x != 0) {
                turn.y = turn.x * -1;
                turn.x = 0;
            } else {
                turn.x = turn.y;
                turn.y = 0;
            }

            // Проверяем стену впереди
            wall_forward = CheckForwardWall(current, turn, matrix_);

            if (wall_forward) {
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

                solution.push_back(current);

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

            solution.push_back(current);

            // Проверяем на выход
            if (current.x == end.x && current.y == end.y) {
                break;
            }
        }
    }

    return solution;
}

void MazeSolver::PrintSolution(std::vector<Location> solution) {
    for (auto pos : solution) {
        std::cout << "{" << pos.x << ", " << pos.y << "}" << std::endl;
    }
}
