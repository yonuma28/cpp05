#include "AForm.hpp"

#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < Bureaucrat::highestGrade || execGrade < Bureaucrat::highestGrade)
        throw GradeTooHighException();
    if (signGrade > Bureaucrat::lowestGrade || execGrade > Bureaucrat::lowestGrade)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _signGrade(other._signGrade),
      _execGrade(other._execGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _isSigned;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecGrade() const
{
    return _execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
    performAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "form not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << form.getName() << ", form sign grade " << form.getSignGrade()
        << ", form execute grade " << form.getExecGrade() << ", signed: "
        << std::boolalpha << form.getSigned();
    return out;
}
