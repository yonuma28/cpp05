#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        const std::string _target;
        bool              _isSigned;
        const int         _signGrade;
        const int         _execGrade;

    public:
        AForm(const std::string& name, const std::string& target, int signGrade, int execGrade);
        virtual ~AForm();
        AForm& operator=(const AForm& copy);
        AForm(const AForm& copy);

        // getter
        const std::string& getName() const;
        const std::string& getTarget() const;
        bool getSigned() const;
        unsigned int getSignGrade() const;
        unsigned int getExecGrade() const;

        void beSigned(const Bureaucrat& b);
        
        void execute(Bureaucrat const & executor) const;
        virtual void performAction() const = 0; 

        //exception
        class GradeTooHighException : public std::exception {
            public: virtual const char* what() const throw() { return "Grade too high"; }
        };
        class GradeTooLowException : public std::exception {
            public: virtual const char* what() const throw() { return "Grade too low"; }
        };
        class FormNotSignedException : public std::exception {
            public: virtual const char* what() const throw() { return "Form is not signed"; }
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
