#ifndef A1_MAZE_1_SRC_MAZE_CAVES_CAVE_CAVE_H_
#define A1_MAZE_1_SRC_MAZE_CAVES_CAVE_CAVE_H_

#include <fstream>
#include <iostream>
#include <random>
#include <vector>

#include "../Matrix/matrix_oop.h"

namespace s21 {

enum CellState { kDead, kAlive };  // Содержимое пещеры
/**
 * @brief Класс для работы с матрицой пещеры
 */
class Cave {
 public:
  Cave();  ///< Дефолтный конструктор
  /**
   * @brief Параметрезированный конструктор
   * @param chance_to_spawn шанс на спавн
   * @param birth_limit лимит на рождение
   * @param death_limit лимит на смерть
   */
  Cave(double chance_to_spawn, int birth_limit, int death_limit);
  ~Cave() = default;  ///< Дефолтный деструктор

  /**
   * @brief Первичная генерация пещеры
   * @param height высота пещеры
   * @param width ширина пещеры
   * @return ссылку натрицу пещеры
   */
  Matrix &GenerateCave(int height, int width);
  void IterateCave();  ///< Последующие итерации после первичной генерации
  /**
   * @brief Сохранить пещеру в файл
   * @param filename путь до файла
   */
  void SaveToFile(std::string filename);
  /**
   * @brief Загрузить пещеру из файла
   * @param filename путь до файла
   */
  void LoadFromFile(std::string filename);

  /**
   * @brief Установить шанс на спавн
   * @param chance_to_spawn шанс на спавн
   */
  void SetChanceToSpawn(double chance_to_spawn);
  /**
   * @brief Установить лимит на рождение
   * @param birth_limit лимит на рождение
   */
  void SetBirthLimit(int birth_limit);
  /**
   * @brief Установить лимит на смерть
   * @param death_limit лимит на смерть
   */
  void SetDeathLimit(int death_limit);
  double GetChanceToSpawn();  ///< Получить шанс на спавн
  int GetBirthLimit();  ///< Получить лимит на рождение
  int GetDeathLimit();  ///< Получить линит на смерть
  Matrix GetCaveMatrix();  ///< Получить матрицу пещеры

 private:
  int GetRandomInt();  ///< Получить состояние клетки от шанса на спавн
  /**
   * @brief Посчитать соседей
   * @param map пещера
   * @param rowPos позиция Y
   * @param colPos позиция X
   * @return количество соседей
   */
  int FindNeighboursCount(Matrix &map, int rowPos, int colPos);

  Matrix matrix_{};           ///< Матрица пещеры
  double chance_to_spawn_{};  ///< Шанс на спавн
  int birth_limit_{};         ///< Лимит на рождение
  int death_limit_{};         ///< Лимит на смерть
};

}  // namespace s21

#endif  // A1_MAZE_1_SRC_MAZE_CAVES_CAVE_CAVE_H_
