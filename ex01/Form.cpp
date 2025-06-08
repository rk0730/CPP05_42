#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade),
	  _executeGrade(other._executeGrade)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form()
{
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() << ", Form is " << (form.getIsSigned() ? "signed" : "not signed")
	   << ", Sign Grade " << form.getSignGrade() << ", Execute Grade " << form.getExecuteGrade()
	   << ".";
	return os;
}
