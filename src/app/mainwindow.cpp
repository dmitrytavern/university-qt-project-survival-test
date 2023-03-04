#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow()
{
  setWindowTitle("Project Survival Test");
  setCentralWidget(new QWidget(this));
}
