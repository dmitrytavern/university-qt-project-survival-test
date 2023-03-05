#include "ResultWidget.h"

const QString UI_TITLE = "Тест завершено";
const QString UI_DESCRIPTION = "Результати оцінюються так:\n  <40 - завершення проекту сумнівне.\n  40-59 - у ході проекту слід очікувати на серйозні проблеми.\n  60-79 - проект, найімовірніше, буде успішним.\n  80-89 - імовірність успіху висока.\n  >90 - 100% шансів на успіх.";

const QString UI_SMALLER_40 = "завершення проекту сумнівне.";
const QString UI_40_59 = "у ході проекту слід очікувати на серйозні проблеми.";
const QString UI_60_79 = "проект, найімовірніше, буде успішним.";
const QString UI_80_89 = "імовірність успіху висока";
const QString UI_BIGGER_90 = "100% шансів на успіх";

const QString UI_RESULT_SMALL_COMPANY = "Результат (мала компанія до 5 осіб): ";
const QString UI_RESULT_MIDDLE_COMPANY = "Результат (середня компанія від 5 до 20 осіб): ";
const QString UI_RESULT_BIG_COMPANY = "Результат (велика компанія понад 20 осіб): ";

const QString UI_BUTTON_START = "Закінчити";

ResultWidget::ResultWidget(QWidget *parent = nullptr) : QWidget(parent)
{
  resultText = new AppPlainText();

  AppTitle *title = new AppTitle(UI_TITLE);

  AppPlainText *description = new AppPlainText(UI_DESCRIPTION);

  QPushButton *exitButton = new QPushButton(UI_BUTTON_START);

  QVBoxLayout *vbox = new QVBoxLayout();
  vbox->addWidget(title);
  vbox->addWidget(description);
  vbox->addWidget(resultText);
  vbox->addStretch();

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(exitButton, 0, Qt::AlignRight);

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addLayout(vbox, 1);
  layout->addLayout(hbox);
  layout->setAlignment(Qt::AlignTop);

  connect(exitButton, &QPushButton::clicked, exitButton, &QCoreApplication::quit);
}

void ResultWidget::setResultValue(int num)
{
  QString outputMessage = "\n";
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

  resultText->setText(outputMessage);
}

QString ResultWidget::getReportMessage(float num)
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
