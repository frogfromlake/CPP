/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 16:55:36 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

/* Constructors */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{
	this->_target = "undefined";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {}

/* Destructors */
ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* Overloaded Operators */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &op)
{
	if (this == &op)
		return *this;

	return *this;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form)
{
	os << "Form " << form.getName() << " is";
	form.getSignatureStatus() ? os << " " : os << " not ";
	os << "signed (Sign Grade: " << form.getReqGradeSign() << ", Execution Grade: " << form.getReqGradeExec() << ", Target: " << form.getTarget() << ")";
	return os;
}

/* Public Methods */
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);

	std::ofstream shrubbery;
	shrubbery.open((this->_target + "_shrubbery").c_str());
	shrubbery << "        _-_" << std::endl;
	shrubbery << "     /~~   ~~\\" << std::endl;
	shrubbery << "  /~~         ~~\\" << std::endl;
	shrubbery << " {               }" << std::endl;
	shrubbery << "  \\  _-     -_  /" << std::endl;
	shrubbery << "    ~  \\\\ //  ~" << std::endl;
	shrubbery << " _- -   | | _- _" << std::endl;
	shrubbery << "   _ -  | |   -_" << std::endl;
	shrubbery << "       // \\\\" << std::endl;
	shrubbery.close();
}

/* Getter */
std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

/* Setter */
void ShrubberyCreationForm::setTarget(std::string target)
{
	this->_target = target;
}
