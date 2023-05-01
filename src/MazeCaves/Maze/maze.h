#ifndef MAZE_SRC_MAZE_H_
#define MAZE_SRC_MAZE_H_

// #include <iostream>
#include <fstream>
#include <random>
#include <vector>

#include "../Matrix/matrix_oop.h"

namespace s21 {

enum Walls { kNothing, kRightWall, kBottomWall, kBothWalls };

enum IWasHere { kNoOneTimeWasHere, kWasOnce, kWasManyTimes };

enum LastPosition { kCenter, kUp, kLeft, kRight, kDown };

class Maze {
 public:
  Matrix &GenerateMaze(int height, int width);

  // Можно сделать вывод через std::cout << maze
//  void PrintMaze() const;

  void SaveToFile(std::string filename) const;

  void LoadFromFile(std::string filename);

  const Matrix &GetMatrix() const;
  int GetColumns() const;
  int GetRows() const;
  bool IsValidMaze() const;

 private:
  int GetRandomInt() const;
  IWasHere CheckMatrix(s21::Matrix &answer, LastPosition pos = kCenter, int row = 0, int column = 0) const;

  Matrix matrix_{};
};

}  // namespace s21

#endif  // MAZE_SRC_MAZE_H_
