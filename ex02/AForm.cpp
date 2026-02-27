# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm(const AForm &Aform)
  : _name(Aform.getName()), _target(Aform.getTarget()), _isSigned(Aform.getSigned()),
      _signGrade(Aform.getSignGrade()),
      _execGrade(Aform.getExecGrade()) {}

AForm::AForm(const std::string &name, const std::string& target, const int gradeRequiredSign,
             const int gradeRequiredExecute)
    : _name(name), _target(target), _isSigned(false), _signGrade(gradeRequiredSign),
      _execGrade(gradeRequiredExecute)
{
  if (_execGrade < Bureaucrat::highestGrade ||
      _signGrade < Bureaucrat::highestGrade) {
    throw GradeTooHighException();
  } else if (_execGrade > Bureaucrat::lowestGrade ||
             _signGrade > Bureaucrat::lowestGrade) {
    throw GradeTooLowException();
  }
}

AForm &AForm::operator=(const AForm &form) {
  if (this != &form) {
    this->_isSigned = form.getSigned();
  }
  return *this;
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() <= static_cast<unsigned int>(_signGrade)) {
    _isSigned = true;
  } else {
    throw GradeTooLowException();
  }
}

const std::string &AForm::getName() const { return _name; }

const std::string &AForm::getTarget() const { return _target; }

bool AForm::getSigned() const { return _isSigned; }

unsigned int AForm::getSignGrade() const { return _signGrade; }

unsigned int AForm::getExecGrade() const { return _execGrade; }

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "name: " << form.getName() << std::endl
     << "signed: " << std::boolalpha << form.getSigned() << std::endl
     << "gradeRequiresSign: " << form.getSignGrade() << std::endl
     << "gradeRequiredExecute: " << form.getExecGrade();
  return os;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > static_cast<unsigned int>(this->_execGrade))
        throw AForm::GradeTooLowException();

    this->performAction();
}
