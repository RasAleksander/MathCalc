#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_

#include <vector>

#include "../model/calculator.h"
#include "../model/credit.h"

namespace baseFunc {

class Controller {
 public:
  Controller(Calculator *m, Credit *c);
  ~Controller();
  double CalculateMain(std::string expression, double x);
  Calculator::CoordinatesXY &CalculateGraph(std::string expression,
                                            int number_of_points,
                                            double x_start, double x_end,
                                            double y_min, double y_max);
  Credit::CreditResult CalculateCredit(bool type, double credit_amount,
                                       double period, double rate);

 private:
  Calculator *calculator_model_;
  Credit *credit_model_;
};
}  // namespace baseFunc

#endif  // CONTROLLER_H_
