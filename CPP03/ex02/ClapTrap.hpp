/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 09:17:51 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 22:46:29 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___CLAP_TRAP_HPP___)
#define ___CLAP_TRAP_HPP___

#include <iostream>
#include <climits>

class ClapTrap
{
	protected:
		/* Protected Attributes */
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		/* Constructors */
		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap(const ClapTrap& copy);
		~ClapTrap();

		/* Overloaded Operators */
		ClapTrap &operator=(const ClapTrap &op);

		/* Public Methods */
		void	attack(const std::string &target);
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};

#endif // ___CLAP_TRAP_HPP___