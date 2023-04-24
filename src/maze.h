#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include <random>

#include "matrix_oop.h"


class Maze{
public:

    Matrix &GenerateMaze(int height, int width);

    // Можно сделать вывод через std::cout << maze
    void PrintMaze();

    void SaveToFile(std::string filename);

private:
    enum walls {
        nothing,
        rigthWall,
        bottomWall,
        bothWalls
    };

    Matrix matrix_{};

};