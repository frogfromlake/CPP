/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:37:44 by nelix             #+#    #+#             */
/*   Updated: 2022/08/19 21:49:33 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

/* Constructors */
Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	this->_type = copy._type;
	std::cout << "Cat Copy Constructor called" << std::endl;
}

/* Deconstructorss */
Cat::~Cat()
{
	std::cout << "Cat Deconstructor called" << std::endl;
}

/* Overloaded Operators */
Cat &Cat::operator=(const Cat &op)
{
	std::cout << "Cat Assignment operator called" << std::endl;
	if (this == &op)
		return *this;

	this->_type = op._type;
	return *this;
}

/* Public Methods */
void Cat::makeSound() const
{
	std::cout << "Meoww!" << std::endl;
}
