#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::performAction() const
{
    std::ofstream output((_target + "_shrubbery").c_str());

    if (!output.is_open())
        throw std::runtime_error("failed to create shrubbery file");
    output << "       _-_" << std::endl;
    output << "    /~~   ~~\\" << std::endl;
    output << " /~~         ~~\\" << std::endl;
    output << "{               }" << std::endl;
    output << " \\  _-     -_  /" << std::endl;
    output << "   ~  \\\\ //  ~" << std::endl;
    output << "_- -   | | _- _" << std::endl;
    output << "  _ -  | |   -_" << std::endl;
    output << "      // \\\\" << std::endl;
}
