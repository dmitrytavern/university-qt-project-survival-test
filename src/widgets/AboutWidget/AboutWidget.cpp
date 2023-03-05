#include "config.h"
#include "AboutWidget.h"
#include "components/AppTitle/AppTitle.h"
#include "components/AppPlainText/AppPlainText.h"

const QString UI_BUTTON_EXIT = "Назад";
const QString UI_TITLE = "Про программу";
const QString UI_TEXT = "Author: Dmitry Tavern\nRepository: https://github.com/dmitrytavern/university-qt-project-survival-test\nVersion: %1\nBuild: %2\nPlatform: %3\nArchitecture: %4";

AboutWidget::AboutWidget() : QWidget()
{
  AppTitle *title = new AppTitle(UI_TITLE);

  AppPlainText *description = new AppPlainText(UI_TEXT.arg(APP_VERSION).arg(APP_BUILD).arg(APP_PLATFORM).arg(APP_ARCHITECTURE));

  QPushButton *exitButton = new QPushButton(UI_BUTTON_EXIT);

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(exitButton, 0, Qt::AlignRight);

  QVBoxLayout *vbox = new QVBoxLayout();
  vbox->addWidget(title);
  vbox->addWidget(description);
  vbox->addStretch(1);

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addLayout(vbox);
  layout->addLayout(hbox);
  layout->setAlignment(Qt::AlignTop);

  connect(exitButton, &QPushButton::clicked, exitButton, [=, this]()
          { emit back(); });
}
