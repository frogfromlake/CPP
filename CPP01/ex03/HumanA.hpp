/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:53:21 by fquist            #+#    #+#             */
/*   Updated: 2022/07/29 17:51:40 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_H__
#define __HUMANA_H__

#include <iostream>
#include <string>
#include "Weapon.hpp"

# define PURPLE std::cout << "\033[0;35m"
# define RED std::cout << "\033[0;31m"
# define RESET "\033[0m" << std::endl

class HumanA {

	private:

		std::string _Name;
		Weapon &_Club;

	public:

		HumanA( const std::string &Name, Weapon& Club );
		~HumanA();
		void	attack();

};

#endif // __HUMANA_H__