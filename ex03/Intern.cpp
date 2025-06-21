#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <stdexcept>

const std::string Intern::formNames[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other; // Avoid unused parameter warning
}

Intern &Intern::operator=(const Intern &other) {
	(void)other; // Avoid unused parameter warning
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			switch (i) {
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}
	throw std::invalid_argument("Unknown form name: " + formName);
	return NULL;
}
