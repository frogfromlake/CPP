/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:39:26 by fquist            #+#    #+#             */
/*   Updated: 2022/08/31 15:38:39 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors */
Fixed::Fixed()
{
	GREEN "Default constructor called" RESET;
	this->FixedStorage = 0;
}

Fixed::Fixed(Fixed &FixedCopy)
{
	GREEN "Copy constructor called" RESET;
	*this = FixedCopy;
}

/* Destructors */
Fixed::~Fixed()
{
	GREEN "Destructor called" RESET;
}

/* Overloaded Operators */
Fixed& Fixed::operator=(Fixed &FixedCopy)
{
	GREEN "Copy assignment operator called" RESET;
	if(this != &FixedCopy)
		this->FixedStorage = FixedCopy.FixedStorage;
	return (*this);
}

/* Public Methods */
int Fixed::getRawBits( void ) const {

	GREEN "getRawBits member function called" RESET;
	return (this->FixedStorage);
}

void Fixed::setRawBits(int const raw)
{
	GREEN "setRawBits member function called" RESET;
	this->FixedStorage = raw;
}