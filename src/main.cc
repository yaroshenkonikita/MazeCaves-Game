// #include "matrix_oop.h"
#include "maze.h"
#include "cave.h"

int main() {
    Maze maze;
    maze.GenerateMaze(20, 20);
    // std::cout << maze;
    maze.PrintMaze();
    
    Cave cave;
    cave.GenerateCave(50, 50);
    cave.PrintCave();
    cave.IterateCave();
    std::cout << std::endl;
    cave.PrintCave();

    cave.IterateCave();
    std::cout << std::endl;
    cave.PrintCave();

    cave.IterateCave();
    std::cout << std::endl;
    cave.PrintCave();

    // cave.IterateCave();
    // std::cout << std::endl;
    // cave.PrintCave();
    
    // cave.IterateCave();
    // std::cout << std::endl;
    // cave.PrintCave();
    
    // cave.IterateCave();
    // std::cout << std::endl;
    // cave.PrintCave();
        
    // cave.IterateCave();
    // std::cout << std::endl;
    // cave.PrintCave();
    return 0;
}
