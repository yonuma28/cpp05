# include "Form.hpp"

Form::Form(const std::string& name, int signGrade, int execGrade)
    : _name(name),
      _isSigned(false),
      _signGrade(signGrade),
      _execGrade(execGrade)
{
    if (signGrade < highestGrade || execGrade < highestGrade)
        throw Form::GradeTooHighException();
    if (signGrade > lowestGrade || execGrade > lowestGrade)
        throw Form::GradeTooLowException();
        
    std::cout << _name << " constructor called !!" << std::endl;
}

Form::Form(const Form& copy)
    : _name(copy._name), 
      _isSigned(copy._isSigned), 
      _signGrade(copy._signGrade), 
      _execGrade(copy._execGrade)
{
    std::cout << "copy construcor called !!" << std::endl;
}

Form& Form::operator=(const Form& copy)
{
    if (this != &copy) {
        this->_isSigned = copy._isSigned;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "destructor called !!" << std::endl;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _signGrade) {
      _isSigned = true;
    } else {
      throw GradeTooLowException();
    }
}

const std::string &Form::getName() const { return _name; }

bool Form::getSigned() const { return _isSigned; }

unsigned int Form::getRequiredSign() const { return _signGrade; }

unsigned int Form::getRequiredExecute() const { return _execGrade; }

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "name: " << form.getName() << std::endl
     << "signed: " << std::boolalpha << form.getSigned() << std::endl
     << "gradeRequiresSign: " << form.getRequiredSign() << std::endl
     << "gradeRequiredExecute: " << form.getRequiredExecute();
  return os;
}
