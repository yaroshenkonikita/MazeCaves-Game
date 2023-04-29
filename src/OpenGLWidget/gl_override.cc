#include "gl_override.h"

#define GL_SILENCE_DEPRECATION

QOpenGLWidgetOverride::QOpenGLWidgetOverride(QWidget* parent)
    : QOpenGLWidget{parent} {}

void QOpenGLWidgetOverride::initializeGL() {
  //Блок отвечает за проекцию
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glOrtho(0, 2, 2, 0, 1, -1);
}

void QOpenGLWidgetOverride::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0, 0, 0, 255);  // цвет заднего фона

  glBegin(GL_LINES);
  glColor3f(1.0f, 0.0f, 0.0f);
  int rows = maze_model.GetMatrix().GetRows(), columns = maze_model.GetMatrix().GetColumns();
  double width = 2.f / (columns + 1), height = 2.f / (rows + 1);
  glVertex2f(width / 2,  height / 2);
  glVertex2f(width * (columns + 0.5), height / 2);
  glVertex2f(width / 2,  height / 2);
  glVertex2f(width / 2, height * (rows + 0.5));
  for (int row = 0; row < rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      s21::Walls wall = static_cast<s21::Walls>(maze_model.GetMatrix()(row, column));
      if (wall == s21::kBottomWall || wall == s21::kBothWalls) {
        glVertex2f(width / 2 + width * (column + 1), height / 2 + height * (row + 1));
        glVertex2f(width / 2 + width * (column), height / 2 + height * (row + 1));
      }
      if (wall == s21::kRigthWall || wall == s21::kBothWalls) {
        glVertex2f(width / 2 + width * (column + 1), height / 2 + height * (row + 1));
        glVertex2f(width / 2 + width * (column + 1), height / 2 + height * (row));
      }
    }
  }
  glEnd();
  glLineWidth(2);  // толщина ребра
}
