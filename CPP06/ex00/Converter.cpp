/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/08/23 20:41:52 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/* Constructors */
Converter::Converter()
{
	this->_arg = "undefined";
}

Converter::Converter(std::string arg)
{
	this->_arg = arg;
}

Converter::Converter(const Converter &copy)
{
	this->_arg = copy._arg;
}

/* Destructors */
Converter::~Converter() {}

/* Overloaded Operators */
Converter &Converter::operator=(const Converter &op)
{
	if (this == &op)
		return *this;

	this->_arg = op._arg;
	return *this;
}

/* Private Methods */
void Converter::determineType()
{
	std::stringstream(this->_arg);
	
	this->_type = noType;
	this->error = false;

	// Determine CharType
	if (this->_arg.length() == 3 && this->_arg[0] == '\'' && this->_arg[2] == '\'')
	{
		this->_type = charType;
		return;
	}

	// Determine Pseudo FloatType
	if (this->_arg.compare("-inff") == 0 || this->_arg.compare("+inff") == 0 || this->_arg.compare("nanf") == 0)
	{
		this->_type = floatType;
		return;
	}

	// Determine Pseudo DoubleType
	if (this->_arg.compare("-inf") == 0 || this->_arg.compare("+inf") == 0 || this->_arg.compare("nan") == 0)
	{
		this->_type = doubleType;
		return;
	}

	// Determine FloatTypes/DoubleTypes
	if (this->_arg.find('.') != std::string::npos)
	{
		this->_type = doubleType;

		// Determine FloatTypes
		if (this->_arg.find('f'))
		{
			this->_type = floatType;
			return;
		}
		return;
	}
	
	// Determine IntTypes
	for (size_t i = 0; i < this->_arg.length(); i++)
	{
		literalTypes lastType = this->_type;
		if (isdigit(this->_arg[i]))
			this->_type = intType;
		else
			this->_type = lastType;
	}

	if (this->_type == noType)
	{
		std::cout << "Error: Type: could not be determined." << std::endl;
		std::cout << "For char conversions type e.g. <\"\'a\'\"> without brackets." << std::endl;
		this->error = true;
	}
}

void Converter::convertStringToType()
{
	switch (this->_type)
	{
		case charType:
			this->_charData = this->_arg[1];

			this->_intData = static_cast<int>(this->_charData);
			this->_doubleData = static_cast<double>(this->_charData);
			this->_floatData = static_cast<float>(this->_charData);
			return;

		case intType:
			this->_intData = atoi(this->_arg.c_str());

			this->_charData = static_cast<char>(this->_intData);
			this->_doubleData = static_cast<double>(this->_intData);
			this->_floatData = static_cast<float>(this->_intData);
			return;

		case doubleType:
			this->_doubleData = atof(this->_arg.c_str());

			this->_charData = static_cast<char>(this->_doubleData);
			this->_intData = static_cast<int>(this->_doubleData);
			this->_floatData = static_cast<float>(this->_doubleData);
			return;

		case floatType:
			this->_floatData = atof(this->_arg.c_str());

			this->_charData = static_cast<char>(this->_floatData);
			this->_intData = static_cast<int>(this->_floatData);
			this->_doubleData = static_cast<double>(this->_floatData);
			return;

		case noType:
			return;
	}
}

bool Converter::isPseudoLiteral() const
{
	if (this->_type != doubleType && this->_type != floatType)
		return false;

	if (std::isnan(this->_doubleData) || std::isnan(this->_floatData))
		return true;
	
	if (std::isinf(this->_doubleData) || std::isinf(this->_floatData))
		return true;

	return false;
}

/* Public Methods */
void Converter::convert()
{
	this->determineType();
	if (this->error == true)
		return;
	this->convertStringToType();
	this->printResult();
}

void Converter::printResult() const
{
	// Print Char Conversion
	std::cout << "Char: ";

	if (this->isPseudoLiteral())
		std::cout << "impossible";
	else if (!std::isprint(this->_charData))
		std::cout << "Non displayable";
	else
		std::cout << "'" << this->_charData << "'";
	std::cout << std::endl;

	// Print Int Conversion
	std::cout << "Int: ";

	if (this->isPseudoLiteral())
		std::cout << "impossible";
	else
		std::cout << this->_intData;
	std::cout << std::endl;

	// Print Double Conversion
	std::cout << "Double: "
			  << std::fixed << this->_doubleData << std::endl;

	// Print Float Conversion
	std::cout << "Float: "
			  << std::fixed << this->_floatData << "f" << std::endl;
}

/* Getter */

/* Setter */