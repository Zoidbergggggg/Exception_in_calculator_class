
#include <iostream>
#include <stdexcept>
#include "ClassCalculator.h"


int main()
{
	Calculator Calc;

	Calc.Calculate(5, '+').Calculate(2, '-').Calculate(7, '*').Calculate(4, '/');

	std::cout << "Class and descendant processing: \n";
	try
	{
		Calc.Calculate(0, '/');
	}
	catch (const DivideException& except)
	{
		std::cout << except.what() << std::endl;
	}
	try
	{
		Calc.Calculate(5, '.');
	}
	catch (const InvalidOperation& except)
	{
		std::cout << except.what() << std::endl;
	}
	try
	{
		throw CalculatorException();
	}
	catch (const CalculatorException& except)
	{
		std::cout << except.what() << std::endl;
	}

	std::cout << "Result of your operations: " << Calc.getResult() << std::endl;

	Calc + 123;
	Calc - 13;
	Calc * 3;
	Calc / 5;
	std::cout << "Result of your operations: " << Calc.getResult() << std::endl;

	return 0;
}