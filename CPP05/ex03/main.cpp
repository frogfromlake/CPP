/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:13:26 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 23:15:09 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#include <iostream>

const unsigned int highestGrade = 1, lowestGrade = 150;

void validBureaucrat()
{
	std::cout << "\n### Checking valid Bureaucrats ###\n\n";
	{
		std::cout << ">> Creating Michael with the default grade (150)" << std::endl;

		Bureaucrat Michael = Bureaucrat("Michael");
		std::cout << Michael << std::endl;

		std::cout << ">> Setting Grade of Michael to highest Grade (" << highestGrade << ")" << std::endl;
		try
		{
			Michael.setGrade(highestGrade);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << ">> Setting Grade of Michael to lowest Grade (" << lowestGrade << ")" << std::endl;
		try
		{
			Michael.setGrade(lowestGrade);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

void invalidBureaucrat()
{
	std::cout << "\n### Checking Invalid Grades / Bureaucrats ###\n\n";
	{
		std::cout << "~~~ Checking Exception in Constructor ~~~" << std::endl;
		{
			const unsigned int invalidGrade = 3000;
			std::cout << ">> Creating Michael with an invalid Grade: (" << invalidGrade << ") which should throw an exception!" << std::endl;
			try
			{
				Bureaucrat Michael = Bureaucrat("Michael", invalidGrade);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << "\n~~~ Checking Exception in setGrade ~~~" << std::endl;
		{
			const unsigned int validGrade = 30;
			std::cout << ">> Creating Michael with a valid Grade: (" << validGrade << ")" << std::endl;

			Bureaucrat Michael = Bureaucrat("Michael", validGrade);
			std::cout << Michael << std::endl;

			const unsigned int invalidGrade = 500;
			std::cout << ">> Setting invalid Grade for Michael: (" << invalidGrade << ") which should throw an exception!" << std::endl;
			try
			{
				Michael.setGrade(invalidGrade);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << "\n~~~ Checking Exception in incrementGrade" << std::endl;
		{
			std::cout << ">> Creating Michael with the highest possible Grade (" << highestGrade << ")" << std::endl;
			Bureaucrat Michael = Bureaucrat("Michael", highestGrade);

			std::cout << ">> Incrementing Grade to " << highestGrade - 1 << " which should throw an exception!" << std::endl;
			try
			{
				Michael.incrementGrade();
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << "\n~~~ Checking Exception in decrementGrade" << std::endl;
		{
			std::cout << ">> Creating Michael with the lowest possible Grade (" << lowestGrade << ")" << std::endl;
			Bureaucrat Michael = Bureaucrat("Michael", lowestGrade);

			std::cout << ">> Decrementing Grade to " << lowestGrade + 1 << " which should throw an exception!" << std::endl;
			try
			{
				Michael.decrementGrade();
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	}
}

void CheckingShrubberyForm()
{
	const unsigned int GradeToSign = 145, GradeToExec = 137;
	std::cout << "\n### Checking Shrubbery Creation Form ###\n" << std::endl;

	std::cout << ">> Creating ShrubberyCreationForm" << std::endl;

	ShrubberyCreationForm form = ShrubberyCreationForm("Earth");
	std::cout << form << std::endl;

	std::cout << ">> Creating 2 Bureaucrats (Signing and Execution)" << std::endl;
	Bureaucrat signer = Bureaucrat("Michael", GradeToSign - 1);
	Bureaucrat executor = Bureaucrat("Bernd", GradeToExec - 1);

	std::cout << ">> Trying to sign " << form << " with " << signer << std::endl;
	try
	{
		signer.signForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << ">> Trying to execute " << form << " with " << executor << std::endl;
	try
	{
		executor.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void CheckingRobotomyForm()
{
	const unsigned int GradeToSign = 72, GradeToExec = 45;
	std::cout << "\n### Checking Robotomy Request Form ###\n" << std::endl;

	std::cout << ">> Creating RobotomyRequestForm" << std::endl;

	RobotomyRequestForm form = RobotomyRequestForm("Thunderbite");
	std::cout << form << std::endl;

	std::cout << ">> Creating 2 Bureaucrats (Signing and Execution)" << std::endl;
	Bureaucrat signer = Bureaucrat("Michael", GradeToSign - 1);
	Bureaucrat executor = Bureaucrat("Bernd", GradeToExec - 1);

	std::cout << ">> Trying to sign " << form << " with " << signer << std::endl;
	try
	{
		signer.signForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << ">> Trying to execute " << form << " with " << executor << std::endl;
	try
	{
		executor.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void CheckingPresidentialForm()
{
	const unsigned int GradeToSign = 25, GradeToExec = 5;
	std::cout << "\n### Checking Presidential Pardon Form ###\n" << std::endl;

	std::cout << ">> Creating PresidentialPardonForm" << std::endl;

	PresidentialPardonForm form = PresidentialPardonForm("Fabian Quist");
	std::cout << form << std::endl;

	std::cout << ">> Creating 2 Bureaucrats (Signing and Execution)" << std::endl;
	Bureaucrat signer = Bureaucrat("Michael", GradeToSign - 1);
	Bureaucrat executor = Bureaucrat("Bernd", GradeToExec - 1);

	std::cout << ">> Trying to sign " << form << " with " << signer << std::endl;
	try
	{
		signer.signForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << ">> Trying to execute " << form << " with " << executor << std::endl;
	try
	{
		executor.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void CheckingIntern()
{
	std::cout << "\n### Checking Interns ###\n" << std::endl;
	
	Intern Pickel = Intern();
	
	AForm *tmp;
	
	std::cout << "~~~ Checking Interns makeForm() valid input ~~~\n" << std::endl;
	std::cout << ">> Intern creating all Forms" << std::endl;
	tmp = Pickel.makeForm("ShrubberyCreationForm", "Fabian Quist");
	
	std::cout << "Form: " << (*tmp).getName() << " is";
	(*tmp).getSignatureStatus() ? std::cout << " " : std::cout << " not ";
	std::cout << "signed. (Grade to Sign: " << (*tmp).getReqGradeSign() << ", Grade to Execute: " << (*tmp).getReqGradeExec() << ")" << std::endl;

	delete tmp;

	tmp = Pickel.makeForm("RobotomyRequestForm", "Fabian Quist");
	
	std::cout << "Form: " << (*tmp).getName() << " is";
	(*tmp).getSignatureStatus() ? std::cout << " " : std::cout << " not ";
	std::cout << "signed. (Grade to Sign: " << (*tmp).getReqGradeSign() << ", Grade to Execute: " << (*tmp).getReqGradeExec() << ")" << std::endl;

	delete tmp;

	tmp = Pickel.makeForm("PresidentialPardonForm", "Fabian Quist");
	
	std::cout << "Form: " << (*tmp).getName() << " is";
	(*tmp).getSignatureStatus() ? std::cout << " " : std::cout << " not ";
	std::cout << "signed. (Grade to Sign: " << (*tmp).getReqGradeSign() << ", Grade to Execute: " << (*tmp).getReqGradeExec() << ")" << std::endl;

	delete tmp;

	std::cout << "\n~~~ Checking Interns makeForm() invalid input ~~~\n" << std::endl;
	std::cout << ">> Intern creating empty Form" << std::endl;
	tmp = Pickel.makeForm("", "");
	
	if (tmp)
	{
		std::cout << "Form: " << (*tmp).getName() << " is";
		(*tmp).getSignatureStatus() ? std::cout << " " : std::cout << " not ";
		std::cout << "signed. (Grade to Sign: " << (*tmp).getReqGradeSign() << ", Grade to Execute: " << (*tmp).getReqGradeExec() << ")" << std::endl;

		delete tmp;
	}

	std::cout << ">> Intern creating unknown Form" << std::endl;
	tmp = Pickel.makeForm("ShrubberyPresidentialRobotomy", "Fabian Quist");
	
	if (tmp)
	{
		std::cout << "Form: " << (*tmp).getName() << " is";
		(*tmp).getSignatureStatus() ? std::cout << " " : std::cout << " not ";
		std::cout << "signed. (Grade to Sign: " << (*tmp).getReqGradeSign() << ", Grade to Execute: " << (*tmp).getReqGradeExec() << ")" << std::endl;

		delete tmp;
	}
}	

int	main()
{
	validBureaucrat();

	invalidBureaucrat();

	CheckingShrubberyForm();
	
	CheckingRobotomyForm();
	
	CheckingPresidentialForm();
	
	CheckingIntern();

	system("leaks Intern");
	return 0;
}