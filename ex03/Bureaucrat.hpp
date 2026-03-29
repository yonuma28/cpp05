#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
  private:
    const std::string _name;
    int _grade;

    Bureaucrat();

  public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void IncrementGrade();
    void DecrementGrade();
    void signForm(AForm &form) const;
    void executeForm(const AForm &form) const;

    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    static const int highestGrade = 1;
    static const int lowestGrade = 150;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
