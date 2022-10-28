/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:25:43 by fquist            #+#    #+#             */
/*   Updated: 2022/08/06 21:40:13 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_H__
#define __POINT_H__

#include <string>
#include <iostream>
#include <fstream>
#include <math.h>
#include "Fixed.hpp"

# define GREEN std::cout << "\033[1;32m"
# define LGREEN std::cout << "\033[0;32m"
# define RED std::cout << "\033[0;31m"
# define YELLOW std::cout << "\033[0;33m"
# define RESET "\033[0m" << std::endl

class Point {

	private:

		const Fixed _x;
		const Fixed _y;

	public:
	
		Point();
		Point( const float initX, const float initY );
		Point( const Point &Copy );
		Point& operator=(const Point &Copy);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
};

Fixed	sign(Point p1, Point p2, Point p3);
bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif // __POINT_H__