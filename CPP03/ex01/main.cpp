/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 09:17:51 by nelix             #+#    #+#             */
/*   Updated: 2022/08/31 15:53:05 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap Alice("Alice");
	ClapTrap Bob("Bob");
	ScavTrap Lou("Lou");

	std::cout << "\nDefault Tests:\n" << std::endl;
	Alice.attack("Bob");
	Bob.takeDamage(0);
	
	Bob.attack("Alice");
	Alice.takeDamage(0);

	Lou.attack("Bob");
	Bob.takeDamage(0);

	Alice.attack("Lou");
	Lou.takeDamage(0);

	Lou.guardGate();

	Bob.beRepaired(0);
	Alice.beRepaired(0);
	Lou.beRepaired(0);

	std::cout << "\nChecks complete!\n" << std::endl;
	system("leaks ScavTrap");
	return (0);
}