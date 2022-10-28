/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/31 16:18:08 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>

int main(void)
{
	std::cout << "\n----------------~~* Checking easyfind() *~~-----------------" << std::endl;

	std::cout << "\n>> Creating and filling Vector\n" << std::endl;

	int to_find = 22;
	
	int content[] = {2, 7, 1, to_find, 2, 8, 2};
	int size = sizeof(content)/sizeof(content[0]);
	std::vector<int> vec (content, content + sizeof(content) / sizeof(int));

	std::cout << "Vector Data: (";
	for (int i = 0; i < size; i++)
	{
		std::cout << content[i];
		if (i + 1 != size)
			std::cout << ", ";
	}
	std::cout << ")" << std::endl;

	std::cout << "to_find = " << to_find << std::endl;
	try
	{
		std::cout << "Result : "	<< easyfind(vec, to_find) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	to_find = 64;
	std::cout << "to_find = " << to_find << std::endl;
	try
	{
		std::cout << "Result : "	<< easyfind(vec, to_find) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	system("leaks easyFind");
	return 0;
}