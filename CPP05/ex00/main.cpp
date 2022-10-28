/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:13:26 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 23:16:48 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

int	main()
{
	validBureaucrat();

	invalidBureaucrat();

	system("leaks Bureaucrat");
	return 0;
}