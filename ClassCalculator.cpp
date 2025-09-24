#include "ClassCalculator.h"

const char* CalculatorException::what()  const noexcept
{
	return "Error ";
}

const char* DivideException::what() const noexcept
{
	return "Sorry, but you can't do this operation with '0'";
}

const char* InvalidOperation::what() const noexcept
{
	return "Sorry, your operation is incorrect";
}

void Calculator::setResult(double StartValue)
{
	result = StartValue;
}
double Calculator::getResult() const
{
	return result;
}
Calculator& Calculator::Calculate(const double& value, const char& operation)
{
	result = Calculate(operation, result, value);
	return *this;
}

Calculator& Calculator::operator+ (double value)
{
	return Calculate(value, '+');

}

Calculator& Calculator::operator- (double value)
{
	return Calculate(value, '-');
}

Calculator& Calculator::operator* (double value)
{
	return Calculate(value, '*');
}

Calculator& Calculator::operator/ (double value)
{
	return Calculate(value, '/');

}


double Calculator::FuncOfSum(double num1, double num2)
{
	return num1 + num2;
}

double Calculator::FuncOfMultip(double num1, double num2)
{
	return num1 - num2;
}

double Calculator::FuncOfSubtr(double num1, double num2)
{
	return num1 / num2;
}

double Calculator::FuncOfDiv(double num1, double num2)
{
	return num1 * num2;
}

double Calculator::Calculate(char op, double num1, double num2)
{
	double result = 0;
	if (op == '+')
	{
		result = FuncOfSum(num1, num2);
	}
	else if (op == '-')
	{
		result = FuncOfMultip(num1, num2);
	}
	else if (op == '/')
	{
		if (num2 == 0)
		{
			throw DivideException();
		}
		else
		{
			result = FuncOfSubtr(num1, num2);
		}
	}
	else if (op == '*')
	{
		result = FuncOfDiv(num1, num2);
	}
	else
	{
		throw InvalidOperation();
	}
	return result;
}