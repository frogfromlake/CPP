/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:01:27 by nelix             #+#    #+#             */
/*   Updated: 2022/08/26 00:36:23 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <algorithm>
#include <limits>

/* Constructors */
Span::Span() : _maxElements(0)
{
	this->_integers.reserve(this->_maxElements);
}

Span::Span(const Span &copy) : _maxElements(copy._maxElements), _integers(copy._integers) {};

Span::Span(unsigned int maxElements) : _maxElements(maxElements)
{
	this->_integers.reserve(this->_maxElements);
}

/* Destructors */
Span::~Span() {};

/* Overloaded Operators */
Span &Span::operator=(const Span &op)
{
	if (this == &op)
		return *this;

	if (this->_integers.size() > this->_maxElements)
		return *this;

	for (std::vector<int>::const_iterator iter = op._integers.begin(); iter != op._integers.end(); iter++)
	{
		this->_integers.push_back(*iter);
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Span& sp)
{
	int size = sp.getSize();
	for (int i = 0; i < size; i++)
	{
		if (i)
			os << " ";
		os << sp.getElement(i);
	}
	return (os);
}

/* Public Methods */
void Span::addNumber(int number)
{
	if (this->_integers.size() + 1 > this->_maxElements)
		throw OverflowException();

	this->_integers.push_back(number);
}

void Span::iterAddNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		this->addNumber(*begin);
		begin++;
	}
}

unsigned int Span::shortestSpan() const
{
	if (this->_integers.size() <= 1)
		throw InvalidOperationException();

	std::vector<int> copy(this->_integers);
	std::sort (copy.begin(), copy.end());

	int minSpan = std::numeric_limits<int>::max();
	
	for (std::vector<int>::iterator iter = copy.begin(); iter != copy.end() - 1; iter++)
		minSpan = std::min(minSpan, *(iter + 1) - *iter);
	
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (this->_integers.size() <= 1)
		throw InvalidOperationException();

	int maxElement = *std::max_element(this->_integers.begin(), this->_integers.end());
	int minElement = *std::min_element(this->_integers.begin(), this->_integers.end());
	return maxElement - minElement;
}

void Span::clear()
{
	this->_integers.clear();
}

/* Getter */
unsigned int Span::getSize() const
{
	return this->_integers.size();
}

int Span::getElement(unsigned int index) const
{
	if (index >= this->_maxElements)
		throw IndexOutOfBounds();

	return this->_integers[index];
}


/* Setter */

