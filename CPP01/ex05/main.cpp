/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:40:38 by fquist            #+#    #+#             */
/*   Updated: 2022/08/04 20:12:43 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void) {

	Harl scene;

	scene.complain("DEBUG");
	scene.complain("INFO");
	scene.complain("WARNING");
	scene.complain("ERROR");

	scene.complain("TEST");

	system("leaks Harl");
	return (0);
}