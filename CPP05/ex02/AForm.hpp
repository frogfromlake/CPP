/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/22 14:10:10 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___AFORM_HPP___)
#define ___AFORM_HPP___

#include "Bureaucrat.hpp"
class Bureaucrat;

#include <string>
#include <exception>


class AForm
{
	private:
		/* Private Attributes */
		const std::string _name;
		bool _signed;
		const unsigned int _reqGradeSign;
		const unsigned int _reqGradeExec;
	public:
		/* Constructors */
		AForm();
		AForm(const std::string name, const unsigned int reqGradeSign, const unsigned int reqGradeExec);
		AForm(const AForm &copy);
		/* Destructors */
		~AForm();

		/* Overloaded Operators */
		AForm &operator=(const AForm &op);

		/* Public Methods */
		void beSigned(const Bureaucrat &bc);
		virtual void execute(Bureaucrat const &executor) const;

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

		struct FormNotSignedException : public std::exception
		{
			const char *what() const throw()
			{
				return "FormNotSignedException";
			}
		};
};

#endif // ___AFORM_HPP___