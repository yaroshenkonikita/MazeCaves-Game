#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include <random>

struct Cell {
    bool right_wall_{};
    bool bottom_wall_{};
};

std::vector<std::vector<Cell>> generateMaze(int width, int height) {
    // initialization the maze
    std::vector<std::vector<Cell>> maze(height, std::vector<Cell>(width));

    // initialization right and bottom walls 
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (col == width - 1) {
                maze[row][col].right_wall_ = true;
            }
            if (row == height - 1) {
                maze[row][col].bottom_wall_ = true;
            }
        }
    }

    std::vector<int> row_set;
    row_set.reserve(width);
    for (int i = 0; i < width; ++i)
        row_set.push_back(0);

    int set = 1;

    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_int_distribution<int> dist(0, 2);

    for (int row = 0; row < height; ++row) {
        
        // join cells not members of a set to their own unique set
        for (int col = 0; col < width; ++col)
            if (row_set[col] == 0) 
                row_set[col] = set++;

        
        // create right walls
        for (int col = 0; col < width - 1; ++col) {
            const auto right_wall = dist(mt);

            if ((right_wall == 1) || (row_set[col] == row_set[col + 1])) {
                maze[row][col].right_wall_ = true;
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
            if ((bottom_wall == 1) && (count_current_set != 1)) {
                maze[row][col].bottom_wall_ = true;
            }
        }

        if (row != height - 1) {
            for (int col = 0; col < width; ++col) {
                unsigned count_hole = 0;
                for (int i = 0; i < width; ++i) {
                    if ((row_set[i] == row_set[col]) && (maze[row][i].bottom_wall_ == false)) {
                        count_hole++;
                    }
                }
                if (count_hole == 0) {
                    maze[row][col].bottom_wall_ = false;
                }
            }
        }

        // create a new row
        if (row != height - 1) {
            // copy previous row
            // maze[row + 1] = maze[row];

            for (int col = 0; col < width; ++col) {
                if (maze[row][col].bottom_wall_ == true) {
                    row_set[col] = 0;
                }
                // if (col < width - 1)
                //     maze[row + 1][col].right_wall_ = false;
                // if (row < height - 1)
                //     maze[row + 1][col].bottom_wall_ = false;
            }
        }

        if (row == height - 1) {
            for (int col = 0; col < width - 1; ++col) {
                if (row_set[col] != row_set[col + 1]) {
                    maze[row][col].right_wall_ = false;
                }
            }
        }

    }
    // for (int row = 0; row < height; ++row) {
    //     for (int col = 0; col < width; ++col) {
    //         // if (col == width - 1) {
    //         //     maze[row][col].right_wall_ = true;
    //         // }
    //         if (row == height - 1) {
    //             maze[row][col].bottom_wall_ = true;
    //         }
    //     }
    // }
    return maze;
}

void printMaze(std::vector<std::vector<Cell>> maze) {
    std::cout << "Right walls:" << std::endl;
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[i].size(); ++j) {
            std::cout << maze[i][j].right_wall_;
        }
        std::cout << std::endl;
    }

    std::cout << "Bottom walls:" << std::endl;
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[i].size(); ++j) {
            std::cout << maze[i][j].bottom_wall_;
        }
        std::cout << std::endl;
    }

    std::cout << "LABIRINT:" << std::endl;
    for (int i = 0; i < maze[0].size(); ++i) {
        std::cout << " _";
    }
    std::cout << std::endl;
    for (int i = 0; i < maze.size(); ++i) {
        std::cout << "|";
        for (int j = 0; j < maze[i].size(); ++j) {
            if (maze[i][j].bottom_wall_ == true) {
                std::cout << "_";
            } else {
                std::cout << " ";
            }
            if (maze[i][j].right_wall_ == true) {
                std::cout << "|";
            } else {
                std::cout << " ";
            }

        }
        std::cout << std::endl;
    }


    return;
} 

int main() {
    std::vector<std::vector<Cell>> maze = generateMaze(10, 10);
    printMaze(maze);
    return 0;
}

