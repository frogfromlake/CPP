/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:38:55 by fquist            #+#    #+#             */
/*   Updated: 2022/08/31 16:23:04 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {

	Point a(3, 1);
	Point b(7, 2);
	Point c(5, 4);
	Point pInside(5, 2);
	Point pOutside(3, 5);
	
	if (bsp(a, b, c, pInside))
	// if (bsp(a, b, c, pOutside))
		GREEN "Point is inside the triangle" RESET;
	else
		RED "Point is outside the triangle" RESET;

	system("leaks a.out");
	return 0;
}
