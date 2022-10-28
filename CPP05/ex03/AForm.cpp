/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 14:10:23 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>

/* Constructors */
AForm::AForm() : _name("undefined"), _signed(false), _reqGradeSign(1), _reqGradeExec(1)
{

}

AForm::AForm(const std::string name, const unsigned int reqGradeSign, const unsigned int reqGradeExec) : _name(name), _reqGradeSign(reqGradeSign), _reqGradeExec(reqGradeExec)
{
	this->_signed = false;
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), _signed(copy.getSignatureStatus()), _reqGradeSign(copy.getReqGradeSign()), _reqGradeExec(copy.getReqGradeExec())
{

}

/* Destructors */
AForm::~AForm()
{
	
}

/* Overloaded Operators */
AForm &AForm::operator=(const AForm &op)
{
	if (this == &op)
		return *this;

	return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "AForm " << form.getName() << " is";
	form.getSignatureStatus() ? os << " " : os << " not ";
	os << "signed (GradeToSign: " << form.getReqGradeSign() << ", GradeToExecute: " << form.getReqGradeExec() << ")";
	return os;
}

/* Public Methods */
void AForm::beSigned(const Bureaucrat &bc)
{
	if (this->getReqGradeSign() <= bc.getGrade())
		throw AForm::GradeTooLowException();

	this->_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw AForm::FormNotSignedException();

	if (this->getReqGradeExec() < executor.getGrade())
		throw AForm::GradeTooLowException();
}

/* Getter */
std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSignatureStatus() const
{
	return this->_signed;
}

unsigned int AForm::getReqGradeSign() const
{
	return this->_reqGradeSign;
}

unsigned int AForm::getReqGradeExec() const
{
	return this->_reqGradeExec;
}

/* Setter */
