/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:37:14 by nelix             #+#    #+#             */
/*   Updated: 2022/08/18 22:14:26 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___WRONGCAT_HPP___)
#define ___WRONGCAT_HPP___

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		/* Private Attributes */
	public:
		/* Constructors */
		WrongCat();
		WrongCat(const WrongCat& copy);
		/* Deconstructors */
		~WrongCat();

		/* Overloaded Operators */
		WrongCat &operator=(const WrongCat &op);

		/* Public Methods */
		void makeSound() const;
};

#endif // __WRONGCAT_HPP__