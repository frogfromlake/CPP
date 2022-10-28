/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:49:02 by nelix             #+#    #+#             */
/*   Updated: 2022/08/31 16:15:03 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "ABC.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	std::srand(time(NULL));

	switch(std::rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	std::string type = "undefined";

	if (dynamic_cast<A *>(p) != NULL)
		type = "A";
	else if (dynamic_cast<B *>(p) != NULL)
		type = "B";
	else if (dynamic_cast<C *>(p) != NULL)
		type = "C";

	std::cout << "Identified by pointer: Class "
			  << type << " was created" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A a;
		a = dynamic_cast<A&>(p);
		std::cout << "Identified by reference: Class A was created" << std::endl;
	} catch (const std::exception& e) {	}

	try
	{
		B b;
		b = dynamic_cast<B&>(p);
		std::cout << "Identified by reference: Class B was created" << std::endl;
	} catch (const std::exception& e) {	}

	try
	{
		C c;
		c = dynamic_cast<C&>(p);
		std::cout << "Identified by reference: Class C was created" << std::endl;
	} catch (const std::exception& e) {	}
}

int main()
{
	Base* p = generate();

	identify(p);
	identify(*p);

	delete p;

	system("leaks identify");
	return (0);
}
