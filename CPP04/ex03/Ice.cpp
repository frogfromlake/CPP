/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 17:37:07 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

#include <iostream>

/* Constructors */
Ice::Ice()
{
	this->_type = "ice";
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{

}

Ice::Ice(const std::string &type)
{
	this->_type = type;
}

/* Destructors */
Ice::~Ice()
{

}

/* Overloaded Operators */
Ice& Ice::operator=(const Ice &op)
{
	if (this == &op)
		return *this;

	this->_type = op._type;
	return *this;
}

/* Public Methods */
AMateria *Ice::clone() const
{
	Ice *cloned = new Ice(this->_type);
	return cloned;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/* Getter */
const std::string &Ice::getType() const
{
	return this->_type;
}

/* Setter */