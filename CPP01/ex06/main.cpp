/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:40:38 by fquist            #+#    #+#             */
/*   Updated: 2022/08/04 20:30:22 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

int main( void) {

	Harl scene;

	// scene.complain("DEBUG");
	// scene.complain("INFO");
	scene.complain("WARNING");
	// scene.complain("ERROR");

	// scene.complain("TEST");

	system("leaks harlFilter");
	return (0);
}