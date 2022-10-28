/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/23 13:25:25 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___CONVERTER_HPP___)
#define ___CONVERTER_HPP___

#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

enum literalTypes
{
	charType,
	intType,
	doubleType,
	floatType,
	noType
};

class Converter
{
	private:
		/* private Members */
		std::string		_arg;
		literalTypes	_type;

		char	_charData;
		int		_intData;
		float	_floatData;
		double	_doubleData;

		bool error;

		/* private Methods */
		void determineType();
		void convertStringToType();
		bool isPseudoLiteral() const;

	public:
		/* Constructors */
		Converter();
		Converter(std::string arg);
		Converter(const Converter &copy);
		/* Destructors */
		~Converter();

		/* Overloaded Operators */
		Converter &operator=(const Converter &op);

		/* Public Methods */
		void convert();
		void printResult() const;

		/* Getter */

		/* Setter */
};

#endif // ___CONVERTER_HPP___