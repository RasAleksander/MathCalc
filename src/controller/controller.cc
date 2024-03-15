#include "../controller/controller.h"

baseFunc::Controller::Controller(Calculator* m, Credit* c)
    : calculator_model_(m), credit_model_(c) {}

baseFunc::Controller::~Controller() {}

double baseFunc::Controller::CalculateMain(const std::string expression,
                                           double x) {
  calculator_model_->ParseToTokens(expression);
  calculator_model_->ConvertToPostfix();
  return calculator_model_->CalculatePostfix(x);
}

baseFunc::Calculator::CoordinatesXY& baseFunc::Controller::CalculateGraph(
    std::string expression, int number_of_points, double x_start, double x_end,
    double y_min, double y_max) {
  calculator_model_->ParseToTokens(expression);
  calculator_model_->ConvertToPostfix();
  calculator_model_->CalculateCoordinates(number_of_points, x_start, x_end,
                                          y_min, y_max);
  return calculator_model_->GetGraphCoordinates();
}

baseFunc::Credit::CreditResult baseFunc::Controller::CalculateCredit(
    bool type, double credit_amount, double period, double rate) {
  if (type) {
    credit_model_->CalculateAnnuityCredit(credit_amount, period, rate);
  } else {
    credit_model_->CalculateDifferentiatedCredit(credit_amount, period, rate);
  }
  return credit_model_->GetResultValues();
}