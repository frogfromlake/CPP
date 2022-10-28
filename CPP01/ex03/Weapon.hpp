/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:41:37 by fquist            #+#    #+#             */
/*   Updated: 2022/07/29 17:38:02 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>
#include <iostream>

# define PURPLE std::cout << "\033[0;35m"
# define RED std::cout << "\033[0;31m"
# define RESET "\033[0m" << std::endl

class Weapon {

	private:

		std::string type;

	public:

		Weapon( std::string Type);
		~Weapon();
		const std::string& getType( void );
		void		setType( std::string type );
};

#endif // __WEAPON_H__