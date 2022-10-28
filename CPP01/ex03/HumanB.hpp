/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:54:13 by fquist            #+#    #+#             */
/*   Updated: 2022/07/29 17:37:40 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <iostream>
#include <string>
#include "Weapon.hpp"

# define PURPLE std::cout << "\033[0;35m"
# define RED std::cout << "\033[0;31m"
# define RESET "\033[0m" << std::endl

class HumanB {
	
	private:

		Weapon *_Club;
		std::string _Name;

	public:

		HumanB( std::string Name );
		~HumanB( void );
		void	setWeapon( Weapon& newWeapon );
		void	attack();

};

#endif // __HUMANB_H__