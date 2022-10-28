/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:37:14 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 22:46:10 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined( __CAT_H__)
#define __CAT_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		/* Private Attributes */
		Brain *_pBrain;
	public:
		/* Constructors */
		Cat();
		Cat(const Cat& copy);
		/* Deconstructorss */
		~Cat();

		/* Overloaded Operators */
		Cat &operator=(const Cat &op);

		/* Public Methods */
		void makeSound() const;
		void gotIdea(std::string idea);
		void forgotIdea(std::string idea);
};

#endif // __CAT_H__