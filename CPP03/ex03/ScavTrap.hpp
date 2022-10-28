/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:41:40 by nelix             #+#    #+#             */
/*   Updated: 2022/09/01 14:52:32 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(__SCAVTRAP_HPP__)
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	private:
		/* Private Attributes */
	public:
		/* Constructors */
		ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &copy );
		/* Deconstructorss */
		~ScavTrap();

		/* Overloaded Operators */
		ScavTrap &operator=(const ScavTrap &op);

		/* Public Members */
		void guardGate();
		void attack(const std::string &target);
};

#endif // __SCAVTRAP_HPP__