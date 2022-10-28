/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:39:18 by fquist            #+#    #+#             */
/*   Updated: 2022/08/31 15:40:04 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

#include <string>
#include <iostream>
#include <fstream>
#include <math.h>

# define GREEN std::cout << "\033[1;32m"
# define LGREEN std::cout << "\033[0;32m"
# define RED std::cout << "\033[0;31m"
# define YELLOW std::cout << "\033[0;33m"
# define RESET "\033[0m" << std::endl

class Fixed
{
	private:
		/* private Members */
		int _FixedStorage;
		static const int _FractionalBits = 8;

	public:
		/* Constructors */
		Fixed();
		Fixed( const int ToConvert );
		Fixed( const float ToConvert );
		Fixed( const Fixed &FixedCopy);
		/* Destructors */
		~Fixed();

		/* Overloaded Operators */
		Fixed& operator=(const Fixed &FixedCopy);

		/* Public Methods */
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

};

std::ostream& operator<<(std::ostream &Cout, const Fixed &Obj);

#endif // __FIXED_H__
