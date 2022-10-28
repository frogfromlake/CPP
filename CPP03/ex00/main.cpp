/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 09:17:51 by nelix             #+#    #+#             */
/*   Updated: 2022/08/31 15:52:16 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap Alice("Alice");
	ClapTrap Bob("Bob");

	std::cout << "\nDefault Tests:\n" << std::endl;
	Alice.attack("Bob");
	Bob.takeDamage(0);
	
	Bob.attack("Alice");
	Alice.takeDamage(0);

	Bob.beRepaired(0);
	Alice.beRepaired(0);

	std::cout << "\nChecking HitPoints:\n" << std::endl;
	Bob.takeDamage(11);
	Bob.beRepaired(11);

	std::cout << "\nChecking EnergyPoints:\n" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Bob.attack("Alice");
		Alice.beRepaired(0);
	}
	
	std::cout << "\nChecks complete!\n" << std::endl;
	system("leaks ClapTrap");
	return (0);
}