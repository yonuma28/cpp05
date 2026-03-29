#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < Bureaucrat::highestGrade || execGrade < Bureaucrat::highestGrade)
        throw GradeTooHighException();
    if (signGrade > Bureaucrat::lowestGrade || execGrade > Bureaucrat::lowestGrade)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _signGrade(other._signGrade),
      _execGrade(other._execGrade)
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

const std::string &Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _isSigned;
}

int Form::getRequiredSign() const
{
    return _signGrade;
}

int Form::getRequiredExecute() const
{
    return _execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << ", form sign grade " << form.getRequiredSign()
        << ", form execute grade " << form.getRequiredExecute() << ", signed: "
        << std::boolalpha << form.getSigned();
    return out;
}
