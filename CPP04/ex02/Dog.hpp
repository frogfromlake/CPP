/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:37:14 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 22:46:12 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined( __DOG_H__)
#define __DOG_H__

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		/* Private Attributes */
		Brain *_pBrain;
	public:
		/* Constructors */
		Dog();
		Dog(const Dog &copy);
		/* Deconstructorss */
		~Dog();

		/* Overloaded Operators */
		Dog &operator=(const Dog &op);

		/* Public Methods */
		void makeSound() const;
		void gotIdea(std::string idea);
		void forgotIdea(std::string idea);

		/* Getter */
		std::string getType() const;
};

#endif // __DOG_H__