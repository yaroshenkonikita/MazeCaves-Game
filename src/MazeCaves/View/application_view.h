#ifndef A1_MAZE_A_SRC_MAZE_CAVES_VIEW_APPLICATION_VIEW_H_
#define A1_MAZE_A_SRC_MAZE_CAVES_VIEW_APPLICATION_VIEW_H_

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

class ApplicationView : public QMainWindow {
  Q_OBJECT
 public:
  ApplicationView(QWidget *parent = nullptr);
  ~ApplicationView();

 private slots:
  void on_generateMazePushButton_clicked();
  void on_actionSave_Maze_triggered();
  void on_actionLoad_Maze_triggered();
  void on_solveMazePushButton_clicked();
  void on_actionOpenApp_triggered();

 private:
  Ui::ApplicationView *ui;
};

#endif  // A1_MAZE_A_SRC_MAZE_CAVES_VIEW_APPLICATION_VIEW_H_
