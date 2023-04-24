// #include "matrix_oop.h"
#include "maze.h"

int main() {
    // std::vector<std::vector<Cell>> maze = generateMaze(10, 10);
    // printMaze(maze);

    Maze maze;
    maze.GenerateMaze(20, 20);
    // std::cout << maze;
    maze.PrintMaze();
    
    return 0;
}
