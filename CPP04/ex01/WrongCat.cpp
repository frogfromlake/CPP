/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:37:44 by nelix             #+#    #+#             */
/*   Updated: 2022/08/18 22:15:19 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

/* Constructors */
WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	this->_type = copy._type;
	std::cout << "WrongCat Copy Constructor called" << std::endl;
}

/* Deconstructors */
WrongCat::~WrongCat()
{
	std::cout << "WrongCat Deconstructor called" << std::endl;
}

/* Overloaded Operators */
WrongCat &WrongCat::operator=(const WrongCat &op)
{
	std::cout << "WrongCat Assignment operator called" << std::endl;
	if (this == &op)
		return *this;

	this->_type = op._type;
	return *this;
}

/* Public Methods */
void WrongCat::makeSound() const
{
	std::cout << "Wooff!" << std::endl;
}
