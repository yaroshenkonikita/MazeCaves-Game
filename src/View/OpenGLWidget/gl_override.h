#ifndef GL_CONTROLLER_H_
#define GL_CONTROLLER_H_

#define GL_SILENCE_DEPRECATION
#include <QColorDialog>
#include <QDialog>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include "Maze-Cave/maze.h"

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
  s21::Maze maze_model;
};

#endif  // GL_CONTROLLER_H_
