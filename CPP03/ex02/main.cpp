/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 09:17:51 by nelix             #+#    #+#             */
/*   Updated: 2022/08/31 15:53:40 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	ClapTrap Alice("Alice");
	ClapTrap Bob("Bob");
	ScavTrap Lou("Lou");
	FragTrap Emil("Emil");

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
	
	Lou.guardGate();
	Emil.highFivesGuys();
	
	Bob.beRepaired(0);
	Alice.beRepaired(0);
	Lou.beRepaired(0);
	Emil.beRepaired(0);

	std::cout << "\nChecks complete!\n" << std::endl;
	system("leaks FragTrap");
	return (0);
}