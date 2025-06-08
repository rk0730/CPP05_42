#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	std::cout << "case 1" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Alice", 50);
		std::cout << bureaucrat << std::endl;
		Form form("Form1", 50, 30);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "case 2" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Alice", 50);
		std::cout << bureaucrat << std::endl;
		Form form("Form1", 0, 30);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
