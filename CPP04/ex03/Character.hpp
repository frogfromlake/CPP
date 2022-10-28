/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 22:46:12 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___CHARACTER_HPP___)
#define ___CHARACTER_HPP___

#include "ICharacter.hpp"

#include <string>

class Character : public ICharacter
{
	private:
		/* Private Attributes */
		static const unsigned int _invSlots = 4;
		AMateria *_inventory[_invSlots];
		std::string _name;
	public:
		/* Constructors */
		Character();
		Character(const std::string &name);
		Character(const Character &copy);
		/* Destructors */
		~Character();

		/* Overloaded Operators */
		Character &operator=(const Character &op);

		/* Public Methods */
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		/* Getter */
		virtual std::string const & getName() const;

		/* Setter */
};

#endif // ___CHARACTER_HPP___