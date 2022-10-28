/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:13:51 by nelix             #+#    #+#             */
/*   Updated: 2022/08/31 16:14:04 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Struct.hpp"

#include <iostream>
#include <stdint.h>

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data data;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Initial Data Struct:" << std::endl
			  << "struct Data" << std::endl
			  << "{" << std::endl
			  << "\tint i;" << std::endl
			  << "\tdouble d;" << std::endl
			  << "\tfloat f;\n" << std::endl
			  << "\tchar a;" << std::endl
			  << "\tstd::string s;\n" << std::endl
			  << "\tbool b;\n" << std::endl
			  << "\tvoid *p;" << std::endl
			  << "};" << std::endl;

	data.i = 42;
	data.d = 42.2;
	data.f = 24.24f;
	data.c = 'c';
	data.s = "String";
	data.b = true;
	data.p = &data.s;
	

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Filling Data Struct:" << std::endl
			  << "data.i = 42;" << std::endl
			  << "data.d = 42.2;" << std::endl
			  << "data.f = 24.24f;\n" << std::endl
			  << "data.c = 'c';" << std::endl
			  << "data.s = \"String\";" << std::endl
			  << "data.b = true;" << std::endl
			  << "data.p = &data.s;" << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Data Struct Members:" << std::endl
			  << "i\t" << data.i << std::endl
			  << "d\t" << data.d << std::endl
			  << "f\t" << data.f << std::endl
			  << "c\t" << data.c << std::endl
			  << "s\t" << data.s << std::endl
			  << "b\t" << data.b << std::endl
			  << "p\t" << data.p << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Serializing Data* data to uintptr_t raw" << std::endl
			  << std::endl
			  << "uintptr_t raw = serialize(&data);" << std::endl;

	uintptr_t raw = serialize(&data);
	
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Deserializing uintptr_t raw to Data* data" << std::endl
			  << std::endl
			  << "Data *deserialized = deserialize(raw);" << std::endl;

	Data *deserialized = deserialize(raw);

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "(Deserialized) Data Struct Members:" << std::endl
			  << "i\t" << deserialized->i << std::endl
			  << "d\t" << deserialized->d << std::endl
			  << "f\t" << deserialized->f << std::endl
			  << "c\t" << deserialized->c << std::endl
			  << "s\t" << deserialized->s << std::endl
			  << "b\t" << deserialized->b << std::endl
			  << "p\t" << deserialized->p << "\ncomp.:  " << data.p << std::endl
			  << "------------------------------------------" << std::endl;

	system("leaks serialize");
	return 0;
}