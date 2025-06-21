#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
	srand(time(NULL));
	Intern intern;
	std::cout << "case 1" << std::endl;
	try
	{
		Bureaucrat defaultBureaucrat("default", 150);
		Bureaucrat bureaucrat("Alice", 137);
		// ShrubberyCreationForm form("home");
		AForm *form = intern.makeForm("shrubbery creation", "home");
		std::cout << defaultBureaucrat << std::endl;
		std::cout << bureaucrat << std::endl;
		std::cout << *form << std::endl;
		bureaucrat.executeForm(*form);
		defaultBureaucrat.signForm(*form);
		std::cout << *form << std::endl;
		bureaucrat.signForm(*form);
		std::cout << *form << std::endl;
		bureaucrat.executeForm(*form);
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}

	std::cout << "case 2" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Bob", 4);
		// RobotomyRequestForm form("target");
		AForm *form = intern.makeForm("robotomy request", "target");
		std::cout << bureaucrat << std::endl;
		std::cout << *form << std::endl;
		bureaucrat.signForm(*form);
		std::cout << *form << std::endl;
		for (int i = 0; i < 10; ++i)
		{
			bureaucrat.executeForm(*form);
		}
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}

	std::cout << "case 3" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Charlie", 1);
		// PresidentialPardonForm form("target");
		AForm *form = intern.makeForm("presidential pardon", "target");
		std::cout << bureaucrat << std::endl;
		std::cout << *form << std::endl;
		bureaucrat.signForm(*form);
		std::cout << *form << std::endl;
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}

	std::cout << "case 4" << std::endl;
	try
	{
		AForm *form = intern.makeForm("unknown form", "target");
		std::cout << *form << std::endl;
		delete form; // This line should not be reached
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return 0;
}
