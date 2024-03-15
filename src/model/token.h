#ifndef MODEL_TOKEN_H_
#define MODEL_TOKEN_H_
#include <functional>
#include <map>
#include <string>

namespace baseFunc {

#define op1arg(SIGN) [](double a, double b = 0) -> double { return b - a; }
#define op2arg(SIGN) [](double a, double b) -> double { return a SIGN b; }
#define f1arg(SIGN) [](double a, double b = 0) -> double { return SIGN(b + a); }
#define f2arg(SIGN) [](double a, double b) -> double { return SIGN(a, b); }

enum token_type {
  kNumber,
  kFunction,
  kOperator,
  kUnaryOperator,
  kOpenBracket,
  kCloseBracket
};

enum priority { None, Low, Medium, High, Highest };

class Token {
 public:
  Token() = default;
  Token(std::string token_name, token_type token_type, priority priority,
        std::function<double(double, double)> op);
  ~Token() = default;

  std::string GetName();
  token_type GetTokenType();
  priority GetPriority();
  std::function<double(double, double)> GetOperator();

 private:
  std::string token_name_;
  token_type token_type_;
  priority priority_;
  std::function<double(double, double)> operator_;
};

void CreateTokenMap(std::map<std::string, baseFunc::Token>& temp_map);

}  // namespace baseFunc

#endif  // TOKEN_H_
