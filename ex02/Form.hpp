#ifndef FORM_HPP
 # define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        unsigned int        _signGrade;
        unsigned int        _execGrade;

    public:
        // OCF
        Form(const std::string& name, int signGrade, int execGrade);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();

        //getter
        const std::string&  getName() const;
        bool          getSigned() const;
        unsigned int  getRequiredSign() const;
        unsigned int  getRequiredExecute() const;

        //ex02
        void    beSigned(const Bureaucrat& Bureaucrat);

        //error
        class GradeTooHighException : public std::exception {
            virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            virtual const char *what() const throw();
        };

        static const int highestGrade = 1;
        static const int lowestGrade = 150;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

# endif //FORM_HPP
