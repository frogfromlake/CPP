/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 18:03:43 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#include <iostream>

/* Constructors */
MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < _invSlots; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (size_t i = 0; i < _invSlots; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];

		this->_inventory[i] = copy._inventory[i]->clone();
	}
}
/* Destructors */
MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < _invSlots; i++)
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
}

/* Overloaded Operators */
MateriaSource &MateriaSource::operator=(const MateriaSource &op)
{
	if (this == &op)
		return *this;

	for (size_t i = 0; i < _invSlots; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];

		this->_inventory[i] = op._inventory[i]->clone();
	}

	return *this;
}


/* Public Methods */
void MateriaSource::learnMateria(AMateria *m)
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

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < _invSlots; i++)
	{
		if (this->_inventory[i] != NULL)
			if (this->_inventory[i]->getType() == type)
				return this->_inventory[i]->clone();
	}
	return NULL;
	
}

/* Getter */

/* Setter */