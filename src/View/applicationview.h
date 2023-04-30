#ifndef APPLICATIONVIEW_H
#define APPLICATIONVIEW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <stdexcept>

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

 private:
  Ui::ApplicationView *ui;
};
#endif  // APPLICATIONVIEW_H
