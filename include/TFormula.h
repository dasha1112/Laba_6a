#ifndef _FORMULA_
#define _FORMULA_

#include <iostream>
#include <string>
#include "TStack.h"
#include <list>
template <class T>
class TFormula 
{
protected:
	string infixExpr;
	string postfixExpr;
public:
	TFormula(string expression);
	string GetStringNumber(string expr, int& pos);
	string ToPostfix(string infixExpr);
	double Execute(char op, double first, double second);
	double Calc();
  int Priority(char c);
};

template<class T>
inline TFormula<T>::TFormula(string expression)
{
	infixExpr = expression;
	postfixExpr = ToPostfix(infixExpr);
}

template<class T>
inline string TFormula<T>::GetStringNumber(string expr, int& pos)
{
  string strNumber = "";
  for (; pos < expr.size(); pos++)  //	Перебираем строку
  {
    char num = expr[pos]; //	Разбираемый символ строки
    if (isdigit(num))//	Проверяем, является символ числом
      strNumber += num;
    else
    {
      pos--;
      break;
    }
  }
  return strNumber;
}

template<class T>
inline string TFormula<T>::ToPostfix(string infixExpr) //преобразовывает в постфиксную форм
{
  string postfixExpr = "";
  TStack<char> stack(infixExpr.size());
  for (int i = 0; i < infixExpr.size(); i++)
  {
    char c = infixExpr[i];
    if (isdigit(c)) //если число, то добавляем в строку
    {
      postfixExpr += GetStringNumber(infixExpr, i) + " ";
    }
    else if (c == '(') 
    {
      stack.Push(c); //кладем в стек
    }
    else if (c == ')')
    {
      while (stack.GetCount() > 0 && stack.Top() != '(') //достаем все операнды до закр. скобки
      {
        postfixExpr += stack.GetElem();
      }
      stack.GetElem();
    }
    else if (c == '*' || c == '+' || c == '-' || c == '/')
    {
      while (stack.GetCount() > 0 && stack.Top() != '(' && Priority(stack.Top()) >= Priority(c))
      {
        postfixExpr += stack.GetElem();
      }
      stack.Push(c);
    }
  }
  while (stack.GetCount() > 0)
  {
    postfixExpr += stack.GetElem();
  }
  return postfixExpr;
}


template<class T>
inline double TFormula<T>::Execute(char op, double first, double second)
{
  if (op == '+') { return first + second; }
  else if (op == '-') { return first - second; }
  else if (op == '*') { return first * second; }
  else if (op == '/') 
  {
    if (second == 0) 
    {
      throw "Ошибка";
    }
    else 
    {
      return first / second;
    }
  }
  else 
  {
    throw std::invalid_argument("Invalid operator");
  }
}

template<class T>
inline double TFormula<T>::Calc() 
{
  TStack<double> stack(postfixExpr.size());
  for (int i = 0; i < postfixExpr.size(); i++)//проходим по строке
  {
    char c = postfixExpr[i];
    if (isdigit(c))
    {
      stack.Push(atof(&c)); //заносим в стек
    }
    else if (c == '+' || c == '-' || c == '*' || c == '/') //если операция 
    {
      double second = stack.GetElem();
      double first = stack.GetElem();
      double result = Execute(c, first, second); //выполняем операцию
      stack.Push(result); //заносим результат в стек
    }
  }
  return stack.Top();
}
template<class T>
inline int TFormula<T>::Priority(char c) //приоритет операций
{
  if (c == '+' || c == '-') return 1;
  else if (c == '*' || c == '/') return 2;
  return 0;
}
#endif