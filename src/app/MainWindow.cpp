#include "MainWindow.h"
#include "widgets/HomeWidget/HomeWidget.h"
#include "widgets/ResultWidget/ResultWidget.h"
#include "widgets/TestingWidget/TestingWidget.h"

MainWindow::MainWindow() : QWidget()
{
  HomeWidget *homeWidget = new HomeWidget(this);
  ResultWidget *resultWidget = new ResultWidget(this);
  TestingWidget *testingWidget = new TestingWidget(this);

  QStackedWidget *stackedWidget = new QStackedWidget(this);
  stackedWidget->addWidget(homeWidget);
  stackedWidget->addWidget(resultWidget);
  stackedWidget->addWidget(testingWidget);
  stackedWidget->setCurrentWidget(homeWidget);

  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(stackedWidget);

  QObject::connect(homeWidget, &HomeWidget::startAbout, [=, this]() {});

  QObject::connect(homeWidget, &HomeWidget::startTesting, [=, this]()
                   { stackedWidget->setCurrentWidget(testingWidget); });

  QObject::connect(testingWidget, &TestingWidget::finished, [=, this](int result)
                   { resultWidget->setResultValue(result); 
                     stackedWidget->setCurrentWidget(resultWidget); });
}
