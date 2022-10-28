/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 22:46:12 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___CURE_HPP___)
#define ___CURE_HPP___

#include "AMateria.hpp"

#include <string>

class Cure : public AMateria
{
	private:
		/* Private Attributes */
	public:
		/* Constructors */
		Cure();
		Cure(const Cure &copy);
		Cure(const std::string &type);

		/* Destructors */
		~Cure();

		/* Overloaded Operators */
		Cure &operator=(const Cure &op);

		/* Public Methods */
		AMateria *clone() const;
		void use(ICharacter &target);

		/* Getter */
		const std::string &getType() const;

		/* Setter */
};

#endif // ___CURE_HPP___