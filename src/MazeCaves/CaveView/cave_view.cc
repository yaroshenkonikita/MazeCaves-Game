#include "cave_view.h"
#include "ui_cave_view.h"

CaveView::CaveView(QWidget *parent) :
    QDialog(parent),
    timer_(new QTimer),
    ui(new Ui::CaveView) {
    ui->setupUi(this);

    connect(timer_, SIGNAL(timeout()), this, SLOT(generate_iteration()));
}

CaveView::~CaveView() {
    delete ui;
    delete timer_;
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
//    for (int i = 0; i < count; ++i) {
//        std::this_thread::sleep_for(std::chrono::milliseconds(pause_duration));
//        on_iterateGenerationPushButton_clicked();
//    }

    timer_->start(pause_duration);
}

void CaveView::generate_iteration()
{
    int count_m = ui->countIterationSpinBox->value();
    if (count < count_m) {
        ui->caveWidget->cave_model.IterateCave();
        ui->caveWidget->update();
        count++;
    } else {
        count = 0;
        timer_->stop();
    }

}
