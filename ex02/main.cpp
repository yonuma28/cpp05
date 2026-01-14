#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void printSeparator(std::string message) {
  std::cout << "---------------------" << message << "---------------------"
            << std::endl;
}

int main(void) {
  printSeparator("test ShrubberyCreationForm");
  {
    ShrubberyCreationForm a("garden");
    Bureaucrat b = Bureaucrat("b", 1);
    b.signForm(a);
    b.executeForm(a);
    std::cout << '\n';
  }
  {
    printSeparator("exception form not signed");
    ShrubberyCreationForm a("garden");
    Bureaucrat b = Bureaucrat("b", 1);
    try {
      b.executeForm(a);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
    std::cout << '\n';
  }
  {
    printSeparator("exception grade is too low");
    ShrubberyCreationForm a("garden");
    Bureaucrat b = Bureaucrat("b", 138);
    try {
      b.signForm(a);
      b.executeForm(a);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  std::cout << "\n\n";
  printSeparator("test RobotomyRequestForm");
  {
    RobotomyRequestForm a("marvin");
    Bureaucrat b = Bureaucrat("b", 1);
    try {
      b.signForm(a);
      b.executeForm(a);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
    std::cout << '\n';
  }
  {
    printSeparator("exception form not signed");
    RobotomyRequestForm a("marvin");
    Bureaucrat b = Bureaucrat("b", 1);
    try {
      b.executeForm(a);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
    std::cout << '\n';
  }
  {
    printSeparator("exception grade is too low");
    RobotomyRequestForm a("marvin");
    Bureaucrat b = Bureaucrat("b", 46);
    try {
      b.signForm(a);
      b.executeForm(a);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  std::cout << "\n\n";
  printSeparator("test PresidentialPardonForm");
  {
    PresidentialPardonForm a("trillian");
    Bureaucrat b = Bureaucrat("b", 1);
    try {
      b.signForm(a);
      b.executeForm(a);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
    std::cout << '\n';
  }
  {
    printSeparator("exception form not signed");
    PresidentialPardonForm a("trillian");
    Bureaucrat b = Bureaucrat("b", 1);
    try {
      b.executeForm(a);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
    std::cout << '\n';
  }
  {
    printSeparator("exception grade is too low");
    PresidentialPardonForm a("trillian");
    Bureaucrat b = Bureaucrat("b", 6);
    try {
      b.signForm(a);
      b.executeForm(a);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
}
