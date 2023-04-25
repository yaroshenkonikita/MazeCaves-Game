#include <iostream>
#include <vector>
#include <random>

#include "cave.h"

int Cave::GetRandomInt(double p) {
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    double random_num = dist(engine);
    return random_num > p ? 0 : 1;
}

Matrix &Cave::GenerateCave(int height, int width) {\
    
    // CHECK FOR VALID ARGUMENTS

    matrix_.Set(height, width);
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            matrix_(i, j) = GetRandomInt(chance_to_spawn_);
        }
    }
    return matrix_;
}

void Cave::IterateCave() {
    Matrix old_map(matrix_);
    for (int i = 0; i < matrix_.GetRows(); ++i) {
        for (int j = 0; j < matrix_.GetColumns(); ++j) {
            int neighbours = FindNeighboursCount(old_map, i, j);
            if (matrix_(i, j) == kDead && neighbours > birth_limit_) matrix_(i, j) = kAlive;
            if (matrix_(i, j) == kAlive && neighbours < death_limit_) matrix_(i, j) = kDead;
        }
    }
}

int Cave::FindNeighboursCount(Matrix &map, int rowPos, int colPos) {
    int count = 0;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (i == 0 && j == 0) continue;
            int cur_i = rowPos + i;
            int cur_j = colPos + j;
            if (cur_i < 0 || cur_j < 0 || cur_i >= map.GetRows() || cur_j >= map.GetColumns()) {
                count++;
            } else {
                count += map(rowPos + i, colPos + j);
            }
        }
    }
    return count;
}

void Cave::PrintCave() {
    for (int i = 0; i < matrix_.GetRows(); ++i) {
        for (int j = 0; j < matrix_.GetColumns(); ++j) {
            if (matrix_(i, j)) {
                std::cout << "#";
            } else {
                std::cout << " ";                
            }
        }
        std::cout << std::endl;
    }
}
