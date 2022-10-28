/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/31 16:08:48 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___ICE_HPP___)
#define ___ICE_HPP___

#include "AMateria.hpp"

#include <string>

class Ice : public AMateria
{
	private:
		/* Private Attributes */
	public:
		/* Constructors */
		Ice();
		Ice(const Ice &copy);
		Ice(const std::string &type);
		/* Destructors */
		~Ice();

		/* Overloaded Operators */
		Ice &operator=(const Ice &op);

		/* Public Methods */
		AMateria *clone() const;
		void use(ICharacter &target);

		/* Getter */
		const std::string &getType() const;

		/* Setter */
};

#endif // ___ICE_HPP___