#include "MainWindow.h"
#include "layouts/home/HomeLayout.h"
#include "layouts/result/ResultLayout.h"
#include "layouts/testing/TestingLayout.h"

const QString UI_WIN_TITLE = "Тест на виживання програмного проекту";

MainWindow::MainWindow() : QMainWindow()
{
  HomeLayout *homeLayout = new HomeLayout(this);

  ResultLayout *resultLayout = new ResultLayout(this);
  resultLayout->setVisible(true);
  resultLayout->setResultValue(99);

  TestingLayout *testingLayout = new TestingLayout(this);
  testingLayout->setVisible(false);
  testingLayout->setEndListener([=, this](int result)
                                { setCentralWidget(resultLayout);
                                  testingLayout->setVisible(false);
                                  resultLayout->setVisible(true);
                                  resultLayout->setResultValue(result); });

  setWindowTitle(UI_WIN_TITLE);
  setCentralWidget(homeLayout);

  QObject::connect(homeLayout->startButton, &QPushButton::clicked, [=, this]()
                   { setCentralWidget(testingLayout);
                     testingLayout->setVisible(true); });
}
