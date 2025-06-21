#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("target_shrubbery", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm(target + "_shrubbery", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();

	std::ofstream ofs(getName().c_str());
	if (!ofs.is_open())
		throw std::runtime_error("Failed to open file for writing");

	std::string tree_art = "   / \\\n"
						   "  /   \\\n"
						   " /     \\\n"
						   "/_______\\\n"
						   "  |||||\n"
						   "  |||||\n";
	ofs << tree_art << std::endl;
	ofs.close();
}
