#pragma once
#include <QtWidgets>

class HomeWidget : public QWidget
{
  Q_OBJECT

public:
  HomeWidget();

signals:
  void startTesting();
  void startAbout();
};