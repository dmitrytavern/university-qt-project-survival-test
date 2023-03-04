#pragma once
#include <QtWidgets>

class ResultLayout : public QWidget
{
private:
  QLabel *result;
  QString getReportMessage(float num);

public:
  ResultLayout(QWidget *parent);
  void setResultValue(int num);
};