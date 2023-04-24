#include <iostream>
#include <vector>
#include <random>

#include "cave.h"

int Cave::RandomInt(double p) {
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    double random_num = dist(engine);
    return random_num > p ? 0 : 1;
}

Matrix &Cave::GenerateCave(int height, int width) {
    matrix_.Set(height + 2, width + 2);

    //init walls

    for (int i = 0; i < width + 2; i++) {
        for (int j = 0; j < height + 2; ++j) {
            if (i == 0 || j == 0 || i == width + 1 || j == height + 1) {
                matrix_(i, j) = 1;
            }
        }
    }

    for (int i = 1; i < width + 1; ++i) {
        for (int j = 1; j < height + 1; ++j) {
            matrix_(i, j) = RandomInt(chance_to_spawn_);
        }
    }

    return matrix_;
}

void Cave::IterateCave() {
    Matrix temp_cave = matrix_;
    for (int i = 1; i < matrix_.GetRows() - 1; ++i) {
        for (int j = 1; j < matrix_.GetColumns() - 1; ++j) {
            int sum_of_alive = 0;
            for (int temp_i = i - 1; temp_i < i + 2; ++temp_i) {
                for (int temp_j = j - 1; temp_j < j + 2; ++temp_j) {
                    // std::cout << "cave = " << cave[temp_i][temp_j] << std::endl;
                    // if (matrix_(temp_i, temp_j) == 0 && (temp_i != i && temp_j != j))
                    //     sum_of_alive++;
                    sum_of_alive += matrix_(temp_i, temp_j);
                }
            }
            if (matrix_(i, j)) {
                sum_of_alive--;
            }
            // std::cout << std::endl;
            // std::cout << "Sum of walls = " << sum_of_walls << std::endl;
            if (sum_of_alive >= 4) {
                temp_cave(i, j) = 1;
            } else {
                temp_cave(i, j) = 0;                
            }

        //     // Если "живые" клетки окружены "живыми" клетками, 
        //     // количество которых меньше, чем предел "смерти", они "умирают".
        //     if (matrix_(i, j) == 0 && sum_of_alive < death_limit_) {
        //         temp_cave(i, j) = 1;
        //     }

        //     // если "мертвые" клетки находятся рядом с "живыми", 
        //     // количество которых больше, чем предел "рождения", 
        //     // они становятся "живыми".
        //     if (matrix_(i, j) == 1 && sum_of_alive < birth_limit_) {
        //         temp_cave(i, j) = 0;
        //     }
        }
    }
    matrix_ = temp_cave;
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

// int main() {
//     std::vector<std::vector<int>> cave = generateCave(50, 50, 0.35);
//     printCave(cave);
//     iterateCave(cave);
//     std::cout << std::endl;
//     printCave(cave);

//     iterateCave(cave);
//     std::cout << std::endl;
//     printCave(cave);

//     iterateCave(cave);
//     std::cout << std::endl;
//     printCave(cave);
//     return 0;
// }