/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:39:18 by fquist            #+#    #+#             */
/*   Updated: 2022/08/31 15:37:35 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

#include <string>
#include <iostream>
#include <fstream>

# define GREEN std::cout << "\033[1;32m"
# define LGREEN std::cout << "\033[0;32m"
# define RED std::cout << "\033[0;31m"
# define YELLOW std::cout << "\033[0;33m"
# define RESET "\033[0m" << std::endl

class Fixed
{
	private:
		/* private Members */
		int FixedStorage;
		static const int FractionalBits = 8;

	public:
		/* Constructors */
		Fixed();
		Fixed( Fixed &FixedCopy);
		/* Destructors */
		~Fixed();

		/* Overloaded Operators */
		Fixed& operator=(Fixed &FixedCopy);

		/* Public Methods */
		int getRawBits( void ) const;
		void setRawBits( int const raw );

};

#endif // __FIXED_H__
