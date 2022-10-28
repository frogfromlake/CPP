/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 23:14:44 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

/* Constructors */
Intern::Intern() {}

Intern::Intern(const Intern &copy) {(void)copy;}

/* Destructors */
Intern::~Intern() {}

/* Overloaded Operators */
Intern &Intern::operator=(const Intern &op)
{
	if (this == &op)
		return *this;

	return *this;
}

/* Public Methods */
AForm *Intern::CreateShrubberyCreationForm(const std::string target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::CreateRobotomyRequestForm(const std::string target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::CreatePresidentialPardonForm(const std::string target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) const
{
	if (formName.empty() || formTarget.empty())
	{
		std::cerr << "Error: Invalid Input: Input must not be empty." << std::endl;
		return NULL;
	}

	static const std::string knownForms[] = 
	{
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

	static AForm *(Intern::* const functionsArray[])(const std::string target) const =
	{
		&Intern::CreateShrubberyCreationForm,
		&Intern::CreateRobotomyRequestForm,
		&Intern::CreatePresidentialPardonForm
	};

	for (size_t i = 0; i < knownForms->length(); i++)
	{
		if (formName == knownForms[i])
			return (this->*functionsArray[i])(formTarget);
	}
	
	std::cerr << "Error: " << formName << " for " << formTarget << " not found." << std::endl;
	return NULL;
}


/* Getter */

/* Setter */