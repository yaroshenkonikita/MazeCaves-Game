#ifndef A1_MAZE_1_SRC_MAZE_CAVES_MATRIX_MATRIX_H_
#define A1_MAZE_1_SRC_MAZE_CAVES_MATRIX_MATRIX_H_

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>

namespace s21 {

class Matrix {
 public:
  Matrix();
  Matrix(int rows, int columns);
  Matrix(const Matrix &other);
  Matrix(Matrix &&other);
  ~Matrix();

  int GetColumns() const noexcept;
  int GetRows() const noexcept;
  int Size() const noexcept;

  void Set(int size_rows, int size_columns);
  void SetRows(int size_rows);
  void SetColumns(int size_columns);

  double &operator()(const int rows, const int columns);
  const double &operator()(const int rows, const int columns) const;

  Matrix &operator+=(const Matrix &other);
  Matrix &operator*=(const Matrix &other);
  Matrix &operator*=(double num);
  Matrix &operator-=(const Matrix &other);

  bool operator==(const Matrix &other) const;
  bool operator!=(const Matrix &other) const;

  [[nodiscard]] Matrix operator+(const Matrix &other) const;
  [[nodiscard]] Matrix operator-(const Matrix &other) const;
  [[nodiscard]] Matrix operator*(const Matrix &other) const;

  Matrix &operator=(const Matrix &other);
  Matrix &operator=(Matrix &&other);

  bool EqMatrix(const Matrix &other) const;

  void SumMatrix(const Matrix &other);
  void SubMatrix(const Matrix &other);
  void MulNumber(double num);
  void MulMatrix(const Matrix &other);

  [[nodiscard]] Matrix Transpose() const;
  [[nodiscard]] Matrix MinorMatrix(int discard_row, int discard_column) const;
  [[nodiscard]] Matrix CalcComplements() const;
  double Determinant() const;
  [[nodiscard]] Matrix InverseMatrix() const;

 private:
  double *matrix_;
  int rows_, columns_;

  void CheckEqSize(const Matrix &other) const;
};
std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
Matrix operator*(double num, Matrix other);
Matrix operator*(Matrix other, double num);

}  // namespace s21

#endif  // A1_MAZE_1_SRC_MAZE_CAVES_MATRIX_MATRIX_H_
