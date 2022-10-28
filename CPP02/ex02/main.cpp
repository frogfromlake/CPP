/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:38:55 by fquist            #+#    #+#             */
/*   Updated: 2022/08/31 16:22:29 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

	int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "Incrementing\n" << std::endl;
	std::cout << "Init value: " << a << std::endl;
	std::cout << "Pre increment: " << ++a << std::endl;
	std::cout << "Pre post increment: " << a << std::endl;
	std::cout << "post increment: " << a++ << std::endl;
	std::cout << "post increment value: " << a << std::endl;
	
	std::cout << "Decrementing\n" << std::endl;
	std::cout << "Init value: " << a << std::endl;
	std::cout << "Pre decrement: " << --a << std::endl;
	std::cout << "Pre post decrement: " << a << std::endl;
	std::cout << "post decrement: " << a-- << std::endl;
	std::cout << "post decrement value: " << a << std::endl;
	
	std::cout << "Binary operators\n" << std::endl;
	std::cout << "Init value a: " << a << std::endl;
	std::cout << "Init value b: " << b << std::endl;
	std::cout << "Multiplying: " << a * b << std::endl;
	std::cout << "Dividing: " << a / b << std::endl;
	std::cout << "Adding: " << a + b << std::endl;
	std::cout << "Substracting: " << a - b << std::endl;
	
	std::cout << "Comparisons\n" << std::endl;
	std::cout << "Is equal: " << (a == b) << std::endl;
	std::cout << "Is unequal: " << (a != b) << std::endl;
	std::cout << "a smaller b: " << (a < b) << std::endl;
	std::cout << "a bigger b: " << (a > b) << std::endl;
	std::cout << "a smaller/equal b: " << (a <= b) << std::endl;
	std::cout << "a bigger/equal b: " << (a >= b) << std::endl;

	std::cout << "Min / Max\n" << std::endl;
	std::cout << "Min of a b is: " << Fixed::min( a, b ) << std::endl;
	std::cout << "Max of a b is: " << Fixed::max( a, b ) << std::endl;

	system("leaks a.out");
	return 0;
}
