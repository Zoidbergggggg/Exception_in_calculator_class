#pragma once
#include <iostream>
#include <stdexcept>

class CalculatorException : public std::exception
{
public:

	virtual const char* what() const noexcept;

};
class DivideException : public CalculatorException
{
public:
	virtual const char* what() const noexcept;
};
class InvalidOperation : public CalculatorException
{
public:
	virtual const char* what() const noexcept;
};
class Calculator
{
public:
	void setResult(double StartValue);

	double getResult() const;

	Calculator& Calculate(const double& value, const char& operation);

	Calculator& operator+ (double value);

	Calculator& operator- (double value);

	Calculator& operator* (double value);

	Calculator& operator/ (double value);

private:
	double FuncOfSum(double num1, double num2);

	double FuncOfMultip(double num1, double num2);

	double FuncOfSubtr(double num1, double num2);

	double FuncOfDiv(double num1, double num2);

	double Calculate(char op, double num1, double num2);

	double result = 0;

};