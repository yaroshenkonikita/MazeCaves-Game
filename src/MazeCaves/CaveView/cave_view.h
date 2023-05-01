#ifndef CAVEVIEW_H
#define CAVEVIEW_H

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
  ~CaveView();

 private slots:
  void on_firstGenerationPushButton_clicked();

  void on_iterateGenerationPushButton_clicked();

  void on_setSettingsPushButton_clicked();

  void on_autoGenerationPushButton_clicked();

 private:
  Ui::CaveView *ui;
};

#endif  // CAVEVIEW_H
