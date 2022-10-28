/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:42:59 by nelix             #+#    #+#             */
/*   Updated: 2022/08/18 23:31:35 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

/* Constructors */
WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
	this->_type = "Amazon";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	this->_type = copy._type;
}

/* Deconstructors */
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Deconstructor called" << std::endl;
}

/* Overloaded Operators */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &op)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this == &op)
		return *this;

	this->_type = op._type;
	return *this;
}

/* Public Methods */
void WrongAnimal::makeSound() const
{
	std::cout << "I am stupid! - Jeff Bezos" << std::endl;
}

/* Getter */
std::string WrongAnimal::getType() const
{
	return this->_type;
}
