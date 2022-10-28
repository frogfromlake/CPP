/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 18:11:34 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include <iostream>

/* Constructors */
Character::Character()
{
	this->_name = "undefined";

	for (size_t i = 0; i < _invSlots; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string &name)
{
	this->_name = name;
	
	for (size_t i = 0; i < _invSlots; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &copy)
{
	this->_name = copy._name;

	for (size_t i = 0; i < _invSlots; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];

		this->_inventory[i] = copy._inventory[i]->clone();
	}
}

/* Destructors */
Character::~Character()
{
	for (size_t i = 0; i < _invSlots; i++)
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
}

/* Overloaded Operators */
Character &Character::operator=(const Character &op)
{
	if (this == &op)
		return *this;

	this->_name = op._name;

	for (size_t i = 0; i < _invSlots; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];

		this->_inventory[i] = op._inventory[i]->clone();
	}

	return *this;
}

/* Public Methods */
void Character::equip(AMateria *m)
{
	if (m == NULL)
		return;

	for (size_t i = 0; i < _invSlots; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m->clone();
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "Error: Inventory slot is already empty." << std::endl;
		return;
	}

	AMateria *unequipped = this->_inventory[idx];
	this->_inventory[idx] = NULL;
	delete unequipped;
}

void Character::use(int idx, ICharacter &target)
{
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "Error: Inventory slot is empty." << std::endl;
		return;
	}

	this->_inventory[idx]->use(target);
}

/* Getter */
const std::string &Character::getName() const
{
	return this->_name;
}

/* Setter */
