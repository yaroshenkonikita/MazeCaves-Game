#include "maze.h"

using namespace s21;

int Maze::GetRandomInt() const {
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_real_distribution<double> dist(0, 2);
    return dist(engine);
}

Matrix &Maze::GenerateMaze(int height, int width) {
    if (height > 50 || width > 50) {
        throw std::invalid_argument("Error: Incorrect size. Maximum maze size - 50x50");
    }

    // initialization the maze
    matrix_.Set(height, width);

    // initialization right and bottom walls 
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (col == width - 1) {
                matrix_(row, col) += kRigthWall;
            }
            if (row == height - 1) {
                matrix_(row, col) += kBottomWall;
            }
        }
    }

    std::vector<int> row_set;
    row_set.reserve(width);
    for (int i = 0; i < width; ++i)
        row_set.push_back(0);

    int set = 1;

    for (int row = 0; row < height - 1; ++row) {
        
        // join cells not members of a set to their own unique set
        for (int col = 0; col < width; ++col) {
            if (row_set[col] == 0) {
                row_set[col] = set++;                
            }
        }

        
        // create right walls
        for (int col = 0; col < width - 1; ++col) {
            const auto right_wall = GetRandomInt();

            if ((right_wall) || (row_set[col] == row_set[col + 1])) {
                matrix_(row, col) += kRigthWall;
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
            const auto bottom_wall = GetRandomInt();
            unsigned int count_current_set = 0;
            for (int i = 0; i < width; ++i) {
                if (row_set[col] == row_set[i]) {
                    count_current_set++;
                }
            }
            if ((bottom_wall) && (count_current_set != 1)) {
                matrix_(row, col) += kBottomWall;
            }
        }

        if (row != height - 1) {
            for (int col = 0; col < width; ++col) {
                unsigned count_hole = 0;
                for (int i = 0; i < width; ++i) {
                    if ((row_set[i] == row_set[col]) && (matrix_(row, i) < kBottomWall)) {
                        count_hole++;
                    }
                }
                if (count_hole == 0 && matrix_(row, col) >= kBottomWall) {
                    matrix_(row, col) -= kBottomWall;
                }
            }
        }

        // create a new row
        if (row != height - 1) {
            for (int col = 0; col < width; ++col) {
                if (matrix_(row, col) >= kBottomWall) {
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
        const auto right_wall = GetRandomInt();

        if ((right_wall) || (row_set[col] == row_set[col + 1])) {
            matrix_(height - 1, col) += kRigthWall;
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
        if (row_set[col] != row_set[col + 1] && matrix_(height - 1, col) >= kRigthWall) {
            matrix_(height - 1, col) -= kRigthWall;
            const auto changing_set = row_set[col + 1];
            for (int i = 0; i < width; ++i) {
                if (row_set[i] == changing_set) {
                    row_set[i] = row_set[col];
                }
            }
        }
    }

    for (int col = 0; col < width - 1; ++col) {
        if (row_set[col] != row_set[col + 1] && matrix_(height - 1, col) >= kRigthWall) {
            matrix_(height - 1, col) -= kRigthWall;
        }
    }

    return matrix_;
}

void Maze::PrintMaze() const {
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
            if (matrix_(i, j) >= kBottomWall) {
                std::cout << "_";
            } else {
                std::cout << " ";
            }
            if (matrix_(i, j) >= kRigthWall && matrix_(i, j) != kBottomWall) {
                std::cout << "|";
            } else {
                std::cout << " ";
            }

        }
        std::cout << std::endl;
    }
} 

void Maze::LoadFromFile(std::string filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::invalid_argument("Error: The file does not exist");
    }
    std::string line;
    getline(file, line);
    size_t temp_pos = 0;
    int height = std::stoi(line, &temp_pos);
    int width = std::stoi(line.substr(temp_pos + 1), &temp_pos);
    if (height > 50 || width > 50) {
        throw std::invalid_argument("Error: Incorrect size. Maximum maze size - 50x50");
    }
    
    for (int i = 0; i < matrix_.GetRows(); ++i) {
        for (int j = 0; j < matrix_.GetColumns(); ++j) {
            matrix_(i, j) = 0;
        }
    }

    matrix_.Set(height, width);

    for (int i = 0; i < height; ++i) {
        getline(file, line);
        for (int j = 0, k = 0; j < width; ++j, k += 2) {
            char symbol = line.at(k);
            if (symbol != '0' && symbol != '1') {
                throw std::invalid_argument("Error: The file must contain only ones and zeros");
            }
            if (symbol == '1') {
                matrix_(i, j) += kRigthWall;
            }
        }
    }

    getline(file, line);

    for (int i = 0; i < height; ++i) {
        getline(file, line);
        for (int j = 0, k = 0; j < width; ++j, k += 2) {
            char symbol = line.at(k);
            if (symbol != '0' && symbol != '1') {
                throw std::invalid_argument("Error: The file must contain only ones and zeros");
            }
            if (symbol == '1') {
                matrix_(i, j) += kBottomWall;
            }
        }
    }   

    file.close();
}

void Maze::SaveToFile(std::string filename) const {
    std::ofstream file(filename);
    if (!file) {
        throw std::invalid_argument("Error: The file does not exist");
    }
    int height = matrix_.GetRows();
    int width = matrix_.GetColumns();

    file << height << ' ' << width << '\n';

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (matrix_(i, j) == kRigthWall || matrix_(i, j) == kBothWalls) {
                file << 1;
            } else {
                file << 0;
            }
            if (j != width - 1) {
                file << " ";
            }
        }
        file << '\n';
    }

    file << '\n';

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (matrix_(i, j) >= kBottomWall) {
                file << 1;
            } else {
                file << 0;
            }
            if (j != width - 1) {
                file << " ";
            }
        }
        if (i != height - 1) {
            file << '\n';
        }
    }

    file.close();
}

const Matrix &Maze::GetMatrix() const {
    return matrix_;
}
