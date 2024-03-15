#include "../model/credit.h"

// Аннуиентный
void baseFunc::Credit::CalculateAnnuityCredit(double credit_amount,
                                              double period, double rate) {
  ClearData();
  double mounthly_rate = rate / 12.0 / 100.0;
  result_.monthly_payment.push_back(credit_amount * mounthly_rate *
                                    powl(1 + mounthly_rate, period) /
                                    (powl(1 + mounthly_rate, period) - 1));
  result_.total_payment = result_.monthly_payment.back() * period;
  result_.overpayment = result_.total_payment - credit_amount;
}

// Диффиренцированный
void baseFunc::Credit::CalculateDifferentiatedCredit(double credit_amount,
                                                     double period,
                                                     double rate) {
  ClearData();
  double mounthly_rate = rate / 12.0 / 100.0;
  for (int i = 0; i < period; ++i) {
    result_.monthly_payment.push_back(
        credit_amount / period +
        (credit_amount - credit_amount / period * i) * mounthly_rate);
    result_.total_payment += result_.monthly_payment.back();
  }
  result_.overpayment = result_.total_payment - credit_amount;
}

// Метод для получения результатов расчета кредита
// Вынесен отдельно, чтобы предоставить интерфейс для получения результатов
// расчета кредита извне класса Credit (в соответствии с принципами
// инкапсуляции)
baseFunc::Credit::CreditResult baseFunc::Credit::GetResultValues() {
  return result_;
}

// Метод для очистки данных перед новым расчетом
void baseFunc::Credit::ClearData() { result_ = {}; }