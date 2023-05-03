#ifndef A1_MAZE_A_SRC_MAZE_CAVES_CAVE_VIEW_OPENGL_WIDGET_OPENGL_WIDGET_OVERRIDE_H_
#define A1_MAZE_A_SRC_MAZE_CAVES_CAVE_VIEW_OPENGL_WIDGET_OPENGL_WIDGET_OVERRIDE_H_

#define GL_SILENCE_DEPRECATION

#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include "Cave/cave.h"

/**
 * @brief Класс наследуемый от QOpenGLWidget для переопределения функций по
 * работе с объектом
 */
class CaveOpenGLWidgetOverride : public QOpenGLWidget {
  Q_OBJECT
 public:
  CaveOpenGLWidgetOverride(QWidget *parent = nullptr);
  /**
   * @brief Перегрузка метода initializeGL для инициализации OpenGL в виджете
   */
  void initializeGL() override;
  /**
   * @brief Перегрузка метода paintGL для правильной отрисовки объекта на
   * виджете
   */
  void paintGL() override;
  s21::Cave cave_model; ///< Модель пещеры
};

#endif  // A1_MAZE_A_SRC_MAZE_CAVES_CAVE_VIEW_OPENGL_WIDGET_OPENGL_WIDGET_OVERRIDE_H_
