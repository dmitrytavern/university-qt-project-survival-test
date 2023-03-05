#include <QApplication>
#include "MainWindow.h"

const QString UI_WIN_TITLE = "Тест на виживання програмного проекту";

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  MainWindow window;

  window.setFixedSize(500, 340);
  window.setWindowTitle(UI_WIN_TITLE);
  window.show();

  return app.exec();
}