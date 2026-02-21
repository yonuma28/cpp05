#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", "default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::performAction() const {
    std::string filename = this->getTarget() + "_shrubbery";
    std::ofstream ofs(filename.c_str());

    if (!ofs.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    ofs << "         v" << std::endl;
    ofs << "        >X<" << std::endl;
    ofs << "         A" << std::endl;
    ofs << "        d$b" << std::endl;
    ofs << "      .d\\$$b." << std::endl;
    ofs << "    .d$i$$\\$$b." << std::endl;
    ofs << "       d$$@b" << std::endl;
    ofs << "      d\\$$$ib" << std::endl;
    ofs << "    .d$$$\\$$$b" << std::endl;
    ofs << "  .d$$@$$$$\\$$ib." << std::endl;
    ofs << "      |||||" << std::endl;

    ofs.close();
}
