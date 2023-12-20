#include "TFormula.h"
#include "gtests.h"
TEST(TFormula, Calculatortest_sum)
{
  TFormula<double> formula("3 + 2");
  double result = formula.Calc();
  EXPECT_DOUBLE_EQ(result, 5.0);
}
TEST(TFormula, Calculatortest_min)
{
  TFormula<double> formula("3 - 2");
  double result = formula.Calc();
  EXPECT_DOUBLE_EQ(result, 1.0);
}
TEST(TFormula, Calculatortest_multi)
{
  TFormula<double> formula("2 * 2");
  double result = formula.Calc();
  EXPECT_DOUBLE_EQ(result, 4.0);
}
TEST(TFormula, Calculatortest_del)
{
  TFormula<double> formula("5 / 2");
  double result = formula.Calc();
  EXPECT_DOUBLE_EQ(result, 2.5);
}
TEST(TFormula, Calculatortest_scob)
{
  TFormula<double> formula("(1 + 3)/2");
  double result = formula.Calc();
  EXPECT_DOUBLE_EQ(result, 2.0);
}
TEST(TFormula, Calculatortest_mnogo)
{
  TFormula<double> formula("1+2*(3-2)-4");
  double result = formula.Calc();
  EXPECT_DOUBLE_EQ(result, -1.0);
}
TEST(TFormulaTest, Execute_zero) 
{
  TFormula<double> formula("10 / 0");
  char divisionOperator = '/';
  double firstOperand = 10.0;
  double secondOperand = 0.0;
  EXPECT_THROW(formula.Execute(divisionOperator, firstOperand, secondOperand), const char*);
}
TEST(TFormulaTest, Execute_inval) 
{
  TFormula<double> formula("10 s 5");
  char invalidOperator = 's';
  double firstOperand = 10.0;
  double secondOperand = 5.0;
  EXPECT_THROW(formula.Execute(invalidOperator, firstOperand, secondOperand), std::invalid_argument);
}

TEST(TFormulaTest, ToPostfix_mnogo) {
  TFormula<int> formula("(3 + 4) * 2");
  string infixExpr = "(3 + 4) * 2";
  EXPECT_EQ(formula.ToPostfix(infixExpr), "3 4 +2 *");
}

TEST(TFormulaTest, ToPostfix_operand) {
  TFormula<int> formula("5");
  string infixExpr = "5";
  EXPECT_EQ(formula.ToPostfix(infixExpr), "5 ");
}

TEST(TFormulaTest, ToPostfix_empty) {
  TFormula<int> formula("");
  string infixExpr = "";
  EXPECT_EQ(formula.ToPostfix(infixExpr), "");
}

