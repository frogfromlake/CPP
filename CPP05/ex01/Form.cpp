/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 23:52:19 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

/* Constructors */
Form::Form() : _name("undefined"), _signed(false), _reqGradeSign(1), _reqGradeExec(1)
{

}

Form::Form(const std::string name, const unsigned int reqGradeSign, const unsigned int reqGradeExec) : _name(name), _reqGradeSign(reqGradeSign), _reqGradeExec(reqGradeExec)
{
	this->_signed = false;
}

Form::Form(const Form &copy) : _name(copy.getName()), _signed(copy.getSignatureStatus()), _reqGradeSign(copy.getReqGradeSign()), _reqGradeExec(copy.getReqGradeExec())
{

}

/* Destructors */
Form::~Form()
{
	
}

/* Overloaded Operators */
Form &Form::operator=(const Form &op)
{
	if (this == &op)
		return *this;

	return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName() << " is";
	form.getSignatureStatus() ? os << " " : os << " not ";
	os << "signed (GradeToSign: " << form.getReqGradeSign() << ", GradeToExecute: " << form.getReqGradeExec() << ")";
	return os;
}

/* Public Methods */
void Form::beSigned(const Bureaucrat &bc)
{
	if (this->getReqGradeSign() <= bc.getGrade())
		throw Form::GradeTooLowException();

	this->_signed = true;
}

/* Getter */
std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSignatureStatus() const
{
	return this->_signed;
}

unsigned int Form::getReqGradeSign() const
{
	return this->_reqGradeSign;
}

unsigned int Form::getReqGradeExec() const
{
	return this->_reqGradeExec;
}

/* Setter */
