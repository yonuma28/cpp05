#ifndef AForm_HPP
 # define AForm_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const unsigned int        _signGrade;
        const unsigned int        _execGrade;

    public:
        // OCF
        AForm(const std::string& name, const int signGrade, const int execGrade);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        ~AForm();

        //getter
        const std::string&  getName() const;
        bool          getSigned() const;
        unsigned int  getRequiredSign() const;
        unsigned int  getRequiredExecute() const;

        //ex02
        void    beSigned(const Bureaucrat& bureaucrat);
        void    execute(const Bureaucrat& executor) const;

        //error
        class GradeTooHighException : public std::exception {
            virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            virtual const char *what() const throw();
        };
        class NotSigned : public std::exception {
            virtual const char *what() const throw();
        };

        static const int highestGrade = 1;
        static const int lowestGrade = 150;

    protected:
        virtual void    performAction() const = 0;    
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

# endif //AForm_HPP
