#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("target_shrubbery", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm(target + "_robotomy_request", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::cout << "Bzzzzzzzzzz DRRRRIIIILLLL" << std::endl;

	if (rand() % 2)
	{
		std::cout << getName() << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed for " << getName() << "!" << std::endl;
	}
}
