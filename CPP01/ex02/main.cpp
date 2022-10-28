/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:27:06 by fquist            #+#    #+#             */
/*   Updated: 2022/07/29 16:37:57 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

# define PURPLE std::cout << "\033[0;35m"
# define RED std::cout << "\033[0;31m"
# define RESET "\033[0m" << std::endl

int main( void ) {

	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	RED << &string << RESET;
	RED << stringPTR << RESET;
	RED << &stringREF << RESET;
	
	PURPLE << string << RESET;
	PURPLE << *stringPTR << RESET;
	PURPLE << stringREF << RESET;
	system("leaks ThisIsBrain");
	return (0);
}