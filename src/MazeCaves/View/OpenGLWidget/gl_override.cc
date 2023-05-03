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
}

void QOpenGLWidgetOverride::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0, 0, 0, 255);  // цвет заднего фона

  glBegin(GL_LINES);
  glColor3f(1.0f, 0.0f, 0.0f);
  int rows = maze_model.GetRows(), columns = maze_model.GetColumns();
  double width = 2.f / static_cast<float>(columns + 1),
         height = 2.f / static_cast<float>(rows + 1);
  glVertex2f(static_cast<GLfloat>(width / 2.f),
             static_cast<GLfloat>(height / 2.f));
  glVertex2f(static_cast<GLfloat>(width * (columns + 0.5)),
             static_cast<GLfloat>(height / 2.f));
  glVertex2f(static_cast<GLfloat>(width / 2.f),
             static_cast<GLfloat>(height / 2.f));
  glVertex2f(static_cast<GLfloat>(width / 2.f),
             static_cast<GLfloat>(height * (rows + 0.5)));
  for (int row = 0; row < rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      auto wall = static_cast<s21::Walls>(maze_model.GetMatrix()(row, column));
      if (wall == s21::kBottomWall || wall == s21::kBothWalls) {
        glVertex2f(static_cast<GLfloat>(width * (column + 1.5)),
                   static_cast<GLfloat>(height * (row + 1.5)));
        glVertex2f(static_cast<GLfloat>(width * (column + 0.5)),
                   static_cast<GLfloat>(height * (row + 1.5)));
      }
      if (wall == s21::kRightWall || wall == s21::kBothWalls) {
        glVertex2f(static_cast<GLfloat>(width * (column + 1.5)),
                   static_cast<GLfloat>(height * (row + 1.5)));
        glVertex2f(static_cast<GLfloat>(width * (column + 1.5)),
                   static_cast<GLfloat>(height * (row + 0.5)));
      }
    }
  }
  glEnd();

  glBegin(GL_LINE_STRIP);
  glColor3f(0.0f, 1.0f, 0.0f);
  for (auto& i : escape_path) {
    glVertex2f(static_cast<GLfloat>(width * (i.x + 1)),
               static_cast<GLfloat>(height * (i.y + 1)));
  }
  glEnd();
  glLineWidth(2);  // толщина ребра
}
