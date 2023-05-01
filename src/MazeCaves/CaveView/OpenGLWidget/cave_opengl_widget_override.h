#ifndef CAVEOPENGLWIDGETOVERRIDE_H_
#define CAVEOPENGLWIDGETOVERRIDE_H_

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
    s21::Cave cave_model;
};


#endif  // CAVEOPENGLWIDGETOVERRIDE_H_
