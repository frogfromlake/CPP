/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 09:17:51 by nelix             #+#    #+#             */
/*   Updated: 2022/08/31 15:54:33 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void )
{
	ClapTrap Alice("Alice");
	ClapTrap Bob("Bob");
	ScavTrap Lou("Lou");
	FragTrap Emil("Emil");
	DiamondTrap	Ghost("Ghost");

	std::cout << "\nDefault Tests:\n" << std::endl;

	Alice.attack("Bob");
	Bob.takeDamage(0);
	
	Bob.attack("Alice");
	Alice.takeDamage(0);

	Lou.attack("Bob");
	Bob.takeDamage(20);

	Bob.beRepaired(30);

	Alice.attack("Lou");
	Lou.takeDamage(0);

	Alice.attack("Emil");
	Emil.takeDamage(0);
	
	Ghost.attack("Emil");
	Emil.takeDamage(30);
	
	Lou.guardGate();
	Emil.highFivesGuys();
	Ghost.whoAmI();
	
	Bob.beRepaired(0);
	Alice.beRepaired(0);
	Lou.beRepaired(0);
	Emil.beRepaired(0);
	Ghost.beRepaired(0);

	std::cout << "\nChecks complete!\n" << std::endl;
	system("leaks DiamondTrap");

	return (0);
}