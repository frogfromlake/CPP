/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:11:33 by fquist            #+#    #+#             */
/*   Updated: 2022/07/29 16:54:40 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <string>

# define PURPLE std::cout << "\033[0;35m"
# define RESET "\033[0m" << std::endl

class Zombie {
	
	private:
	
		std::string name;

	public:

		Zombie();
		Zombie( std::string name );
		~Zombie( void );
		void setName( std::string name );
		std::string getName( void );
		void announce( void );
	
};

Zombie* zombieHorde( int N, std::string name );

#endif