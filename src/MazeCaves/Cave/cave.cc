#include "cave.h"

using namespace s21;

Cave::Cave() : chance_to_spawn_(0.3), birth_limit_(3), death_limit_(3) {}

Cave::Cave(double chance_to_spawn, int birth_limit, int death_limit)
    : chance_to_spawn_(chance_to_spawn),
      birth_limit_(birth_limit),
      death_limit_(death_limit) {}

int Cave::GetRandomInt() {
  std::random_device rd;
  std::default_random_engine engine(rd());
  std::uniform_real_distribution<double> dist(0.0, 1.0);
  double random_num = dist(engine);
  return random_num > chance_to_spawn_ ? 0 : 1;
}

Matrix &Cave::GenerateCave(int height, int width) {
  if (height > 50 || width > 50) {
    throw std::invalid_argument(
        "Error: Incorrect size. Maximum cave size - 50x50");
  }

  matrix_.Set(height, width);
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      matrix_(i, j) = GetRandomInt();
    }
  }
  return matrix_;
}

Matrix Cave::GetCaveMatrix() { return matrix_; }

void Cave::IterateCave() {
  Matrix old_map(matrix_);
  for (int i = 0; i < matrix_.GetRows(); ++i) {
    for (int j = 0; j < matrix_.GetColumns(); ++j) {
      int neighbours = FindNeighboursCount(old_map, i, j);
      if (matrix_(i, j) == kDead && neighbours > birth_limit_)
        matrix_(i, j) = kAlive;
      if (matrix_(i, j) == kAlive && neighbours < death_limit_)
        matrix_(i, j) = kDead;
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
      if (cur_i < 0 || cur_j < 0 || cur_i >= map.GetRows() ||
          cur_j >= map.GetColumns()) {
        count++;
      } else {
        count += map(rowPos + i, colPos + j);
      }
    }
  }
  return count;
}

void Cave::LoadFromFile(std::string filename) {
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
    throw std::invalid_argument(
        "Error: Incorrect size. Maximum cave size - 50x50");
  }

  matrix_.Set(height, width);

  for (int i = 0; i < height; ++i) {
    getline(file, line);
    for (int j = 0, k = 0; j < width; ++j, k += 2) {
      char symbol = line.at(k);
      if (symbol != '0' && symbol != '1') {
        throw std::invalid_argument(
            "Error: The file must contain only ones and zeros");
      }
      matrix_(i, j) = symbol == '1' ? 1 : 0;
    }
  }

  file.close();
}

void Cave::SaveToFile(std::string filename) {
  std::ofstream file(filename);
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

  file.close();
}

void Cave::SetChanceToSpawn(double chance_to_spawn) {
  if (chance_to_spawn > 1.0 || chance_to_spawn < 0.0) {
    throw std::invalid_argument(
        "Error: Chance to spawn value must be between 0.0 and 1.0");
  }
  chance_to_spawn_ = chance_to_spawn;
}

double Cave::GetChanceToSpawn() { return chance_to_spawn_; }

void Cave::SetBirthLimit(int birth_limit) {
  if (birth_limit > 7 || birth_limit < 0) {
    throw std::invalid_argument(
        "Error: Birth limit value must be between 0 and 7");
  }
  birth_limit_ = birth_limit;
}

int Cave::GetBirthLimit() { return birth_limit_; }

void Cave::SetDeathLimit(int death_limit) {
  if (death_limit > 7 || death_limit < 0) {
    throw std::invalid_argument(
        "Error: Death limit value must be between 0 and 7");
  }
  death_limit_ = death_limit;
}

int Cave::GetDeathLimit() { return death_limit_; }
