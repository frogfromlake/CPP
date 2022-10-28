/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/24 15:59:10 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___ARRAY_HPP___)
#define ___ARRAY_HPP___

#include <string>
#include <iostream>
#include <exception>


template<typename T>
class Array
{
	private:
		/* private Members */
		int _size;
		T *_array;

	public:
		/* Constructors */
		Array()
		{
			this->_size = 0;
			this->_array = new T(this->_size);
		}

		Array(const Array &copy)
		{
			this->_size = copy.size();
			this->_array = new T[this->_size];

			for (int i = 0; i < this->_size; i++)
				this->_array[i] = copy[i];
		}

		Array(unsigned int n)
		{
			static T _default;

			this->_size = n;
			this->_array = new T[this->_size];
			for (int i = 0; i < this->_size; i++)
				this->_array[i] = _default;
		}

		/* Destructors */
		~Array()
		{
			delete [] this->_array;
		}

		/* Overloaded Operators */
		Array &operator=(const Array &op)
		{
			if (*this == op)
				return *this;

			delete [] this->_array;

			int opSize = op.size();
			this->_array = new T[opSize];

			for (int i = 0; i < opSize; i++)
				this->_array[i] = op[i];

			return *this;
		}

		T &operator[](int index)
		{
			if (index >= this->_size || index < 0)
				throw IndexOutOfBoundsException();

			return this->_array[index];
		}

		const T &operator[](int index) const
		{
			if (index >= this->_size || index < 0)
				throw IndexOutOfBoundsException();
		
			return this->_array[index];
		}

		/* Public Methods */
		int size() const
		{
			return (this->_size);
		}

		/* Getter */
		
		/* Setter */

		/* Exceptions */
		struct IndexOutOfBoundsException : public std::exception
		{
			const char *what() const throw()
			{
				return "IndexOutOfBoundException";
			}
		};
};

template<typename T>
std::ostream &operator<<(std::ostream &os, Array<T> const &array)
{
	os << "Array(";
	for (int i = 0; i < array.size(); i++)
	{
		os << array[i];
		if (i + 1 != array.size())
			os << ", ";
	}
	os << ")" << std::endl;

	return os;
}

#endif // ___ARRAY_HPP___