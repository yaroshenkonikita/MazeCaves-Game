#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include <random>

#include "matrix_oop.h"


class Cave {
public:

    Matrix &GenerateCave(int height, int width, double chance_of_spawn);

    // Можно сделать вывод через std::cout << maze
    void PrintCave();

    void SaveToFile(std::string filename);

    void IterateCave();
private:
    // enum walls {
    //     nothing,
    //     rigthWall,
    //     bottomWall,
    //     bothWalls
    // };

   int RandomInt(double p);

    Matrix matrix_{};

};