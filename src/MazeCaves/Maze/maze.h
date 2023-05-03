#ifndef A1_MAZE_A_SRC_MAZE_CAVES_MAZE_MAZE_H_
#define A1_MAZE_A_SRC_MAZE_CAVES_MAZE_MAZE_H_

#include <fstream>
#include <random>
#include <vector>

#include "../Matrix/matrix_oop.h"

namespace s21 {

/**
 * @brief Обозначение стен в матрице лабиринта
 */
enum Walls {
  kNothing,     ///< Нет стен
  kRightWall,   ///< Стена справа
  kBottomWall,  ///< Стена снизу
  kBothWalls    ///< Стена справа и снизу
};

/**
 * @brief Enum для проверки лабиринта на идеальность
 */
enum IWasHere {
  kNoOneTimeWasHere,  ///< никого не было
  kWasOnce,           ///< Был один раз
  kWasManyTimes       /// Был несколько раз
};

/**
 * @brief Enum для запоминания позиции во время проверки на идеальность
 */
enum LastPosition {
  kCenter,  /// Только пришел на эту клетку
  kUp,      ///< Пришел сверху
  kLeft,    ///< Пришел слева
  kRight,   ///< Пришел справа
  kDown     ///< Пришел снизу
};

/**
 * @brief Класс для работы с матрицой лабиринта
 */
class Maze {
 public:
  /**
   * @brief Генерация лабиринта
   * @param height высота
   * @param width ширина
   * @return ссылку на матрицу лабиринта
   */
  Matrix &GenerateMaze(int height, int width);
  /**
   * @brief Сохранить лабиринт
   * @param filename путь до файла
   */
  void SaveToFile(std::string filename) const;
  /**
   * @brief Загрузить лабиринт
   * @param filename путь до файла
   */
  void LoadFromFile(std::string filename);

  [[nodiscard]] const Matrix &GetMatrix()
      const;  ///< Получить матрицу лабиринта
  [[nodiscard]] int GetColumns() const;  ///< Получить ширину лабиринта
  [[nodiscard]] int GetRows() const;  ///< Получить высоту лабиринта

 private:
  [[nodiscard]] bool IsValidMaze() const;  ///< Проверить матрицу на идеальность
  [[nodiscard]] int GetRandomInt() const;  ///< Получить случайное число
  /**
   * @brief Рекурсивная функция для прохождения всего лабиринта
   * @details Идет во все стороны от каждой точки, если есть зацикленные позиции
   * - он их найдет. А потом проходит по всему массиву и проверяет на то что он
   * везде прошел.
   * @param answer матрица отслеживания прохождения
   * @param pos позиция из которой вызвалась рекурсивная функция
   * @param row текущая строчка
   * @param column текущая колонка
   * @return результат проверки
   */
  IWasHere CheckMatrix(s21::Matrix &answer, LastPosition pos = kCenter,
                       int row = 0, int column = 0) const;

  Matrix matrix_{};  ///< Матрица лабиринта
};

}  // namespace s21

#endif  // A1_MAZE_A_SRC_MAZE_CAVES_MAZE_MAZE_H_
