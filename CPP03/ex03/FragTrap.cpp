/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:17:54 by nelix             #+#    #+#             */
/*   Updated: 2022/08/19 21:49:00 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

/* Constructors */
FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructs itself!" << std::endl;
}

FragTrap::FragTrap( std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructs itself!" << std::endl;
}

FragTrap::FragTrap( const FragTrap &copy ) : ClapTrap(copy)
{
	std::cout << "FragTrap " << this->_name << " constructs itself as a copy from " << copy._name << "!" << std::endl;
}

/* Deconstructorss */
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " deconstructs itself!" << std::endl;
}

/* Overloaded Operators */
FragTrap &FragTrap::operator=( const FragTrap &op )
{
	if (this == &op)
		return *this;

	this->_name = op._name;
	this->_hitPoints = op._hitPoints;
	this->_energyPoints = op._energyPoints;
	this->_attackDamage = op._attackDamage;
	return *this;
}

/* Public Methods */
void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}
