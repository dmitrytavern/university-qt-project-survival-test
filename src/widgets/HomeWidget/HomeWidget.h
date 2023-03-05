#pragma once
#include <QtWidgets>

class HomeWidget : public QWidget
{
  Q_OBJECT

public:
  HomeWidget(QWidget *parent);

signals:
  void startTesting();
  void startAbout();
};