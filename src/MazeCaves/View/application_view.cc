#include "application_view.h"

#include "./ui_application_view.h"

ApplicationView::ApplicationView(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ApplicationView) {
  ui->setupUi(this);
}

ApplicationView::~ApplicationView() { delete ui; }

void ApplicationView::on_generateMazePushButton_clicked() {
  ui->mazeWidget->escape_path.clear();
  ui->mazeWidget->maze_model.GenerateMaze(ui->xSizeSpinBox->value(),
                                          ui->ySizeSpinBox->value());
  ui->mazeWidget->update();
}

void ApplicationView::on_actionSave_Maze_triggered() {
  QString path = QFileDialog::getSaveFileName(this, tr("Save file"), "name.txt",
                                              tr("Text files (*.txt)"));

  if (path.isEmpty()) {
    return;
  }

  ui->mazeWidget->maze_model.SaveToFile(path.toStdString());
  ui->mazeWidget->update();
}

void ApplicationView::on_actionLoad_Maze_triggered() {
  QString path = QFileDialog::getOpenFileName(this, tr("Open File"), ".",
                                              tr("Text files (*.txt)"));

  if (path.isEmpty()) {
    return;
  }
  ui->mazeWidget->escape_path.clear();
  ui->mazeWidget->maze_model.LoadFromFile(path.toStdString());
  ui->mazeWidget->update();
}

void ApplicationView::on_solveMazePushButton_clicked() {
  s21::Location start_location(ui->xStartSpinBox->value() - 1,
                               ui->yStartSpinBox->value() - 1);
  s21::Location exit_location(ui->xExitSpinBox->value() - 1,
                              ui->yExitSpinBox->value() - 1);
  try {
    ui->mazeWidget->escape_path = s21::MazeSolver::SolveMaze(
        start_location, exit_location, ui->mazeWidget->maze_model);
  } catch (std::exception &e) {
    QMessageBox::warning(this, "Error", e.what());
  }
  ui->mazeWidget->update();
}

void ApplicationView::on_actionOpenApp_triggered() {
  CaveView a;
  a.exec();
}
