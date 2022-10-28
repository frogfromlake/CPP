/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 17:35:39 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

#include <iostream>

/* Constructors */
Cure::Cure()
{
	this->_type = "cure";
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{

}

Cure::Cure(const std::string &type)
{
	this->_type = type;
}

/* Destructors */
Cure::~Cure()
{

}

/* Overloaded Operators */
Cure &Cure::operator=(const Cure &op)
{
	if (this == &op)
		return *this;

	this->_type = op._type;
	return *this;
}

/* Public Methods */
AMateria *Cure::clone() const
{
	Cure *cloned = new Cure(this->_type);
	return cloned;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

/* Getter */
const std::string &Cure::getType() const
{
	return this->_type;
}

/* Setter */
