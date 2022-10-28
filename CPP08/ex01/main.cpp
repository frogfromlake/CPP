/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/31 16:18:43 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>

void ManualFunctionCallChecks()
{
	std::cout << "\n>>> Creating Vector with 5 elements preallocated" << std::endl;
	Span sp = Span(5);

	std::cout << "\n>>> Default Checks with 5 elements preallocated and 5 value assignements\n" << std::endl;
	try
	{
		sp.addNumber(6);
		sp.addNumber(7);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		std::cout << sp << "\n" << std::endl;
		std::cout << "-----------------" << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
		std::cout << "-----------------\n" << std::endl;
		sp.clear();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << ">>> Exception Check: Calling SpanChecks with 5 elements preallocated and 1 value assignement\n" << std::endl;
	try
	{
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n>>> Exception Check: Calling SpanChecks with 5 elements preallocated and 6 value assignements\n" << std::endl;
	try
	{
		sp.addNumber(7);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(41);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	sp.clear();
}

void IteratorFunctionCallChecks()
{
	std::cout << "\n>>> Default Checks with 20.000 elements preallocated and 20.000 value assignementsand via Iterator" << std::endl;

	unsigned int size = 20000;
	std::vector<int> content (size);
	
	for (size_t i = 0; i < size; i++)
		content[i] = i;

	std::cout << ">>> Filling Vector with Iterator [0 - 20.000] in sequence\n" << std::endl;
	try
	{
		Span sp = Span(size);
		sp.iterAddNumber(content.begin(), content.end());
		// std::cout << sp << std::endl;
		std::cout << "-----------------" << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	content.clear();
}

int main()
{
	ManualFunctionCallChecks();

	IteratorFunctionCallChecks();

	system("leaks Span");
	return 0;
}