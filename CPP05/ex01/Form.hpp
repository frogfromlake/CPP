/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 23:45:42 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___FORM_HPP___)
#define ___FORM_HPP___

#include "Bureaucrat.hpp"
class Bureaucrat;

#include <string>
#include <exception>


class Form
{
	private:
		/* Private Attributes */
		const std::string _name;
		bool _signed;
		const unsigned int _reqGradeSign;
		const unsigned int _reqGradeExec;
	public:
		/* Constructors */
		Form();
		Form(const std::string name, const unsigned int reqGradeSign, const unsigned int reqGradeExec);
		Form(const Form &copy);
		/* Destructors */
		~Form();

		/* Overloaded Operators */
		Form &operator=(const Form &op);

		/* Public Methods */
		void beSigned(const Bureaucrat &bc);

		/* Getter */
		std::string getName() const;
		bool getSignatureStatus() const;
		unsigned int getReqGradeSign() const;
		unsigned int getReqGradeExec() const;

		/* Setter */

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

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif // ___FORM_HPP___