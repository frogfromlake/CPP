/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:13:26 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 23:16:21 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
			const unsigned int invalid_grade = 3000;
			std::cout << ">> Creating Michael with an invalid Grade: (" << invalid_grade << ") which should throw an exception!" << std::endl;
			try
			{
				Bureaucrat Michael = Bureaucrat("Michael", invalid_grade);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << "\n~~~ Checking Exception in setGrade ~~~" << std::endl;
		{
			const unsigned int valid_grade = 30;
			std::cout << ">> Creating Michael with a valid Grade: (" << valid_grade << ")" << std::endl;

			Bureaucrat Michael = Bureaucrat("Michael", valid_grade);
			std::cout << Michael << std::endl;

			const unsigned int invalid_grade = 500;
			std::cout << ">> Setting invalid Grade for Michael: (" << invalid_grade << ") which should throw an exception!" << std::endl;
			try
			{
				Michael.setGrade(invalid_grade);
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

void CheckingForms()
{
	std::cout << "\n### Checking Bureaucrats / Grades / Forms and Exceptions ###\n" << std::endl;

	const unsigned int GradeToSign = 2;
	const unsigned int GradeToExecute = 2;

	std::cout << ">> Creating Form with a 'GradeToSign' of " << GradeToSign << " and a 'GradeToExecute' of " << GradeToExecute << std::endl;
	Form form = Form("Test-Form", GradeToSign, GradeToExecute);

	std::cout << "~~~ Checking Exception in beSigned ~~~" << std::endl;
	{
		const unsigned int BureaucratGrade = GradeToSign + 1;
		std::cout << ">> Creating Bureaucrat who can't sign the Form (Grade: " << BureaucratGrade << ")" << std::endl;

		Bureaucrat ExceptionMichael = Bureaucrat("ExceptionMichael", BureaucratGrade);

		std::cout << ExceptionMichael << " is trying to sign Form\n" << form << std::endl;
		try
		{
			form.beSigned(ExceptionMichael);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "\n~~~ Checking valid Bureaucrat to sign the Form ~~~" << std::endl;
	{
		const unsigned int BureaucratGrade = GradeToSign - 1;
		std::cout << ">> Creating Bureaucrat who can sign the Form (Grade: " << BureaucratGrade << ")" << std::endl;

		Bureaucrat Michael = Bureaucrat("Michael", BureaucratGrade);

		std::cout << Michael << " is trying to sign Form\n" << form << std::endl;
		try
		{
			Michael.signForm(form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << form << std::endl;
	}
}

int	main()
{
	validBureaucrat();

	invalidBureaucrat();

	CheckingForms();

	system("leaks Form");
	return 0;
}