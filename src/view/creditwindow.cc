#include "creditwindow.h"

#include "ui_creditwindow.h"

using namespace baseFunc;

CreditWindow::CreditWindow(QWidget *parent, Controller *c)
    : QDialog(parent), ui(new Ui::CreditWindow), controller_credit_(c) {
  ui->setupUi(this);
  ui->overpayment->setReadOnly(true);
  ui->total_payment->setReadOnly(true);
  ui->credit_amount->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^[0-9]*[.,]?[0-9]+$"), this));
  ui->period->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^[0-9]*[.,]?[0-9]+$"), this));
  ui->rate->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^[0-9]*[.,]?[0-9]+$"), this));
}

CreditWindow::~CreditWindow() { delete ui; }

bool CreditWindow::GetType() { return ui->annuit->isChecked(); }

double CreditWindow::GetPeriod() { return ui->period->text().toDouble(); }

double CreditWindow::GetCreditAmount() {
  return ui->credit_amount->text().toDouble();
}

double CreditWindow::GetRate() { return ui->rate->text().toDouble(); }

void CreditWindow::on_calculate_clicked() {
  ui->monthly_payment->clear();

  Credit::CreditResult result = controller_credit_->CalculateCredit(
      GetType(), GetCreditAmount(), GetPeriod(), GetRate());
  std::vector<double> m = result.monthly_payment;
  auto it = m.begin();
  while (it != m.end()) {
    QListWidgetItem *item = new QListWidgetItem;
    item->setText(QString::number(*it, 'd', 2));
    ui->monthly_payment->addItem(item);
    ++it;
  }
  ui->total_payment->setText((QString::number(result.total_payment, 'd', 2)));
  ui->overpayment->setText((QString::number(result.overpayment, 'd', 2)));
}
