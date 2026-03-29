#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

const char *Intern::UnknownFormException::what() const throw()
{
    return "unknown form";
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    const std::string names[3] = {
        "shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)};

    for (int i = 0; i < 3; ++i)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << forms[i]->getName() << std::endl;
            for (int j = 0; j < 3; ++j)
            {
                if (j != i)
                    delete forms[j];
            }
            return forms[i];
        }
    }
    for (int i = 0; i < 3; ++i)
        delete forms[i];
    throw UnknownFormException();
}
