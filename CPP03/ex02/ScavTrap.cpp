/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:41:25 by nelix             #+#    #+#             */
/*   Updated: 2022/09/01 14:49:01 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

/* Constructors */
ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructs itself!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructs itself!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap " << this->_name << " constructs itself as a copy from " << copy._name << "!" << std::endl;
}

/* Deconstructors */
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " deconstructs itself!" << std::endl;
}

/* Overloaded Operators */
ScavTrap &ScavTrap::operator=(const ScavTrap &op)
{
	if (this == &op)
		return *this;

	this->_name = op._name;
	this->_hitPoints = op._hitPoints;
	this->_energyPoints = op._energyPoints;
	this->_attackDamage = op._attackDamage;
	return *this;
}

/* Public Members */
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in gatekeeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		if (this->_hitPoints <= 0)
			std::cout << "ScavTrap " << this->_name << ": insufficient hitpoints!" << std::endl;
		else if (this->_energyPoints <= 0)
			std::cout << "ScavTrap " << this->_name << ": insufficient energypoints!" << std::endl;
		return;
	}

	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}
