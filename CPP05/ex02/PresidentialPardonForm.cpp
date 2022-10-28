/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 16:19:26 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

/* Constructors */
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5)
{
	this->_target = "undefined";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) {}

/* Destructors */
PresidentialPardonForm::~PresidentialPardonForm() {}

/* Overloaded Operators */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &op)
{
	if (this == &op)
		return *this;

	return *this;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form)
{
	os << "Form " << form.getName() << " is";
	form.getSignatureStatus() ? os << " " : os << " not ";
	os << "signed (Sign Grade: " << form.getReqGradeSign() << ", Execution Grade: " << form.getReqGradeExec() << ", Target: " << form.getTarget() << ")";
	return os;
}

/* Public Methods */
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}

/* Getter */
std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

/* Setter */
void PresidentialPardonForm::setTarget(std::string target)
{
	this->_target = target;
}
