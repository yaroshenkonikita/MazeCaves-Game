// #include "matrix_oop.h"
#include "maze.h"
#include "cave.h"

// #include "new_cave.h"

int main() {
    Maze maze;
    maze.GenerateMaze(40, 40);
    // std::cout << maze;
    maze.LoadFromFile("maze.txt");
    maze.PrintMaze();
    // maze.SaveToFile("maze.txt");

    // Cave cave;
    // cave.LoadFromFile("cave.txt");
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

    // cave.IterateCave();
    // std::cout << std::endl;
    // cave.PrintCave();

    // cave.IterateCave();
    // std::cout << std::endl;
    // cave.PrintCave();

    // cave.IterateCave();
    // std::cout << std::endl;
    // cave.SaveToFile("file.txt");
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
