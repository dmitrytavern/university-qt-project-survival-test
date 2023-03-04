#pragma once
#include <QtWidgets>

struct TestingQuestionData
{
  QString title;
  QString description;
};

class TestingLayout : public QWidget
{
private:
  int currentQuestionWidget;
  int currentQuestionResult;

  QLabel *title;
  QLabel *description;

  void onPressNextHandler();
  void onInputEditLineHandler(const QString &text);
  std::function<void(int)> onEndTestingHandler;

public:
  TestingLayout(QWidget *parent);
  void setEndListener(const std::function<void(int)>);

  QLineEdit *answerLineEdit;
  QPushButton *nextButton;
};