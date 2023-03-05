#include "HomeWidget.h"
#include "components/AppTitle/AppTitle.h"
#include "components/AppPlainText/AppPlainText.h"

const QString UI_TITLE = "Тест на виживання програмного проекту";
const QString UI_DESCRIPTION = "Стів Макконнелл у своїй книзі «Залишитися живим. Керівництво для менеджерів програмних проектів», наводить тест програмного проекту на виживання. Цей чек-лист із 33-х пунктів. Керівник програмного проекту повинен його періодично використовувати для внутрішнього аудиту своїх процесів.\n\nЦей тест зроблено якраз, щоб провести цей аудит.";
const QString UI_BUTTON_START = "Почати";
const QString UI_BUTTON_ABOUT = "Про программу";

HomeWidget::HomeWidget(QWidget *parent = nullptr) : QWidget(parent)
{
  AppTitle *title = new AppTitle(UI_TITLE);

  AppPlainText *description = new AppPlainText(UI_DESCRIPTION);

  QPushButton *startButton = new QPushButton(UI_BUTTON_START);

  QPushButton *aboutButton = new QPushButton(UI_BUTTON_ABOUT);

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(aboutButton, 1, Qt::AlignRight);
  hbox->addWidget(startButton, 0);

  QVBoxLayout *vbox = new QVBoxLayout();
  vbox->addWidget(title);
  vbox->addWidget(description);
  vbox->addStretch(1);

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addLayout(vbox);
  layout->addLayout(hbox);
  layout->setAlignment(Qt::AlignTop);

  connect(startButton, &QPushButton::clicked, startButton, [=, this]()
          { emit startTesting(); });

  connect(aboutButton, &QPushButton::clicked, aboutButton, [=, this]()
          { emit startAbout(); });
}
