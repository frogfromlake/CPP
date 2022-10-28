/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 16:53:42 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <cstdlib>
// #include <ctime>

/* Constructors */
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45)
{
	this->_target = "undefined";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {}

/* Destructors */
RobotomyRequestForm::~RobotomyRequestForm() {}

/* Overloaded Operators */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &op)
{
	if (this == &op)
		return *this;

	return *this;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form)
{
	os << "Form " << form.getName() << " is";
	form.getSignatureStatus() ? os << " " : os << " not ";
	os << "signed (Sign Grade: " << form.getReqGradeSign() << ", Execution Grade: " << form.getReqGradeExec() << ", Target: " << form.getTarget() << ")";
	return os;
}

/* Public Methods */
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);

	std::cout << "BrrrRRRrrrRRRrrrRRRrrr..." << std::endl;

	std::srand(time(NULL));
	int rand = std::rand() % 100;
	std::string result = "";

	if (rand > 50)
		result = "successfull!";
	else
		result = "failed!";

	std::cout << "Robotomy of " << this->getTarget() << " " << result << std::endl;
}

/* Getter */
std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

/* Setter */
void RobotomyRequestForm::setTarget(std::string target)
{
	this->_target = target;
}
