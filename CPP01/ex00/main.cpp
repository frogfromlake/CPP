/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:09:45 by fquist            #+#    #+#             */
/*   Updated: 2022/07/29 15:40:22 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
	
	randomChump( "Alice" );
	Zombie *bob = newZombie( "Bob" );
	bob->announce();
	delete bob;
	return (0);
}