/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:24:20 by nelix             #+#    #+#             */
/*   Updated: 2022/08/19 21:49:00 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

/* Constructors */
DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	this->_name = "undefined";
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " constructs itself!" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &copy ) : ClapTrap(), FragTrap(copy), ScavTrap(copy)
{
	std::cout << "DiamondTrap " << this->_name << " constructs itself as a copy from " << copy._name << "!" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " constructs itself!" << std::endl;
}

/* Deconstructorss */
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " deconstructs itself!" << std::endl;
}

/* Overloaded Operators */
DiamondTrap &DiamondTrap::operator=( const DiamondTrap &op )
{
	if (this == &op)
		return *this;

	this->_name = op._name;
	this->ClapTrap::_name = op.ClapTrap::_name;
	this->_hitPoints = op._hitPoints;
	this->_energyPoints = op._energyPoints;
	this->_attackDamage = op._attackDamage;
	return *this;
}

/* Public Methods */
void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap is experiencing an existential crisis" << std::endl;
	std::cout << "DiamondTrap " << this->_name << " asks itself: Who Am I??" << std::endl;
	std::cout << "Voice from the Void: You are son of ClapTrap " << this->ClapTrap::_name << std::endl;
}
