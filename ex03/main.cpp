#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    Bureaucrat boss("boss", 1);

    try
    {
        AForm *shrubbery = intern.makeForm("shrubbery creation", "home");
        boss.signForm(*shrubbery);
        boss.executeForm(*shrubbery);
        delete shrubbery;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        AForm *robotomy = intern.makeForm("robotomy request", "Bender");
        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);
        delete robotomy;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        AForm *pardon = intern.makeForm("presidential pardon", "Ford Prefect");
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
        delete pardon;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        AForm *unknown = intern.makeForm("coffee request", "Arthur Dent");
        delete unknown;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
