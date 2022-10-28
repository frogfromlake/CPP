/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:37:14 by nelix             #+#    #+#             */
/*   Updated: 2022/08/18 22:10:35 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___WRONGDOG_HPP___)
#define ___WRONGDOG_HPP___

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	private:
		/* Private Attributes */
	public:
		/* Constructors */
		WrongDog();
		WrongDog(const WrongDog& copy);
		/* Deconstructors */
		~WrongDog();

		/* Overloaded Operators */
		WrongDog &operator=(const WrongDog &op);

		/* Public Methods */
		void makeSound() const;
};

#endif // __WRONGDOG_HPP__