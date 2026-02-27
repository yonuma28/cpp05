#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
  {
    std::cout << "-------------------OK-------------------\n";
    try {
      Bureaucrat a = Bureaucrat("a", 149);
      std::cout << a << std::endl;
      a.DecrementGrade();
      std::cout << a << std::endl;
      a.IncrementGrade();
      std::cout << a << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
	try {
		Bureaucrat b = Bureaucrat("b", 2);
		std::cout << b << std::endl;
		b.IncrementGrade();
		std::cout << b << std::endl;
		b.DecrementGrade();
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
  }

  std::cout << '\n';
  {
    std::cout
        << "-------------------Grade is too low test-------------------\n";
    try {
      Bureaucrat a = Bureaucrat("a", Bureaucrat::lowestGrade);
      std::cout << a << std::endl;
      a.DecrementGrade();
      std::cout << a << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  std::cout << '\n';
  {
    std::cout
        << "-------------------Grade is too high test-------------------\n";
    try {
      Bureaucrat b = Bureaucrat("b", Bureaucrat::highestGrade);
      std::cout << b << std::endl;
      b.IncrementGrade();
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
}
