/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:47:59 by nelix             #+#    #+#             */
/*   Updated: 2022/08/31 16:13:15 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <cstring>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: arguments: Invalid amount of arguments." << std::endl;
		return EXIT_FAILURE;
	}

	std::string arg = argv[1];

	Converter conv(arg);

	conv.convert();
	conv.printResult();

	system("leaks convert");
	return EXIT_SUCCESS;
}