#pragma once
#include <QtWidgets>

class AboutWidget : public QWidget
{
  Q_OBJECT

public:
  AboutWidget();

signals:
  void back();
};