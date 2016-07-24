#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <exception>
#include <sstream>

class Operator {

public:
  Operator(const std::string & name) : name(name) {}
  virtual ~Operator() {}

  virtual int operator()(const int left, const int right) const = 0;

private:
  std::string name;

};

class SumOperator : public Operator {

public:
  SumOperator() : Operator("+") {}

  virtual int operator()(const int left, const int right) const override {
    return left + right;
  }
};

class MultiplyOperator : public Operator {

public:
  MultiplyOperator() : Operator("*") {}

  virtual int operator()(const int left, const int right) const override {
    return left * right;
  }

};

bool isOperator(char value) {
  if (value == '+' || value == '*') {
    return true;
  }

  return false;
}

const Operator * operatorForSymbol(char value) {
  if (value == '+') {
    return new SumOperator();
  } else if (value == '*') {
    return new MultiplyOperator();
  } else {
    throw std::invalid_argument("value is invalid");
  }
}

enum class ParserStatus {
  None, ParsingDigit
};

int main(int argc, char const *argv[])
{
  std::stack<int> values;
  std::stack<const Operator *> operators;

  std::string expression = "( 1 + ( ( 2 + 3 ) * ( 4 * 5 ) ) )";

  ParserStatus status = ParserStatus::None;
  std::stringstream temporaryValue;
  std::for_each(expression.begin(), expression.end(), [&](const char value) {
    if (std::isdigit(value)) {
      temporaryValue << value;
      status = ParserStatus::ParsingDigit;
    } else if (value == '(') {
      if (status == ParserStatus::ParsingDigit) {
        std::cerr << "Got '(' but expecting operator, digit or ')' " << std::endl;
        std::exit(EXIT_FAILURE);
      }
    } else if (std::isblank(value)) {
      // ignore
    } else if (isOperator(value)) {
      if (status == ParserStatus::ParsingDigit) {
        values.push(atoi(temporaryValue.str().c_str()));
        temporaryValue.str("");
        status = ParserStatus::None;
      }

      operators.push(operatorForSymbol(value));
    } else if (value == ')') {
      if (status == ParserStatus::ParsingDigit) {
        values.push(atoi(temporaryValue.str().c_str()));
        temporaryValue.str("");
        status = ParserStatus::None;
      }

      const Operator * op = operators.top();
      operators.pop();

      const int right = values.top();
      values.pop();
      const int left = values.top();
      values.pop();

      values.push((*op)(left, right));
      delete op;
    }


  });

  std::cout << "Result = " << values.top() << std::endl;
  return 0;
}
