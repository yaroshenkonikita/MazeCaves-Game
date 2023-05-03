#ifndef A1_MAZE_A_SRC_MAZE_CAVES_VIEW_OPENGL_WIDGET_GL_OVERRIDE_H_
#define A1_MAZE_A_SRC_MAZE_CAVES_VIEW_OPENGL_WIDGET_GL_OVERRIDE_H_

#define GL_SILENCE_DEPRECATION
#include <QColorDialog>
#include <QDialog>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include "Maze/maze.h"
#include "Maze/maze_solver.h"

/**
 * @brief Класс наследуемый от QOpenGLWidget для переопределения функций по
 * работе с объектом
 */
class QOpenGLWidgetOverride : public QOpenGLWidget {
  Q_OBJECT
 public:
  QOpenGLWidgetOverride(QWidget *parent = nullptr);  ///< Дефолтный конструктор

  /**
   * @brief Перегрузка метода initializeGL для инициализации OpenGL в виджете
   */
  void initializeGL() override;
  /**
   * @brief Перегрузка метода paintGL для правильной отрисовки объекта на
   * виджете
   */
  void paintGL() override;
  s21::Maze maze_model;  ///< Модель лабиринта
  std::vector<s21::Location>
      escape_path;  ///< Вектор для выхода из заданных позиций
};

#endif  // A1_MAZE_A_SRC_MAZE_CAVES_VIEW_OPENGL_WIDGET_GL_OVERRIDE_H_
