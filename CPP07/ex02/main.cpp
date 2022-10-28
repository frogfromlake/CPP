/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/31 16:17:19 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void CheckingIntArray()
{
	std::cout << "Creating INT Array" << std::endl;

	int size = 6;
	Array<int> array = Array<int>(size);
	
	std::cout << "\nPrinting empty Array using Operator Overload '<<':" << std::endl;
	std::cout << array;

	int index = 3;
	std::cout << "\nAssingning Value at valid index " << index << std::endl;
	try
	{
		array[index] = 127;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	index = 7;
	std::cout << "\nAssingning Value at invalid index " << index << std::endl;
	try
	{
		array[index] = 127;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nPrinting partially filled Array using Operator Overload '<<':" << std::endl;
	std::cout << array;

	return;
}

void CheckingStrArray()
{
	std::cout << "Creating STR Array" << std::endl;

	int size = 6;
	Array<std::string> array = Array<std::string>(size);

	std::cout << "\nPrinting empty Array using Operator Overload '<<':" << std::endl;
	std::cout << array;

	int index = 3;
	std::cout << "\nAssingning Value at valid index using Operator Overload '[]':" << index << std::endl;

	try
	{
		array[index] = "Keine Termine und leicht einen sitzen.";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	index = 7;
	std::cout << "\nAssingning String at invalid index using Operator Overload '[]':" << index << std::endl;
	try
	{
		array[index] = "Keine Termine und leicht einen sitzen.";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nPrinting partially filled Array using Operator Overload '<<':" << std::endl;
	std::cout << array;

	return;
}

struct TestStruct
{
	int i;
	float f;
	double d;
	std::string s;
};

// Operator Overload for printing TestStruct
std::ostream &operator<<(std::ostream &os, const TestStruct &test)
{
	os << "[" << test.i << ", " << test.f << ", " << test.d << ", " << test.s << "]";
	return os;
}

void CheckingStructArray()
{
	std::cout << "Creating Struct Array" << std::endl;

	int size = 6;
	Array<TestStruct> array = Array<TestStruct>(size);

	std::cout << "\nPrinting empty Struct Array using Operator Overload '<<':" << std::endl;
	std::cout << array;

	int index = 3;
	std::cout << "\nAssingning Struct at valid index using Operator Overload '[]':" << index << std::endl;
	
	TestStruct test;
	test.i = 1;
	test.f = 1.1f;
	test.d = 1.1;
	test.s = "Keine Termine und leicht einen sitzen.";
	try
	{
		array[index] = test;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	index = 7;
	std::cout << "\nAssingning Struct at invalid index using Operator Overload '[]':" << index << std::endl;
	try
	{
		array[index] = test;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nPrinting partially filled Array using Operator Overload '<<':" << std::endl;
	std::cout << array;

	return;
}


int main()
{
	std::cout << "\n--------~~** Checking Array Class Template **~~--------\n" << std::endl;

	std::cout << "-----------~* Checking Integer Array *~------------\n" << std::endl;
	CheckingIntArray();

	std::cout << "\n------------~* Checking String Array *~------------\n" << std::endl;
	CheckingStrArray();
	
	std::cout << "\n------------~* Checking Struct Array *~------------\n" << std::endl;
	CheckingStructArray();

	std::cout << std::endl;

	system("leaks Array");
	return 0;
}