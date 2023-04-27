#include "gl_override.h"

#define GL_SILENCE_DEPRECATION

QOpenGLWidgetOverride::QOpenGLWidgetOverride(QWidget* parent)
    : QOpenGLWidget{parent} {}

void QOpenGLWidgetOverride::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LINE_STIPPLE);
  glOrtho(0, 1, 1, 0, 1, -1);
  //Блок отвечает за проекцию
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void QOpenGLWidgetOverride::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(settings.background_color[0], settings.background_color[1],
               settings.background_color[2],
               settings.background_color[3]);  // цвет заднего фона

  glColor3d(settings.edge_color[0], settings.edge_color[1],
            settings.edge_color[2]);
  glLineWidth(2);  // толщина ребра
}
