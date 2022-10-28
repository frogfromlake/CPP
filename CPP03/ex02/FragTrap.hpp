/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:19:49 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 22:46:12 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(__FRAGTRAP_HPP__)
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		/* Private Attributes */
	public:
		/* Constructors */
		FragTrap();
		FragTrap( std::string name );
		FragTrap( const FragTrap &copy );
		/* Deconstructors */
		~FragTrap();

		/* Overloaded Operators */
		FragTrap &operator=( const FragTrap &op );

		/* Public Methods */
		void highFivesGuys(void);
};

#endif // __FRAGTRAP_HPP__