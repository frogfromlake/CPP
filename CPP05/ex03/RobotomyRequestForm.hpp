/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 15:47:25 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___ROBOTOMYREQUESTFORM_HPP___)
#define ___ROBOTOMYREQUESTFORM_HPP___

#include "AForm.hpp"

#include <string>

class RobotomyRequestForm : public AForm
{
	private:
		/* private Members */
		std::string _target;
	public:
		/* Constructors */
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		/* Destructors */
		~RobotomyRequestForm();

		/* Overloaded Operators */
		RobotomyRequestForm &operator=(const RobotomyRequestForm &op);

		/* Public Methods */
		void execute(Bureaucrat const &executor) const;

		/* Getter */
		std::string getTarget() const;

		/* Setter */
		void setTarget(std::string target);
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form);

#endif // ___ROBOTOMYREQUESTFORM_HPP___