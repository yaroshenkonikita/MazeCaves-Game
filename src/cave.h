#ifndef MAZE_SRC_CAVE_H_
#define MAZE_SRC_CAVE_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include <random>

#include "matrix_oop.h"

enum CellState { kDead, kAlive };

class Cave {
public:

    Cave() {
        this->chance_to_spawn_ = 0.45;
        this->birth_limit_ = 3;
        this->death_limit_ = 4;
    }

    Cave(double chance_to_spawn, int birth_limit, int death_limit) {
        this->chance_to_spawn_ = chance_to_spawn_;
        this->birth_limit_ = birth_limit;
        this->death_limit_ = death_limit;
    }

    Matrix &GenerateCave(int height, int width);

    // Можно сделать вывод через std::cout << maze
    void PrintCave();

    void SaveToFile(std::string filename);

    void IterateCave();
private:

    int GetRandomInt(double p);

    int FindNeighboursCount(Matrix &map, int rowPos, int colPos);

    Matrix matrix_{};

    double chance_to_spawn_{};
    int birth_limit_{};
    int death_limit_{};
};

#endif // MAZE_SRC_CAVE_H_