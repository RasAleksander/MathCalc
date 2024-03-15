#ifndef MODEL_CALCULATOR_H_
#define MODEL_CALCULATOR_H_
#include <cmath>
#include <queue>
#include <regex>
#include <stack>
#include <string>

#include "../model/token.h"

namespace baseFunc {

class Calculator {
 public:
  using CoordinatesXY = std::pair<std::vector<double>, std::vector<double>>;
  Calculator();
  ~Calculator();
  void ParseToTokens(const std::string expression);
  void ConvertToPostfix();
  double CalculatePostfix(const double x);
  void CalculateCoordinates(int number_of_points, double x_start, double x_end,
                            double y_min, double y_max);
  CoordinatesXY &GetGraphCoordinates();

 private:
  std::queue<Token> infix_;
  std::queue<Token> postfix_;
  std::stack<Token> token_stack_;
  std::stack<double> number_stack_;
  std::map<std::string, Token> token_map_;
  std::function<double(double, double)> f_;
  CoordinatesXY coordinates_;

  std::string FindNumber(const std::string &expression, size_t &index);
  std::string FindFunction(const std::string &expression, size_t &index);
  bool FindUnaryMinus(const std::string &exp, size_t &index);
  void CheckAndPushToken(std::string temp);
  double PopFromResult();
};
}  // namespace baseFunc
#endif
