#include "cave_opengl_widget_override.h"

CaveOpenGLWidgetOverride::CaveOpenGLWidgetOverride(QWidget *parent)
    : QOpenGLWidget{parent} {}

void CaveOpenGLWidgetOverride::initializeGL() {
  //Блок отвечает за проекцию
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glOrtho(0, 2, 2, 0, 1, -1);
  cave_model.GenerateCave(50, 50);
}

void CaveOpenGLWidgetOverride::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(255, 255, 255, 255);  // цвет заднего фона

  glBegin(GL_QUADS);
  glColor3f(0.0f, 0.0f, 0.0f);
  auto cave_matrix = cave_model.GetCaveMatrix();
  int rows = cave_matrix.GetRows(), columns = cave_matrix.GetColumns();
  double width = 2.f / (columns + 1), height = 2.f / (rows + 1);
  for (int row = 0; row < rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      if (static_cast<s21::CellState>(cave_matrix(row, column)) ==
          s21::kAlive) {
        glVertex2f(width * (column + 0.5), height * (row + 0.5));
        glVertex2f(width * (column + 0.5), height * (row + 1.5));
        glVertex2f(width * (column + 1.5), height * (row + 1.5));
        glVertex2f(width * (column + 1.5), height * (row + 0.5));
      }
    }
  }
  glEnd();
}
