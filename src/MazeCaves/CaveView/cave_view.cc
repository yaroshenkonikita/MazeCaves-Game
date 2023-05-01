#include "cave_view.h"
#include "ui_cave_view.h"

CaveView::CaveView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CaveView) {
    ui->setupUi(this);
}

CaveView::~CaveView() {
    delete ui;
}

void CaveView::on_firstGenerationPushButton_clicked() {
    ui->caveWidget->cave_model.GenerateCave(ui->xSizeSpinBox->value(), ui->ySizeSpinBox->value());
    ui->caveWidget->update();
}

void CaveView::on_iterateGenerationPushButton_clicked() {
    ui->caveWidget->cave_model.IterateCave();
    ui->caveWidget->update();
}

void CaveView::on_setSettingsPushButton_clicked() {
    ui->caveWidget->cave_model.SetChanceToSpawn(ui->chanceSpawnDoubleSpinBox->value());
    ui->caveWidget->cave_model.SetBirthLimit(ui->birthLimitSpinBox->value());
    ui->caveWidget->cave_model.SetDeathLimit(ui->deathLimitSpinBox->value());
}

void CaveView::on_autoGenerationPushButton_clicked() {
    int count = ui->countIterationSpinBox->value();
    int pause_duration = ui->pauseDurationSpinBox->value();
    on_firstGenerationPushButton_clicked();
    for (int i = 0; i < count; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(pause_duration));
        on_iterateGenerationPushButton_clicked();
    }
}
