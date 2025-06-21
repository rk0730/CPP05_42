#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>

class AForm;

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &target) const;
private:
	static const std::string formNames[3];
};


#endif
