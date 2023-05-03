#ifndef A1_MAZE_A_SRC_MAZE_CAVES_MAZE_MAZE_H_
#define A1_MAZE_A_SRC_MAZE_CAVES_MAZE_MAZE_H_

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
  void SaveToFile(std::string filename) const;
  void LoadFromFile(std::string filename);

  [[nodiscard]] const Matrix &GetMatrix() const;
  [[nodiscard]] int GetColumns() const;
  [[nodiscard]] int GetRows() const;
  [[nodiscard]] bool IsValidMaze() const;

 private:
  [[nodiscard]] int GetRandomInt() const;
  IWasHere CheckMatrix(s21::Matrix &answer, LastPosition pos = kCenter,
                       int row = 0, int column = 0) const;

  Matrix matrix_{};
};

}  // namespace s21

#endif  // A1_MAZE_A_SRC_MAZE_CAVES_MAZE_MAZE_H_
