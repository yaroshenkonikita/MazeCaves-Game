#include "applicationview.h"
#include "./ui_applicationview.h"

ApplicationView::ApplicationView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ApplicationView)
{
    ui->setupUi(this);
}

ApplicationView::~ApplicationView()
{
    delete ui;
}


void ApplicationView::on_generateMazePushButton_clicked()
{
    ui->mazeWidget->maze_model.GenerateMaze(ui->xSizeSpinBox->value(), ui->ySizeSpinBox->value());
}


void ApplicationView::on_actionSave_Maze_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Save file"), "name.txt",
                                                tr("Text files (*.txt)"));

    if (path.isEmpty()) { return; }

    ui->mazeWidget->maze_model.SaveToFile(path.toStdString());
    ui->mazeWidget->update();
}


void ApplicationView::on_actionLoad_Maze_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), ".",
                                                tr("Text files (*.txt)"));

    if (path.isEmpty()) { return; }

    ui->mazeWidget->maze_model.LoadFromFile(path.toStdString());
    ui->mazeWidget->update();
}


void ApplicationView::on_solveMazePushButton_clicked()
{
    int start_x = ui->xStartSpinBox->value();
    int start_y = ui->yStartSpinBox->value();
    int exit_x = ui->xExitSpinBox->value();
    int exit_y = ui->yExitSpinBox->value();
    s21::Location start_location(start_x, start_y);
    s21::Location exit_location(exit_x, exit_y);
    auto sol = ui->mazeWidget->solver.SolveMaze(start_location, exit_location,
                                                ui->mazeWidget->maze_model);
    ui->mazeWidget->solver.PrintSolution(sol);
    ui->mazeWidget->update();
//    ui->mazeWidget->maze_model.GetMatrix();
}

