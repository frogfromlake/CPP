/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:53:34 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 18:08:32 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

/* Constructors */
AMateria::AMateria() : _type("undefined")
{

}

AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{

}

AMateria::AMateria(std::string const &type) : _type(type)
{

}

/* Deconstructors */
AMateria::~AMateria()
{

}

/* Overloaded Operators */
AMateria &AMateria::operator=(const AMateria &op)
{
	if (this == &op)
		return *this;

	this->_type = op._type;
	return *this;
}

/* Public Methods */
void AMateria::use(ICharacter &target)
{
	std::cout << target.getName() << std::endl;
}

/* Getter */
std::string const &AMateria::getType() const
{
	return this->_type;
}
