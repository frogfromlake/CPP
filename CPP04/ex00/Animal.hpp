/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:40:13 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 22:46:29 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___ANIMAL_HPP___)
#define ___ANIMAL_HPP___

#include <string>

class Animal
{
	protected:
		/* Protected Attributes */
		std::string _type;
	public:
		/* Constructors */
		Animal();
		Animal( const Animal &copy);
		/* Deconstructorss */
		virtual ~Animal();

		/* Overloaded Operators */
		Animal &operator=( const Animal &op );

		/* Public Methods */
		virtual void	makeSound() const;

		/* Getter */
		std::string getType() const;
};

#endif // ___ANIMAL_HPP___