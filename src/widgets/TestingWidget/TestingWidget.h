#pragma once
#include <QtWidgets>
#include "components/AppTitle/AppTitle.h"
#include "components/AppPlainText/AppPlainText.h"

struct TestingQuestionData
{
  QString title;
  QString description;
};

class TestingWidget : public QWidget
{
  Q_OBJECT

public:
  TestingWidget();

  QLineEdit *answerLineEdit;
  QPushButton *nextButton;

signals:
  void finished(int result);

private:
  int currentQuestionWidget;
  int currentQuestionResult;

  AppTitle *questionTitle;
  AppPlainText *questionDescription;

  void onPressNextHandler();
  void onInputEditLineHandler(const QString &text);
  bool validateInput(const QString &text);
  void setNextQuestion();
};