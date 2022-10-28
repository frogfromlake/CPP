/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 23:12:50 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

/* Constructors */
Bureaucrat::Bureaucrat() : _name("undefined")
{
	try
	{
		this->setGrade(150);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : _name(name)
{
	try
	{
		this->setGrade(grade);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
	try
	{
		this->setGrade(copy.getGrade());
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/* Destructors */
Bureaucrat::~Bureaucrat()
{

}

/* Overloaded Operators */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &op)
{
	if (this == &op)
		return *this;

	try
	{
		this->setGrade(op.getGrade());
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bc)
{
	os << "Bureaucrat: " << bc.getName() << ", [Grade: " << bc.getGrade() << "]";
	return os;
}

/* Public Methods */
void Bureaucrat::incrementGrade()
{
	try
	{
		this->setGrade(this->getGrade() - 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		this->setGrade(this->getGrade() + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception &e)
	{
		std::cerr << this->_name
				  << " couldn't sign the form: '" << form.getName()
				  << "' because of: " << e.what() << std::endl;
		return;
	}
	std::cout << "Bureaucrat '" << this->_name
			  << "' signed the form: '" << form.getName() << "'" << std::endl;
}

/* Getter */
std::string Bureaucrat::getName() const
{
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const
{
	return this->_grade;
}

/* Setter */
void Bureaucrat::setGrade(unsigned int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}
