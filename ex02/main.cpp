#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
	std::cout << "case 1" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Alice", 50);
		ShrubberyCreationForm form("home");
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		bureaucrat.executeForm(form);
		std::cout << "Shrubbery creation form executed successfully." << std::endl;
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
