/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:37:44 by nelix             #+#    #+#             */
/*   Updated: 2022/08/19 21:49:33 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

/* Constructors */
Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	this->_type = copy._type;
	std::cout << "Dog Copy Constructor called" << std::endl;
}

/* Deconstructorss */
Dog::~Dog()
{
	std::cout << "Dog Deconstructor called" << std::endl;
}

/* Overloaded Operators */
Dog& Dog::operator=(const Dog &op)
{
	std::cout << "Dog Assignment operator called" << std::endl;
	if (this == &op)
		return *this;

	this->_type = op._type;
	return *this;
}

/* Public Methods */
void Dog::makeSound() const
{
	std::cout << "Wooff!" << std::endl;
}
