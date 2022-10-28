/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:37:44 by nelix             #+#    #+#             */
/*   Updated: 2022/08/20 13:27:21 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

/* Constructors */
Cat::Cat()
{
	std::cout << "Cat Default Constructor called" << std::endl;
	this->_type = "Cat";
	this->_pBrain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->_type = copy._type;
	this->_pBrain = new Brain(*copy._pBrain);
}

/* Deconstructorss */
Cat::~Cat()
{
	std::cout << "Cat Deconstructor called" << std::endl;
	delete this->_pBrain;
}

/* Overloaded Operators */
Cat &Cat::operator=(const Cat &op)
{
	std::cout << "Cat Assignment operator called" << std::endl;
	if (this == &op)
		return *this;

	this->_type = op._type;
	this->_pBrain = new Brain(*op._pBrain);
	return *this;
}

/* Public Methods */
void Cat::makeSound() const
{
	std::cout << "Meoww!" << std::endl;
}

void Cat::gotIdea(std::string idea)
{
	this->_pBrain->addIdea(idea);
}

void Cat::forgotIdea(std::string idea)
{
	this->_pBrain->removeIdea(idea);
}

/* Getter */
std::string Cat::getType() const
{
	return this->_type;
}