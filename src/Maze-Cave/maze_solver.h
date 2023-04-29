#ifndef MAZE_SRC_MAZE_SOLVER_H_
#define MAZE_SRC_MAZE_SOLVER_H_

// #include <iostream>
#include <vector>

//#include "Dependence/matrix_oop.h"
#include "maze.h"


namespace s21 {

enum Side {
    kLeft,
    kUp,
    kRigth,
    kDown
};

struct Location {
    int x;
    int y;
    Location() : x(0), y(0) {}
    Location(int x_value, int y_value) : x(x_value), y(y_value) {}
};

class MazeSolver{
public:

//    MazeSolver(Maze maze) : maze_(maze) {}

    std::vector<Location> SolveMaze(Location begin, Location end, Maze maze_);

    void PrintSolution(std::vector<Location> solution);

private:

    int GetRandomInt() const;

    Maze maze_{};

};

} // namespace s21

#endif // MAZE_SRC_MAZE_SOLVER_H_
