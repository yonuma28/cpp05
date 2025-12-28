# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
    _name(" name "), _grade( grade )
{
    std::cout << _name << ": Default constructor called !!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << _name << ": Destructor called !!" << std::endl;
}

