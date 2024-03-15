#include <gtest/gtest.h>

#include "../model/calculator.h"
#include "../model/credit.h"

#define kAcc 1e-6

TEST(calculation, kek_add) {
  s21::Calculator calc;
  calc.ParseToTokens("8+3");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 11, kAcc);
}

TEST(calculation, add) {
  s21::Calculator calc;
  calc.ParseToTokens("5.53234+1032.42342");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 1037.95576, kAcc);
}

TEST(calculation, sum) {
  s21::Calculator calc;
  calc.ParseToTokens("1037.95576-234.234");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 803.72176, kAcc);
}

TEST(calculation, mul) {
  s21::Calculator calc;
  calc.ParseToTokens("803.72176*423.234");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 340162.375372, kAcc);
}

TEST(calculation, div) {
  s21::Calculator calc;
  calc.ParseToTokens("340162.375372/342.32");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 993.697053552, kAcc);
}

TEST(calculation, mod) {
  s21::Calculator calc;
  calc.ParseToTokens("993.697053552mod423.234");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 147.229053552, kAcc);
}

TEST(calculation, parenthesis) {
  s21::Calculator calc;
  calc.ParseToTokens("423.23*(23-4.3)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 7914.401, kAcc);
}

TEST(calculation, sin) {
  s21::Calculator calc;
  calc.ParseToTokens("sin(54.5)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), -0.88797583833, kAcc);
}

TEST(calculation, cos) {
  s21::Calculator calc;
  calc.ParseToTokens("cos(32.32)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 0.61841396583, kAcc);
}

TEST(calculation, tan) {
  s21::Calculator calc;
  calc.ParseToTokens("tan(34.23)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), -0.33975534786, kAcc);
}

TEST(calculation, log) {
  s21::Calculator calc;
  calc.ParseToTokens("log(23.23)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 1.3660492098, kAcc);
}

TEST(calculation, ln) {
  s21::Calculator calc;
  calc.ParseToTokens("ln(48.234)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 3.87606416657, kAcc);
}

TEST(calculation, sqrt) {
  s21::Calculator calc;
  calc.ParseToTokens("sqrt(423)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 20.5669638012, kAcc);
}

TEST(calculation, asin) {
  s21::Calculator calc;
  calc.ParseToTokens("asin(0.324)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 0.329954518, kAcc);
}

TEST(calculation, acos) {
  s21::Calculator calc;
  calc.ParseToTokens("acos(0.324)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 1.24084181, kAcc);
}

TEST(calculation, atan) {
  s21::Calculator calc;
  calc.ParseToTokens("atan(-0.324)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), -0.313327168, kAcc);
}

TEST(calculation, pow) {
  s21::Calculator calc;
  calc.ParseToTokens("423.32^(2.432^(1/5))");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 1372.787322, kAcc);
}

TEST(calculation, expression_1) {
  s21::Calculator calc;
  calc.ParseToTokens("cos(sin(3.14))");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 0.999998, kAcc);
}

TEST(calculation, expression_2) {
  s21::Calculator calc;
  calc.ParseToTokens("(cos(sin(3.14))+3.12)^-5.14e-3");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 0.9927489, kAcc);
}

TEST(calculation, expression_3) {
  s21::Calculator calc;
  calc.ParseToTokens("sqrt(cos(sin(3.14))+3.12)^-5.14e-3");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 0.9963678, kAcc);
}

TEST(calculation, expression_5) {
  s21::Calculator calc;
  calc.ParseToTokens("(-(-(+(+5))))");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 5, kAcc);
}

TEST(calculation, expression_6) {
  s21::Calculator calc;
  calc.ParseToTokens("0^(-1)");
  calc.ConvertToPostfix();
  ASSERT_DOUBLE_EQ(calc.CalculatePostfix(0), INFINITY);
}

TEST(calculation, expression_7) {
  s21::Calculator calc;
  calc.ParseToTokens("2^(3+4*5)*(2*2)+2+6/3");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 33554436, kAcc);
}

TEST(calculation, expression_8) {
  s21::Calculator calc;
  calc.ParseToTokens("sin(2-1)*2^2+6^2*2");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 75.365883939231579, kAcc);
}

TEST(calculation, expression_9) {
  s21::Calculator calc;
  calc.ParseToTokens("(-(-(-5)))*(-(-5))");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), -25, kAcc);
}

TEST(calculation, expression_10) {
  s21::Calculator calc;
  calc.ParseToTokens("-2^(3+4*5)*(2*2)+2+6/3");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), -33554428, kAcc);
}

TEST(calculation, expression_11) {
  s21::Calculator calc;
  calc.ParseToTokens("56+21-376+(56-22)-(13+10)+(11+(7-(3+2)))");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), -275, kAcc);
}

TEST(calculation, expression_12) {
  s21::Calculator calc;
  calc.ParseToTokens("tan(10)*((5-3)*ln(4)-log(8))*2+7");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 9.4242194938376841, kAcc);
}

TEST(calculation, expression_13) {
  s21::Calculator calc;
  calc.ParseToTokens(
      "((-(-356.081*4598.63)*803.928*(70.592*(-0.1569))*(-36.1566)))");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 527181836601.876000, 1);
}

TEST(calculation, expression_14) {
  s21::Calculator calc;
  calc.ParseToTokens("1+9+2-3*4/5mod6^7");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 9.6, kAcc);
}

TEST(calculation, expression_15) {
  s21::Calculator calc;
  calc.ParseToTokens("2^(3^4)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 2417851639229258349412352.0, kAcc);
}

TEST(calculation, expression_16) {
  s21::Calculator calc;
  calc.ParseToTokens("sin(x+cos(x^x))*tan(x)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(1), 1.5566836754802069187064716, kAcc);
}

TEST(calculation, expression_17) {
  s21::Calculator calc;
  calc.ParseToTokens("asin(x+1)+acos(x)-atan(2)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(-0.60), 1.518665563861578471360758, kAcc);
}

TEST(calculation, expression_18) {
  s21::Calculator calc;
  calc.ParseToTokens("sqrt(8965)+ln(56253)-log(965)");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(0), 102.636771255135727187735, kAcc);
}

TEST(calculation, expression_19) {
  s21::Calculator calc;
  calc.ParseToTokens("5.3+8.6-sin(x*1.6-5)/0.5");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(-0.60), 13.26482286785592989986, kAcc);
}

TEST(calculation, expression_20) {
  s21::Calculator calc;
  calc.ParseToTokens("x");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(-0.60), -0.60, kAcc);
}

TEST(calculation, expression_23) {
  s21::Calculator calc;
  calc.ParseToTokens("x");
  calc.ConvertToPostfix();
  ASSERT_NEAR(calc.CalculatePostfix(-1), -1, kAcc);
}

TEST(calculation, expression_25) {
  s21::Calculator calc;
  calc.ParseToTokens("1/0");
  calc.ConvertToPostfix();
  ASSERT_TRUE(std::isinf(calc.CalculatePostfix(0)));
}

TEST(calculation, expression_26) {
  s21::Calculator calc;
  calc.ParseToTokens("-1/0");
  calc.ConvertToPostfix();
  ASSERT_TRUE(std::isinf(calc.CalculatePostfix(0)));
}

TEST(calculation_graph, expression) {
  using namespace s21;
  Calculator calc;
  calc.ParseToTokens("x*x");
  calc.ConvertToPostfix();
  calc.CalculateCoordinates(11, 0, 10, -10, 100);
  Calculator::CoordinatesXY result = calc.GetGraphCoordinates();
  std::vector<double> expected_x = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<double> expected_y = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
  ASSERT_TRUE((result.first == expected_x) && (result.second == expected_y));
}

TEST(credit, ann) {
  s21::Credit calc;
  calc.CalculateAnnuityCredit(123456, 120, 4.56);
  ASSERT_NEAR(calc.GetResultValues().total_payment, 153966.24, 1e-2);
  ASSERT_NEAR(calc.GetResultValues().overpayment, 30510.24, 1e-2);
  ASSERT_NEAR(calc.GetResultValues().monthly_payment.at(0), 1283.05, 1e-2);
}

TEST(credit, diff) {
  s21::Credit calc;
  calc.CalculateDifferentiatedCredit(100000, 6, 12.5);
  ASSERT_NEAR(calc.GetResultValues().total_payment, 103645.83, 1e-2);
  ASSERT_NEAR(calc.GetResultValues().overpayment, 3645.83, 1e-2);
  std::vector<double> expected_mp = {17708.33, 17534.72, 17361.11,
                                     17187.50, 17013.89, 16840.28};
  for (int i = 0; i < 6; ++i) {
    ASSERT_NEAR(calc.GetResultValues().monthly_payment.at(i), expected_mp.at(i),
                1e-2);
  }
}

TEST(logic_error, incorrect_symbol) {
  s21::Calculator calc;
  ASSERT_ANY_THROW(calc.ParseToTokens("2 + $"));
}

TEST(logic_error, incorrect_function_name) {
  s21::Calculator calc;
  ASSERT_ANY_THROW(calc.ParseToTokens("2+ sinus(5)"));
}

TEST(logic_error, fail_2) {
  s21::Calculator calc;
  ASSERT_ANY_THROW(calc.ParseToTokens("2.5.4 + 6"));
}

TEST(logic_error, fail_3) {
  s21::Calculator calc;
  ASSERT_ANY_THROW(calc.ParseToTokens("s"));
}

TEST(logic_error, fail_4) {
  s21::Calculator calc;
  calc.ParseToTokens("cos()");
  calc.ConvertToPostfix();
  ASSERT_ANY_THROW(calc.CalculatePostfix(0));
}

TEST(logic_error, fail_5) {
  s21::Calculator calc;
  calc.ParseToTokens("2*1+5)");
  ASSERT_ANY_THROW(calc.ConvertToPostfix());
}

TEST(logic_error, fail_6) {
  s21::Calculator calc;
  calc.ParseToTokens("(2-6");
  ASSERT_ANY_THROW(calc.ConvertToPostfix());
}

TEST(logic_error, fail_7) {
  s21::Calculator calc;
  ASSERT_ANY_THROW(calc.ParseToTokens("sqrtd2"));
}

TEST(logic_error, fail_8) {
  s21::Calculator calc;
  calc.ParseToTokens("22+7 5 4");
  calc.ConvertToPostfix();
  ASSERT_ANY_THROW(calc.CalculatePostfix(0));
}

TEST(logic_error, fail_9) {
  s21::Calculator calc;
  calc.ParseToTokens("100+2+");
  calc.ConvertToPostfix();
  ASSERT_ANY_THROW(calc.CalculatePostfix(0));
}

TEST(logic_error, fail_10) {
  s21::Calculator calc;
  calc.ParseToTokens("*");
  calc.ConvertToPostfix();
  ASSERT_ANY_THROW(calc.CalculatePostfix(0));
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
