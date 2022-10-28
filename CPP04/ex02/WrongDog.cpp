/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:37:44 by nelix             #+#    #+#             */
/*   Updated: 2022/08/18 22:12:32 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

#include <iostream>

/* Constructors */
WrongDog::WrongDog() : WrongAnimal()
{
	this->_type = "WrongDog";
	std::cout << "WrongDog Default Constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& copy) : WrongAnimal(copy)
{
	this->_type = copy._type;
	std::cout << "WrongDog Copy Constructor called" << std::endl;
}

/* Deconstructors */
WrongDog::~WrongDog()
{
	std::cout << "WrongDog Deconstructor called" << std::endl;
}

/* Overloaded Operators */
WrongDog& WrongDog::operator=(const WrongDog &op)
{
	std::cout << "WrongDog Assignment operator called" << std::endl;
	if (this == &op)
		return *this;

	this->_type = op._type;
	return *this;
}

/* Public Methods */
void WrongDog::makeSound() const
{
	std::cout << "Meoww!" << std::endl;
}
