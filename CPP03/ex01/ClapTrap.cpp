/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 09:17:51 by nelix             #+#    #+#             */
/*   Updated: 2022/08/19 21:49:08 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/* Constructors */
ClapTrap::ClapTrap()
{
	this->_name = "undefined";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " constructs itself!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	std::cout << "ClapTrap " << this->_name << " constructs itself as a copy from " << copy._name << "!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " constructs itself!" << std::endl;
}

/* Deconstructorss */
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " deconstructs itself!" << std::endl;
}

/* Overloaded Operators */
ClapTrap &ClapTrap::operator=(const ClapTrap &op)
{
	std::cout << "ClapTrap " << this->_name << " assigns itself to " << op._name << "!" << std::endl;
	if (this == &op)
		return *this;

	this->_name = op._name;
	this->_hitPoints = op._hitPoints;
	this->_energyPoints = op._energyPoints;
	this->_attackDamage = op._attackDamage;
	return *this;
}

/* Public Methods */
void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		if (this->_hitPoints <= 0)
			std::cout << "ClapTrap " << this->_name << ": insufficient hitpoints!" << std::endl;
		else if (this->_energyPoints <= 0)
			std::cout << "ClapTrap " << this->_name << ": insufficient energypoints!" << std::endl;
		return;
	}

	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " just died!" << std::endl;
		return;
	}

	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		if (this->_hitPoints <= 0)
			std::cout << "ClapTrap " << this->_name << ": insufficient hitpoints!" << std::endl;
		else if (this->_energyPoints <= 0)
			std::cout << "ClapTrap " << this->_name << ": insufficient energypoints!" << std::endl;
		return;
	}

	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " repairs itself, gaining " << amount << " hit points!" << std::endl;
}
