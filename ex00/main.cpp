#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat bureaucrat("Alice", 50);
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat("Bob", 0);
		std::cout << "error" << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

		try
	{
		Bureaucrat bureaucrat("Charlie", 0);
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	return 0;
}
