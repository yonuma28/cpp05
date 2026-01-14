#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class AForm;

class Bureaucrat
{
    private:
        const std::string   _name;  // 官僚の名前
        unsigned int        _grade; // 1から150の間

        Bureaucrat();

    public:
        // OCM
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();

        // ゲッター
        // 官僚の名前を得る
        const std::string&  getName() const;
        // グレードを得る
        unsigned int        getGrade() const;

        // gradeの操作
        void    IncrementGrade();
        void    DecrementGrade();

        // 例外クラス
        // 上の例外を確認
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        // 下の例外を確認
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        static const int highestGrade = 1;
        static const int lowestGrade = 150;

        // ex02
        void    signForm(AForm &form) const;
        void    executeForm(AForm const &form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif //BUREAUCRAT_HPP
