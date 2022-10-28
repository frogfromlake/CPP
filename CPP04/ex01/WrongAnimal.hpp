/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:40:13 by nelix             #+#    #+#             */
/*   Updated: 2022/08/18 23:35:40 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___WRONGANIMAL_HPP___)
#define ___WRONGANIMAL_HPP___

#include <string>

class WrongAnimal
{
	protected:
		/* Protected Attributes */
		std::string _type;
	public:
		/* Constructors */
		WrongAnimal();
		WrongAnimal( const WrongAnimal &copy);
		/* Deconstructors */
		virtual ~WrongAnimal();

		/* Overloaded Operators */
		WrongAnimal &operator=( const WrongAnimal &op );

		/* Public Methods */
		void	makeSound() const;

		/* Getter */
		std::string getType() const;
};

#endif // ___WrongAnimal_HPP___