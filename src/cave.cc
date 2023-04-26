#include <iostream>
#include <vector>
#include <random>
#include <fstream>

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

void Cave::LoadFromFile(std::string filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::invalid_argument("The file does not exist");
    }
    std::string line;
    getline(file, line);
    size_t subPosition = 0;
    int height = std::stoi(line, &subPosition);
    int width = std::stoi(line.substr(subPosition + 1), &subPosition);
    if (height > 50 || width > 50) {
        throw std::invalid_argument("Incorrect size");
    }
    
    matrix_.Set(height, width);

    for (int i = 0; i < height; ++i) {
        getline(file, line);
        for (int j = 0, k = 0; j < width; ++j, k += 2) {
            char symbol = line.at(k);
            if (symbol != '0' && symbol != '1') {
                throw std::invalid_argument("The file must contain only ones and zeros");
            }
            matrix_(i, j) = symbol == '1' ? 1 : 0;
        }
    }

    file.close();
}

void Cave::SaveToFile(std::string filename) {
    std::ofstream file(filename);
    if (!file) {
        throw std::invalid_argument("The file does not exist");
    }
    int height = matrix_.GetRows();
    int width = matrix_.GetColumns();

    file << height << ' ' << width << '\n';

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            file << matrix_(i, j);
            if (j != width - 1) {
                file << " ";
            }
        }
        if (i != height - 1) {
            file << '\n';
        }
    }
}

