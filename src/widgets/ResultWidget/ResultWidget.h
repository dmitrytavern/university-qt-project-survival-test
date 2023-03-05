#pragma once
#include <QtWidgets>
#include "components/AppTitle/AppTitle.h"
#include "components/AppPlainText/AppPlainText.h"

class ResultWidget : public QWidget
{
private:
  AppPlainText *resultText;
  QString getReportMessage(float num);

public:
  ResultWidget(QWidget *parent);
  void setResultValue(int num);
};