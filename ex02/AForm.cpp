# include "AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : _name(name),
      _isSigned(false),
      _signGrade(signGrade),
      _execGrade(execGrade)
{
    if (signGrade < highestGrade || execGrade < highestGrade)
        throw AForm::GradeTooHighException();
    if (signGrade > lowestGrade || execGrade > lowestGrade)
        throw AForm::GradeTooLowException();
        
    std::cout << _name << " constructor called !!" << std::endl;
}

AForm::AForm(const AForm& copy)
    : _name(copy._name), 
      _isSigned(copy._isSigned), 
      _signGrade(copy._signGrade), 
      _execGrade(copy._execGrade)
{
    std::cout << "copy construcor called !!" << std::endl;
}

AForm& AForm::operator=(const AForm& copy)
{
    if (this != &copy) {
        this->_isSigned = copy._isSigned;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "destructor called !!" << std::endl;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _signGrade) {
      _isSigned = true;
    } else {
      throw GradeTooLowException();
    }
}

const std::string &AForm::getName() const { return _name; }

bool AForm::getSigned() const { return _isSigned; }

unsigned int AForm::getRequiredSign() const { return _signGrade; }

unsigned int AForm::getRequiredExecute() const { return _execGrade; }

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low";
}

const char* AForm::NotSigned::what() const throw() {
    return "AForm is not signed";
}

void    AForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigned())
        throw AForm::NotSigned();
    
    if (executor.getGrade() > this->getRequiredExecute())
        throw AForm::GradeTooLowException();
    
    this->performAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
  os << "- name: " << AForm.getName() << std::endl
     << "- signed: " << std::boolalpha << AForm.getSigned() << std::endl
     << "- gradeRequiresSign: " << AForm.getRequiredSign() << std::endl
     << "- gradeRequiredExecute: " << AForm.getRequiredExecute();
  return os;
}
