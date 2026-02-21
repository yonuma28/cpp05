# include "Bureaucrat.hpp"
# include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    if (this != &rhs) {
        this->_grade = rhs._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << "." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cerr << _name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << "." << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
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
