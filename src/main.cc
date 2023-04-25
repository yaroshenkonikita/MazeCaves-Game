// #include "matrix_oop.h"
#include "maze.h"
#include "cave.h"

// #include "new_cave.h"

int main() {
    Maze maze;
    maze.GenerateMaze(50, 50);
    // std::cout << maze;
    maze.PrintMaze();
    
    Cave cave;
    cave.GenerateCave(100, 100);
    // cave.PrintCave();
    
    // for (int i = 0; i < 6; ++i) {
    //     cave.IterateCave();
    //     cave.PrintCave();

    // }

    // cave.PrintCave();

    // cave.PrintCave();
    // cave.IterateCave();
    // std::cout << std::endl;
    // cave.PrintCave();

    cave.IterateCave();
    std::cout << std::endl;
    // cave.PrintCave();

    cave.IterateCave();
    std::cout << std::endl;
    // cave.PrintCave();

    cave.IterateCave();
    std::cout << std::endl;
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

    // s21::Cave cave;
    // cave.setLimits(4,4);
    // cave.generateMap(50, 50, 50);
    // cave.printCave();

    // std::cout << std::endl;

    // cave.updateMap();
    // cave.printCave();

    // std::cout << std::endl;

    // cave.updateMap();
    // cave.printCave();

    // std::cout << std::endl;

    // cave.updateMap();
    // cave.printCave();
    return 0;
}
