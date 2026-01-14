# include "Bureaucrat.hpp"
# include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) // nameは定数なのでここで初期化
{
    if (grade < highestGrade) {
        throw GradeTooHighException();
    }
    if (lowestGrade < grade) {
        throw GradeTooLowException();
    }
    this->_grade = grade;
    std::cout << _name << " constructed with grade " << _grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << _name << ": Destructor called !!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
    : _name(copy.getName()), _grade(copy.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    if (this != &copy)
    {
        this->_grade = copy.getGrade();
    }
    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return _name;
}

unsigned int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::IncrementGrade() {
    if (_grade - 1 <= Bureaucrat::highestGrade) {
      throw GradeTooHighException();
    }
    _grade--;
}
  
void Bureaucrat::DecrementGrade() {
    if (Bureaucrat::lowestGrade <= _grade + 1) {
        throw GradeTooLowException();
    }
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
       << ".";
    return os;
}

void Bureaucrat::signForm(AForm &form) const {
        try {
            form.beSigned(*this);
            std::cout << this->getName() << " signed " << form.getName() << std::endl;
        } catch (const std::exception &e) {
            std::cout << this->getName() << " couldn’t sign " << form.getName()
                                << " because " << e.what() << "." << std::endl;
        }
}

void Bureaucrat::executeForm(AForm const &form) const {
        try {
            form.execute(*this);
            std::cout << this->getName() << " executed " << form.getName() << std::endl;
        } catch (const std::exception &e) {
            std::cout << this->getName() << " couldn’t execute " << form.getName()
                                << " because " << e.what() << "." << std::endl;
        }
}
