/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:23:52 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 22:46:09 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___DIAMONDTRAP_HPP___)
#define ___DIAMONDTRAP_HPP___

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		/* Private Attributes */
		std::string _name;
	public:
		/* Constructors */
		DiamondTrap();
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap &copy );
		/* Deconstructorss */
		~DiamondTrap();

		/* Overloaded Operators */
		DiamondTrap &operator=( const DiamondTrap &op );

		/* Public Methods */
		void whoAmI();
};

#endif // ___DiamondTrap_HPP___