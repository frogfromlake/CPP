/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 16:41:35 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___BUREAUCRAT_HPP___)
#define ___BUREAUCRAT_HPP___

#include "AForm.hpp"
class AForm;

#include <string>
#include <exception>

class Bureaucrat
{
	private:
		/* Private Attributes */
		const std::string _name;
		unsigned int _grade;
	public:
		/* Constructors */
		Bureaucrat();
		Bureaucrat(const std::string &name, unsigned int grade = 150);
		Bureaucrat(const Bureaucrat &copy);
		/* Destructors */
		~Bureaucrat();

		/* Overloaded Operators */
		Bureaucrat &operator=(const Bureaucrat &op);

		/* Public Methods */
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form) const;

		/* Getter */
		std::string getName() const;
		unsigned int getGrade() const;
		void executeForm(AForm const &form);

		/* Setter */
		void setGrade(unsigned int grade);

		/* Exceptions */
		struct GradeTooLowException : public std::exception
		{
			const char *what() const throw()
			{
				return "GradeTooLowException";
			}
		};

		struct GradeTooHighException : public std::exception
		{
			const char *what() const throw()
			{
				return "GradeTooHighException";
			}
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bc);

#endif // ___BUREAUCRAT_HPP___