#include "AppTitle.h"

AppTitle::AppTitle() : QLabel()
{
  QFont font("Arial", 12);
  this->setFont(font);
  this->setWordWrap(true);
}

AppTitle::AppTitle(QString title) : QLabel()
{
  QFont font("Arial", 12);
  this->setFont(font);
  this->setText(title);
  this->setWordWrap(true);
}
