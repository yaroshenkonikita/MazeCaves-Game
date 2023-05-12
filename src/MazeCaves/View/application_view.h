#ifndef A1_MAZE_1_SRC_MAZE_CAVES_VIEW_APPLICATION_VIEW_H_
#define A1_MAZE_1_SRC_MAZE_CAVES_VIEW_APPLICATION_VIEW_H_

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <stdexcept>

#include "CaveView/cave_view.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ApplicationView;
}
QT_END_NAMESPACE
/**
 * @brief Класс представления основного приложения(Лабиринт-Пещера)
 */
class ApplicationView : public QMainWindow {
  Q_OBJECT
 public:
  ApplicationView(QWidget *parent = nullptr);  ///< Дефолтный конструктор
  ~ApplicationView();  ///< Дефолтный деструктор

 private slots:
  void on_generateMazePushButton_clicked();  ///< Слот генерации лабиринта
  void on_actionSave_Maze_triggered();  ///< Слот сохранения лабиринта
  void on_actionLoad_Maze_triggered();  ///< Слот загрузки лабиринта
  void on_solveMazePushButton_clicked();  ///< Слот решения лабиринта
  void on_actionOpenApp_triggered();  ///< Слот открытия пещеры

 private:
  Ui::ApplicationView *ui;  ///< Указатель на UI
};

#endif  // A1_MAZE_1_SRC_MAZE_CAVES_VIEW_APPLICATION_VIEW_H_
