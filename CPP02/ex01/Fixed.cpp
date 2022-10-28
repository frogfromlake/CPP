/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:39:26 by fquist            #+#    #+#             */
/*   Updated: 2022/08/31 15:42:50 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/* Constructors */
Fixed::Fixed()
{
	GREEN "Default constructor called" RESET;
	this->_FixedStorage = 0;
}

Fixed::Fixed(const Fixed &FixedCopy)
{
	GREEN "Copy constructor called" RESET;
	*this = FixedCopy;
}

Fixed::Fixed(const int ToConvert)
{
	GREEN "Integer constructor is called" RESET;
	this->_FixedStorage = ToConvert << this->_FractionalBits;
}

Fixed::Fixed(const float ToConvert)
{
	GREEN "Float constructor is called" RESET;
	this->_FixedStorage = roundf(ToConvert * (1 << this->_FractionalBits));
}

/* Destructors */
Fixed::~Fixed()
{
	GREEN "Destructor called" RESET;
}

/* Overloaded Operators */
Fixed& Fixed::operator=(const Fixed &FixedCopy)
{
	GREEN "Copy assignment operator called" RESET;
	if(this != &FixedCopy)
		this->_FixedStorage = FixedCopy._FixedStorage;
	return (*this);
}

std::ostream& operator<<(std::ostream &Cout, const Fixed &Obj)
{
	Cout << "\033[1;32m" << Obj.toFloat() << "\033[0m";
	return (Cout);
}

/* Public Methods */
int Fixed::getRawBits( void ) const
{

	GREEN "getRawBits member function called" RESET;
	return (this->_FixedStorage);
}

void Fixed::setRawBits(int const raw)
{
	GREEN "setRawBits member function called" RESET;
	this->_FixedStorage = raw;
}

float Fixed::toFloat( void ) const
{
	float result;

	result = static_cast<float>(this->_FixedStorage / static_cast<float>(1 << this->_FractionalBits));
	return (result);
}

int Fixed::toInt(void) const
{
	int result;
	result = static_cast<int>(this->_FixedStorage >> this->_FractionalBits);
	return (result);
}
