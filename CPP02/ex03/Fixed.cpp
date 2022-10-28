/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:39:26 by fquist            #+#    #+#             */
/*   Updated: 2022/08/06 21:34:59 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->_FixedStorage = 0;
}

Fixed::Fixed(const int ToConvert) {
	// LGREEN "Convert x and y" RESET;
	this->_FixedStorage = ToConvert << this->_FractionalBits;
}

Fixed::Fixed(const float ToConvert) {

	this->_FixedStorage = roundf(ToConvert * (1 << this->_FractionalBits));
}

//copying values of one class in to another
Fixed::Fixed(const Fixed &FixedCopy) {

	*this = FixedCopy;
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed &FixedCopy) {

	if(this != &FixedCopy)
		this->_FixedStorage = FixedCopy._FixedStorage;
	return (*this);
}

bool Fixed::operator>(const Fixed &FixedCopy) {

	return (this->_FixedStorage > FixedCopy._FixedStorage);
}

bool Fixed::operator<(const Fixed &FixedCopy) {

	return (this->_FixedStorage < FixedCopy._FixedStorage);
}

bool Fixed::operator>=(const Fixed &FixedCopy) {

	return (this->_FixedStorage >= FixedCopy._FixedStorage);
}

bool Fixed::operator<=(const Fixed &FixedCopy) {

	return (this->_FixedStorage <= FixedCopy._FixedStorage);
}

bool Fixed::operator==(const Fixed &FixedCopy) {

	return (this->_FixedStorage == FixedCopy._FixedStorage);
}

bool Fixed::operator!=(const Fixed &FixedCopy) {

	return (this->_FixedStorage != FixedCopy._FixedStorage);
}

Fixed Fixed::operator+(const Fixed &FixedCopy) {

	int res = this->_FixedStorage + FixedCopy._FixedStorage;
	Fixed tmp;
	tmp.setRawBits(res);
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &FixedCopy) {

	int res = this->_FixedStorage - FixedCopy._FixedStorage;
	Fixed tmp;
	tmp.setRawBits(res);
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &FixedCopy) {

	Fixed tmp;

	int res = this->_FixedStorage * FixedCopy._FixedStorage / ( 1 << this->_FractionalBits);
	tmp.setRawBits(res);
	return(tmp);
}

Fixed Fixed::operator/(const Fixed &FixedCopy) {

	Fixed tmp;

	int res = this->_FixedStorage / FixedCopy._FixedStorage * ( 1 << this->_FractionalBits);
	tmp.setRawBits(res);
	return(tmp);
}

// pre increment
Fixed Fixed::operator++() {

	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

// post increment
Fixed Fixed::operator++(int) {

	Fixed tmp(*this);
	
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

// pre decrement
Fixed Fixed::operator--() {

	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

// post decrement
Fixed Fixed::operator--(int) {

	Fixed tmp(*this);
	
	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}

Fixed& Fixed::min(Fixed &FpnOne, Fixed &FpnTwo) {

	if (FpnOne < FpnTwo)
		return (FpnOne);
	else
		return (FpnTwo);
}

const Fixed& Fixed::min(const Fixed &FpnOne, const Fixed &FpnTwo) {

	if (static_cast<Fixed>(FpnOne) < static_cast<Fixed>(FpnTwo))
		return (FpnOne);
	else
		return (FpnTwo);
}

Fixed& Fixed::max(Fixed &FpnOne, Fixed &FpnTwo) {

	if (FpnOne > FpnTwo)
		return (FpnOne);
	else
		return (FpnTwo);
}

const Fixed& Fixed::max(const Fixed &FpnOne, const Fixed &FpnTwo) {

	if (static_cast<Fixed>(FpnOne) > static_cast<Fixed>(FpnTwo))
		return (FpnOne);
	else
		return (FpnTwo);
}

int Fixed::getRawBits( void ) const {

	return (this->_FixedStorage);
}

void Fixed::setRawBits(int const raw) {

	this->_FixedStorage = raw;
}

float Fixed::toFloat( void ) const {

	float result;

	result = static_cast<float>(this->_FixedStorage / static_cast<float>(1 << this->_FractionalBits));
	return (result);
}

int Fixed::toInt(void) const {

	int result;
	result = static_cast<int>(this->_FixedStorage >> this->_FractionalBits);
	return (result);
}

std::ostream& operator<<(std::ostream &Cout, const Fixed &Obj) {
	Cout << "\033[1;32m" << Obj.toFloat() << "\033[0m";
	return (Cout);
}