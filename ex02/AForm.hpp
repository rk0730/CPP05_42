#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
class Bureaucrat; // Forward declaration to avoid circular dependency

class AForm
{
public:
	AForm();
	AForm(const std::string &name, int signGrade, int executeGrade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class FormIsNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;

private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _executeGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
