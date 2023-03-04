#include "ResultLayout.h"

const QString UI_TITLE = "Тест завершено";
const QString UI_DESCRIPTION = "Результати оцінюються так:\n  <40 - завершення проекту сумнівне.\n  40-59 - середній результат. У ході проекту слід очікувати на серйозні проблеми.\n  60-79 - добрий результат. Проект, найімовірніше, буде успішним.\n  80-89 - відмінний результат. Імовірність успіху висока.\n  >90 - чудовий результат. 100% шансів на успіх.";

const QString UI_SMALLER_40 = "завершення проекту сумнівне.";
const QString UI_40_59 = "у ході проекту слід очікувати на серйозні проблеми.";
const QString UI_60_79 = "проект, найімовірніше, буде успішним.";
const QString UI_80_89 = "імовірність успіху висока";
const QString UI_BIGGER_90 = "100% шансів на успіх";

const QString UI_RESULT_SMALL_COMPANY = "Результат (мала компанія до 5 осіб): ";
const QString UI_RESULT_MIDDLE_COMPANY = "Результат (середня компанія від 5 до 20 осіб): ";
const QString UI_RESULT_BIG_COMPANY = "Результат (велика компанія понад 20 осіб): ";

ResultLayout::ResultLayout(QWidget *parent = nullptr) : QWidget(parent)
{
  QFont titleFont("Arial", 14);
  QFont resultFont("Arial", 10);
  QFont descriptionFont("Arial", 10);

  result = new QLabel();
  result->setFont(descriptionFont);
  result->setWordWrap(true);

  QLabel *title = new QLabel();
  title->setFont(titleFont);
  title->setText(UI_TITLE);
  title->setWordWrap(true);

  QLabel *description = new QLabel();
  description->setFont(descriptionFont);
  description->setText(UI_DESCRIPTION);
  description->setWordWrap(true);

  QVBoxLayout *box = new QVBoxLayout();
  box->addWidget(title);
  box->addWidget(description);
  box->addWidget(result);

  setLayout(box);
}

void ResultLayout::setResultValue(int num)
{
  QString outputMessage = "\n\n";
  QString outputReportMessage = getReportMessage(num);

  outputMessage += UI_RESULT_SMALL_COMPANY;
  outputMessage += QString::number(num * 1.5);
  outputMessage += ". Це означає, що: ";
  outputMessage += getReportMessage(num * 1.5);
  outputMessage += "\n\n";

  outputMessage += UI_RESULT_MIDDLE_COMPANY;
  outputMessage += QString::number(num * 1.25);
  outputMessage += ". Це означає, що: ";
  outputMessage += getReportMessage(num * 1.25);
  outputMessage += "\n\n";

  outputMessage += UI_RESULT_BIG_COMPANY;
  outputMessage += QString::number(num);
  outputMessage += ". Це означає, що: ";
  outputMessage += getReportMessage(num);
  outputMessage += "\n\n";

  result->setText(outputMessage);
}

QString ResultLayout::getReportMessage(float num)
{
  if (num < 40)
    return UI_SMALLER_40;
  if (40 < num && num <= 59)
    return UI_40_59;
  if (60 < num && num <= 79)
    return UI_60_79;
  if (80 < num && num <= 89)
    return UI_80_89;
  return UI_BIGGER_90;
}
