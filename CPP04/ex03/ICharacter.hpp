/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:48:45 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 16:40:13 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___ICHARACTER_HPP___)
#define ___ICHARACTER_HPP___

#include <string>
#include "AMateria.hpp"

class ICharacter
{
	public:
		/* Deconstructors */
		virtual ~ICharacter() {}

		/* Constructors */
		
		/* Public Methods */
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
		
		/* Getter */
		virtual std::string const & getName() const = 0;
};

#endif // ___ICHARACTER_HPP___