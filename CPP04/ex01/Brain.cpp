/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/19 22:40:43 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

/* Constructors */
Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	for (size_t i = 0; i < this->_maxIdeas; i++)
	{
		this->_ideas[i] = copy._ideas[i];
	}
}

/* Deconstructors */
Brain::~Brain()
{
	std::cout << "Brain Deconstructor called" << std::endl;
}

/* Overloaded Operators */
Brain &Brain::operator=(const Brain &op)
{
	std::cout << "Brain Assignment operator called" << std::endl;
	if (this == &op)
		return *this;

	for (size_t i = 0; i < this->_maxIdeas; i++)
	{
		this->_ideas[i] = op._ideas[i];
	}
	return *this;
}

/* Public Methods */
void Brain::addIdea(std::string idea)
{
	static unsigned int index = 0;

	if (index >= _maxIdeas)
		return;

	this->_ideas[index] = idea;

	++index;
}

void Brain::removeIdea(std::string idea)
{
	for (unsigned int i = 0; i < _maxIdeas; ++i)
	{
		if (this->_ideas[i] == idea)
		{
			this->_ideas[i] = "";
			return;
		}
	}
}

/* Getter */
std::string Brain::getIdea(unsigned int index)
{
	if (index >= this->_maxIdeas)
		return "Error: Index is out of range.";

	return this->_ideas[index];
}

/* Setter */
