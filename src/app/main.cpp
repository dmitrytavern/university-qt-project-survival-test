#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  MainWindow window;

  window.setFixedSize(600, 400);
  window.show();

  return app.exec();
}