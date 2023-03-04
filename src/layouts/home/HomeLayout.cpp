#include "HomeLayout.h"

const QString UI_TITLE = "Тест на виживання програмного проекту";
const QString UI_DESCRIPTION = "Стів Макконнелл у своїй книзі «Залишитися живим. Керівництво для менеджерів програмних проектів», наводить тест програмного проекту на виживання. Цей чек-лист із 33-х пунктів. Керівник програмного проекту повинен його періодично використовувати для внутрішнього аудиту своїх процесів.\n\nЦей тест зроблено якраз, щоб провести цей аудит.";
const QString UI_BUTTON_START = "Почати";

HomeLayout::HomeLayout(QWidget *parent = nullptr) : QWidget(parent)
{
  startButton = new QPushButton(UI_BUTTON_START);

  QLabel *title = new QLabel(this);
  QFont titleFont("Arial", 14);
  title->setText(UI_TITLE);
  title->setFont(titleFont);
  title->setWordWrap(true);

  QLabel *description = new QLabel(this);
  QFont descriptionFont("Arial", 10);
  description->setText(UI_DESCRIPTION);
  description->setFont(descriptionFont);
  description->setWordWrap(true);

  QVBoxLayout *box = new QVBoxLayout();
  box->addWidget(title);
  box->addWidget(description);
  box->addWidget(startButton);

  setLayout(box);
}
