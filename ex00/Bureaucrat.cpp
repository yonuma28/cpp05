#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade)
{
    if (grade < highestGrade)
        throw GradeTooHighException();
    if (grade > lowestGrade)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::IncrementGrade()
{
    if (_grade <= highestGrade)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::DecrementGrade()
{
    if (_grade >= lowestGrade)
        throw GradeTooLowException();
    ++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
        << ".";
    return out;
}
