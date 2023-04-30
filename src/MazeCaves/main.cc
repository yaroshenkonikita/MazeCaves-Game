#include <QApplication>

#include "View/applicationview.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  ApplicationView w;
  w.show();
  return a.exec();
}
