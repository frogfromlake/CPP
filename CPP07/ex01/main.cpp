/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/31 16:16:38 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void TestIntArr()
{
	std::cout << "~~ Checking Int Array ~~" << std::endl;

	int arr[] = {1, 76, 38, 66, 4, 999999};
	iter(arr, 6, &printElement);
}

void TestFloatArr()
{
	std::cout << "~~ Checking Float Array ~~" << std::endl;

	float arr[] = {1.0f, 76.2f, 38.35f, 66.2934f, 4.4f, 999999.999f};
	iter(arr, 6, &printElement);
}

void TestStrArr()
{
	std::cout << "~~ Checking Str Array ~~" << std::endl;

	std::string arr[] = {"Keine Termine", "und leicht", "einen sitzen.", ";-)"};
	iter(arr, 4, &printElement);
}

int	main()
{
	TestIntArr();
	TestFloatArr();
	TestStrArr();

	system("leaks iter");
	return 0;
}