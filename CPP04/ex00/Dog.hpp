/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:37:14 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 22:46:10 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined( __DOG_H__)
#define __DOG_H__

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		/* Private Attributes */
	public:
		/* Constructors */
		Dog();
		Dog(const Dog& copy);
		/* Deconstructorss */
		~Dog();

		/* Overloaded Operators */
		Dog &operator=(const Dog &op);

		/* Public Methods */
		void makeSound() const;
};

#endif // __DOG_H__