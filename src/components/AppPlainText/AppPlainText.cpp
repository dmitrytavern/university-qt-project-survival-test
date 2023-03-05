#include "AppPlainText.h"

AppPlainText::AppPlainText() : QLabel()
{
  QFont font("Arial", 10);
  this->setFont(font);
  this->setWordWrap(true);
}

AppPlainText::AppPlainText(QString text) : QLabel()
{
  QFont font("Arial", 10);
  this->setFont(font);
  this->setText(text);
  this->setWordWrap(true);
}
