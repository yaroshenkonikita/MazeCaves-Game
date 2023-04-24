#include "maze.h"

Matrix &Maze::GenerateMaze(int height, int width) {
    // initialization the maze
    matrix_.Set(height, width);

    // initialization right and bottom walls 
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (col == width - 1) {
                matrix_(row, col) += rigthWall;
            }
            if (row == height - 1) {
                matrix_(row, col) += bottomWall;
            }
        }
    }

    std::vector<int> row_set;
    row_set.reserve(width);
    for (int i = 0; i < width; ++i)
        row_set.push_back(0);

    int set = 1;

    std::random_device rd;
    std::default_random_engine mt(rd());

    std::uniform_int_distribution<int> dist(0, 2);

    for (int row = 0; row < height - 1; ++row) {
        
        // join cells not members of a set to their own unique set
        for (int col = 0; col < width; ++col) {
            if (row_set[col] == 0) {
                row_set[col] = set++;                
            }
        }

        
        // create right walls
        for (int col = 0; col < width - 1; ++col) {
            const auto right_wall = dist(mt);

            if ((right_wall) || (row_set[col] == row_set[col + 1])) {
                matrix_(row, col) += rigthWall;
            } else {
                const auto changing_set = row_set[col + 1];
                for (int i = 0; i < width; ++i) {
                    if (row_set[i] == changing_set) {
                        row_set[i] = row_set[col];
                    }
                }
                // row_set[col + 1] = row_set[col];
            }
        }

        // create bottom walls
        for (int col = 0; col < width; ++col) {
            const auto bottom_wall = dist(mt);
            unsigned int count_current_set = 0;
            for (int i = 0; i < width; ++i) {
                if (row_set[col] == row_set[i]) {
                    count_current_set++;
                }
            }
            if ((bottom_wall) && (count_current_set != 1)) {
                matrix_(row, col) += bottomWall;
            }
        }

        if (row != height - 1) {
            for (int col = 0; col < width; ++col) {
                unsigned count_hole = 0;
                for (int i = 0; i < width; ++i) {
                    if ((row_set[i] == row_set[col]) && (matrix_(row, i) < bottomWall)) {
                        count_hole++;
                    }
                }
                if (count_hole == 0 && matrix_(row, col) >= bottomWall) {
                    matrix_(row, col) -= bottomWall;
                }
            }
        }

        // create a new row
        if (row != height - 1) {
            for (int col = 0; col < width; ++col) {
                if (matrix_(row, col) >= bottomWall) {
                    row_set[col] = 0;
                }
            }
        }
    }

    // join cells not members of a set to their own unique set
    for (int col = 0; col < width; ++col) {
        if (row_set[col] == 0) {
            row_set[col] = set++;                
        }
    }

    // create right walls
    for (int col = 0; col < width - 1; ++col) {
        const auto right_wall = dist(mt);

        if ((right_wall) || (row_set[col] == row_set[col + 1])) {
            matrix_(height - 1, col) += rigthWall;
        } else {
            const auto changing_set = row_set[col + 1];
            for (int i = 0; i < width; ++i) {
                if (row_set[i] == changing_set) {
                    row_set[i] = row_set[col];
                }
            }
        }
    }

    for (int col = 0; col < width - 1; ++col) {
        if (row_set[col] != row_set[col + 1] && matrix_(height - 1, col) >= rigthWall) {
            matrix_(height - 1, col) -= rigthWall;
            const auto changing_set = row_set[col + 1];
            for (int i = 0; i < width; ++i) {
                if (row_set[i] == changing_set) {
                    row_set[i] = row_set[col];
                }
            }
        }
    }

    for (int col = 0; col < width - 1; ++col) {
        if (row_set[col] != row_set[col + 1] && matrix_(height - 1, col) >= rigthWall) {
            matrix_(height - 1, col) -= rigthWall;
        }
    }

    return matrix_;
}

// void printMaze(std::vector<std::vector<Cell>> maze) {
void Maze::PrintMaze() {
    std::cout << "Walls:" << std::endl;
    for (int i = 0; i < matrix_.GetRows(); ++i) {
        for (int j = 0; j < matrix_.GetColumns(); ++j) {
            std::cout << matrix_(i, j);
        }
        std::cout << std::endl;
    }

    std::cout << "LABIRINT:" << std::endl;
    for (int i = 0; i < matrix_.GetColumns(); ++i) {
        std::cout << " _";
    }
    std::cout << std::endl;
    for (int i = 0; i < matrix_.GetRows(); ++i) {
        std::cout << "|";
        for (int j = 0; j < matrix_.GetColumns(); ++j) {
            if (matrix_(i, j) >= bottomWall) {
                std::cout << "_";
            } else {
                std::cout << " ";
            }
            if (matrix_(i, j) >= rigthWall && matrix_(i, j) != bottomWall) {
                std::cout << "|";
            } else {
                std::cout << " ";
            }

        }
        std::cout << std::endl;
    }
    return;
} 


