/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:10:23 by fquist            #+#    #+#             */
/*   Updated: 2022/07/29 16:05:36 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *Horde;
	Horde = new Zombie[ N ];
	for (int i = 0; i < N; i++) {

		Horde[i].setName( name );
	}
	return (Horde);
}