#ifndef A1_MAZE_A_SRC_MAZE_CAVES_CAVE_VIEW_CAVE_VIEW_H_
#define A1_MAZE_A_SRC_MAZE_CAVES_CAVE_VIEW_CAVE_VIEW_H_

#include <QDialog>
#include <QTimer>

#include "Cave/cave.h"

namespace Ui {
class CaveView;
}

class CaveView : public QDialog {
  Q_OBJECT
 public:
  explicit CaveView(QWidget *parent = nullptr);
  ~CaveView() override;

 private slots:
  void on_firstGenerationPushButton_clicked();
  void on_iterateGenerationPushButton_clicked();
  void on_setSettingsPushButton_clicked();
  void on_autoGenerationPushButton_clicked();

 private:
  Ui::CaveView *ui;
};

#endif  // A1_MAZE_A_SRC_MAZE_CAVES_CAVE_VIEW_CAVE_VIEW_H_
