/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 22:51:35 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___INTERN_HPP___)
#define ___INTERN_HPP___

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>
#include <exception>

class Intern
{
	private:
		/* private Members */
	public:
		/* Constructors */
		Intern();
		Intern(const Intern &copy);
		/* Destructors */
		~Intern();

		/* Overloaded Operators */
		Intern &operator=(const Intern &op);

		/* Public Methods */
		AForm *CreateShrubberyCreationForm(const std::string target) const;
		AForm *CreateRobotomyRequestForm(const std::string target) const;
		AForm *CreatePresidentialPardonForm(const std::string target) const;
		AForm *makeForm(std::string formName, std::string formTarget) const;

		/* Getter */
		
		/* Setter */
};

#endif // ___INTERN_HPP___