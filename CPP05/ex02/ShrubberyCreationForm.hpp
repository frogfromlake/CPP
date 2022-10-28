/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 14:29:45 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___SHRUBBERYCREATIONFORM_HPP___)
#define ___SHRUBBERYCREATIONFORM_HPP___

#include "AForm.hpp"

#include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		/* private Members */
		std::string _target;
	public:
		/* Constructors */
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		/* Destructors */
		~ShrubberyCreationForm();

		/* Overloaded Operators */
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &op);

		/* Public Methods */
		void execute(Bureaucrat const &executor) const;

		/* Getter */
		std::string getTarget() const;

		/* Setter */
		void setTarget(std::string target);
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form);

#endif // ___SHRUBBERYCREATIONFORM_HPP___