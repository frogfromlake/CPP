/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:42:59 by nelix             #+#    #+#             */
/*   Updated: 2022/08/19 21:49:33 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

/* Constructors */
Animal::Animal()
{
	std::cout << "Animal Default Constructor called" << std::endl;
	this->_type = "Meta";
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	this->_type = copy._type;
}

/* Deconstructorss */
Animal::~Animal()
{
	std::cout << "Animal Deconstructor called" << std::endl;
}

/* Overloaded Operators */
Animal& Animal::operator=(const Animal &op)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this == &op)
		return *this;

	this->_type = op._type;
	return *this;
}

/* Public Methods */
void Animal::makeSound() const
{
	std::cout << "I am stupid! - Mark Zuckerberg" << std::endl;
}

/* Getter */
std::string Animal::getType() const
{
	return this->_type;
}
