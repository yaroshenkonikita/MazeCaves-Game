#ifndef A1_MAZE_1_SRC_MAZE_CAVES_CAVE_VIEW_CAVE_VIEW_H_
#define A1_MAZE_1_SRC_MAZE_CAVES_CAVE_VIEW_CAVE_VIEW_H_

#include <QDialog>
#include <QFileDialog>
#include <QTimer>

#include "Cave/cave.h"

namespace Ui {
class CaveView;
}

/**
 * @brief Класс представления окна пещеры
 */
class CaveView : public QDialog {
  Q_OBJECT
 public:
  explicit CaveView(QWidget *parent = nullptr);  ///< Дефолтный конструктор
  ~CaveView() override;  ///< Дефолтный деструктор

 private slots:
  void on_firstGenerationPushButton_clicked();  ///< Слот на первичную генерацию
                                                ///< пещеры
  void on_iterateGenerationPushButton_clicked();  ///< Слот на очередную
                                                  ///< итерацию пещеры
  void
  on_setSettingsPushButton_clicked();  ///< Сохранить настройки в класс Cave
  void
  on_autoGenerationPushButton_clicked();  ///< Слот на автоматическую итерацию

  void on_saveCavePushButton_clicked();

  void on_loadCavePushButton_clicked();

 private:
  Ui::CaveView *ui;  ///< Указатель на UI
};

#endif  // A1_MAZE_1_SRC_MAZE_CAVES_CAVE_VIEW_CAVE_VIEW_H_
