/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:37:44 by nelix             #+#    #+#             */
/*   Updated: 2022/08/19 23:11:58 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

/* Constructors */
Dog::Dog() : Animal()
{
	std::cout << "Dog Default Constructor called" << std::endl;
	this->_type = "Dog";
	this->_pBrain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->_type = copy._type;
	this->_pBrain = new Brain(*copy._pBrain);
}

/* Deconstructorss */
Dog::~Dog()
{
	std::cout << "Dog Deconstructor called" << std::endl;
	delete this->_pBrain;
}

/* Overloaded Operators */
Dog& Dog::operator=(const Dog &op)
{
	std::cout << "Dog Assignment operator called" << std::endl;
	if (this == &op)
		return *this;	

	this->_type = op._type;
	this->_pBrain = new Brain(*op._pBrain);
	return *this;
}

/* Public Methods */
void Dog::makeSound() const
{
	std::cout << "Wooff!" << std::endl;
}

void Dog::gotIdea(std::string idea)
{
	this->_pBrain->addIdea(idea);
}

void Dog::forgotIdea(std::string idea)
{
	this->_pBrain->removeIdea(idea);
}
