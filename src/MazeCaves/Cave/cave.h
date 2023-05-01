#ifndef MAZE_SRC_CAVE_H_
#define MAZE_SRC_CAVE_H_

 #include <iostream>
#include <fstream>
#include <random>
#include <vector>

#include "../Matrix/matrix_oop.h"

namespace s21 {

enum CellState { kDead, kAlive };

class Cave {
 public:
  Cave() : chance_to_spawn_(0.3), birth_limit_(3), death_limit_(3) {}

  Cave(double chance_to_spawn, int birth_limit, int death_limit) : chance_to_spawn_(chance_to_spawn), birth_limit_(birth_limit), death_limit_(death_limit) {}

  Matrix &GenerateCave(int height, int width);

  // Можно сделать вывод через std::cout << cave
  void PrintCave();

  void IterateCave();

  void SaveToFile(std::string filename);

  void LoadFromFile(std::string filename);

  void SetChanceToSpawn(double chance_to_spawn);

  double GetChanceToSpawn();

  void SetBirthLimit(int birth_limit);

  int GetBirthLimit();

  void SetDeathLimit(int death_limit);

  int GetDeathLimit();

  Matrix GetCaveMatrix();

 private:
  int GetRandomInt(double p);

  int FindNeighboursCount(Matrix &map, int rowPos, int colPos);

  Matrix matrix_{};

  double chance_to_spawn_{};
  int birth_limit_{};
  int death_limit_{};
};

}  // namespace s21

#endif  // MAZE_SRC_CAVE_H_
