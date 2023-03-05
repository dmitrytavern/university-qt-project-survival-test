#include "MainWindow.h"
#include "widgets/HomeWidget/HomeWidget.h"
#include "widgets/AboutWidget/AboutWidget.h"
#include "widgets/ResultWidget/ResultWidget.h"
#include "widgets/TestingWidget/TestingWidget.h"

MainWindow::MainWindow() : QWidget()
{
  HomeWidget *homeWidget = new HomeWidget();
  AboutWidget *aboutWidget = new AboutWidget();
  ResultWidget *resultWidget = new ResultWidget();
  TestingWidget *testingWidget = new TestingWidget();

  QStackedWidget *stackedWidget = new QStackedWidget();
  stackedWidget->addWidget(homeWidget);
  stackedWidget->addWidget(aboutWidget);
  stackedWidget->addWidget(resultWidget);
  stackedWidget->addWidget(testingWidget);
  stackedWidget->setCurrentWidget(homeWidget);

  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(stackedWidget);

  QObject::connect(aboutWidget, &AboutWidget::back, [=, this]()
                   { stackedWidget->setCurrentWidget(homeWidget); });

  QObject::connect(homeWidget, &HomeWidget::startAbout, [=, this]()
                   { stackedWidget->setCurrentWidget(aboutWidget); });

  QObject::connect(homeWidget, &HomeWidget::startTesting, [=, this]()
                   { stackedWidget->setCurrentWidget(testingWidget); });

  QObject::connect(testingWidget, &TestingWidget::finished, [=, this](int result)
                   { resultWidget->setResultValue(result); 
                     stackedWidget->setCurrentWidget(resultWidget); });
}
