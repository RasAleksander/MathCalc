#ifndef MODEL_CREDIT_H_
#define MODEL_CREDIT_H_

#include <cmath>
#include <vector>

namespace baseFunc {
class Credit {
 public:
  typedef struct {
    std::vector<double> monthly_payment;
    double total_payment;
    double overpayment;
  } CreditResult;

  Credit() = default;
  ~Credit() = default;
  void CalculateAnnuityCredit(double credit_amount, double period, double rate);
  void CalculateDifferentiatedCredit(double credit_amount, double period,
                                     double rate);
  CreditResult GetResultValues();

 private:
  void ClearData();
  CreditResult result_;
};
}  // namespace baseFunc

#endif  // _MODEL_CREDIT_H_
