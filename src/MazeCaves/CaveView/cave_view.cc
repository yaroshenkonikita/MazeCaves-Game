#include "cave_view.h"

#include "ui_cave_view.h"

CaveView::CaveView(QWidget* parent) : QDialog(parent), ui(new Ui::CaveView) {
  ui->setupUi(this);
}

CaveView::~CaveView() { delete ui; }

void CaveView::on_firstGenerationPushButton_clicked() {
  ui->caveWidget->cave_model.GenerateCave(ui->xSizeSpinBox->value(),
                                          ui->ySizeSpinBox->value());
  ui->caveWidget->update();
}

void CaveView::on_iterateGenerationPushButton_clicked() {
  ui->caveWidget->cave_model.IterateCave();
  ui->caveWidget->update();
}

void CaveView::on_setSettingsPushButton_clicked() {
  ui->caveWidget->cave_model.SetChanceToSpawn(
      ui->chanceSpawnDoubleSpinBox->value());
  ui->caveWidget->cave_model.SetBirthLimit(ui->birthLimitSpinBox->value());
  ui->caveWidget->cave_model.SetDeathLimit(ui->deathLimitSpinBox->value());
}

void CaveView::on_autoGenerationPushButton_clicked() {
  ui->autoGenerationPushButton->setEnabled(false);
  int remaining_iterations = ui->countIterationSpinBox->value();
  QTimer* timer = new QTimer(this);
  timer->setInterval(ui->pauseDurationSpinBox->value());

  auto check_iterations = [this, timer, remaining_iterations]() mutable {
    on_iterateGenerationPushButton_clicked();
    if (--remaining_iterations <= 0) {
      timer->stop();
      delete timer;
      ui->autoGenerationPushButton->setEnabled(true);
    }
  };

  connect(timer, &QTimer::timeout, this, check_iterations);
  timer->start();
}
