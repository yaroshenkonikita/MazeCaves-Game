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
    auto sol = ui->mazeWidget->solver.SolveMaze(s21::Location(1,1), s21::Location(3,3), ui->mazeWidget->maze_model);
    ui->mazeWidget->solver.PrintSolution(sol);
//    ui->mazeWidget->maze_model.GetMatrix();
}

