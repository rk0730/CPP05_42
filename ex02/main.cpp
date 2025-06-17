#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
	std::cout << "case 1" << std::endl;
	try
	{
		Bureaucrat defaultBureaucrat("default", 150);
		Bureaucrat bureaucrat("Alice", 137);
		ShrubberyCreationForm form("home");
		std::cout << defaultBureaucrat << std::endl;
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		bureaucrat.executeForm(form);
		defaultBureaucrat.signForm(form);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		bureaucrat.executeForm(form);
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "case 2" << std::endl;
	try
	{
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
