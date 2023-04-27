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
  maze_model.GenerateMaze(10, 10);
  update();
}

void QOpenGLWidgetOverride::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0, 0, 0, 255);  // цвет заднего фона

  glBegin(GL_LINES);
  glColor3f(1.0f, 0.0f, 0.0f);
  glLineWidth(2);  // толщина ребра
  int rows = maze_model.GetMatrix().GetRows(), columns = maze_model.GetMatrix().GetColumns();
  double width = 2.f / (double)(columns + 2), height = 2.f / (double)(rows + 2);
  glVertex2f(width,  height);
  glVertex2f(width * (rows + 1), height);
  glVertex2f(width,  height);
  glVertex2f(width, height * (columns + 1));
  for (int row = 0; row < maze_model.GetMatrix().GetRows(); ++row) {
    for (int column = 0; column < maze_model.GetMatrix().GetColumns(); ++column) {
      glVertex2f(width * (row + 1), height * (column + 2));
      glVertex2f(width * (row + 2), height * (column + 2));
      glVertex2f(width * (row + 2), height * (column + 2));
      glVertex2f(width * (row + 2), height * (column + 1));
//      glVertex2f(width * row, height * (column + 2));
//      glVertex2f(width * (row + 2), height * (columns + 2));
    }
  }
  glEnd();
}
