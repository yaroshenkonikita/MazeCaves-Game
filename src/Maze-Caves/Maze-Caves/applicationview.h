#ifndef APPLICATIONVIEW_H
#define APPLICATIONVIEW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationView; }
QT_END_NAMESPACE

class ApplicationView : public QMainWindow
{
    Q_OBJECT

public:
    ApplicationView(QWidget *parent = nullptr);
    ~ApplicationView();

private:
    Ui::ApplicationView *ui;
};
#endif // APPLICATIONVIEW_H
