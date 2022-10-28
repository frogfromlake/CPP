/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:09:45 by fquist            #+#    #+#             */
/*   Updated: 2022/07/29 16:14:46 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
	
	Zombie *ZombieHorde;
	
	ZombieHorde = zombieHorde( 42, "Mo");
	for (int i = 0; i < 42; i++) {

		PURPLE << ZombieHorde[i].getName() << RESET;
	}
	delete [] ZombieHorde;
	system("leaks ZombieHorde");
	return (0);
}
