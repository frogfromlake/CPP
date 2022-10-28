/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 16:08:07 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___PRESIDENTIALPARDONFORM_HPP___)
#define ___PRESIDENTIALPARDONFORM_HPP___

#include "AForm.hpp"

#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		/* private Members */
		std::string _target;
	public:
		/* Constructors */
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		/* Destructors */
		 ~PresidentialPardonForm();

		/* Overloaded Operators */
		PresidentialPardonForm &operator=(const PresidentialPardonForm &op);

		/* Public Methods */
		void execute(Bureaucrat const &executor) const;
	
		/* Getter */
		std::string getTarget() const;

		/* Setter */
		void setTarget(std::string target);
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form);

#endif // ___PRESIDENTIALPARDONFORM_HPP___